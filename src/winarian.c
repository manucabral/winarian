#include "winarian.h"
#include "color.h"

void AjustarVentana(void)
{
    SMALL_RECT Tam = {0, 0, 70, 30};
    HANDLE ManipuladorSalida;
    ManipuladorSalida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(ManipuladorSalida, TRUE, &Tam);
    return;
}

void EstablecerTituloConsola(void)
{
    char Titulo[_MAX_TITLE];
    snprintf(Titulo, sizeof Titulo, "%s v%s", NOMBRE, VERSION);
    SetConsoleTitleA(Titulo);
    return;
}

void MostrarSubtitulo(void)
{
    CambiarColorConsola(CYAN);
    printf("\n\t\t\t%s v%s\n", NOMBRE, VERSION);
    CambiarColorConsola(GRIS);
    printf("\tConfiguraciones y utilidades de registro para Windows\n");
    CambiarColorConsola(GRIS_FUERTE);
    printf("\t\t\tCreado por %s\n\n", AUTOR);
}

char *InterpretarValor(int valor)
{
    return valor ? "Activado" : "Desactivado";
}

int InterpretarColor(int valor)
{
    return valor ? VERDE : ROJO;
}

void MostrarMenu(Lista *ListaRegistro)
{
    CambiarColorConsola(GRIS_FUERTE);
    puts("Opciones disponibles\n");
    while (ListaRegistro)
    {
        CambiarColorConsola(BLANCO);
        printf("[%d] %s ", ListaRegistro->info.id, ListaRegistro->info.nombre);
        CambiarColorConsola(InterpretarColor(ListaRegistro->info.valor));
        printf("%s\n", InterpretarValor(ListaRegistro->info.valor));
        ListaRegistro = ListaRegistro->sig;
    }
    CambiarColorConsola(BLANCO);
    return;
}

Lista *ObtenerNodoRegistro(Lista *ListaRegistro, int Numero)
{
    while (ListaRegistro && ListaRegistro->info.id != Numero)
        ListaRegistro = ListaRegistro->sig;
    return ListaRegistro;
}

Lista *GenerarLista(void)
{
    Lista *Raiz = NULL;
    return Raiz;
}

void InsertarSiguiente(Lista **Raiz, Registro NuevoRegistro)
{
    Lista *Nuevo = (Lista *)malloc(sizeof(Lista));
    Lista *Ultimo = *Raiz;
    Nuevo->info = NuevoRegistro;
    Nuevo->sig = NULL;
    if (*Raiz == NULL)
    {
        puts("Insertado primer producto de lista.");
        *Raiz = Nuevo;
        return;
    }

    while (Ultimo->sig != NULL)
        Ultimo = Ultimo->sig;

    Ultimo->sig = Nuevo;
    puts("Nuevo producto insertado en la lista.");
    return;
}

void AgregarOpciones(Lista **Raiz)
{
    Registro Nuevo;

    Nuevo.id = 1;
    Nuevo.raiz = HKEY_CURRENT_USER;
    strcpy(Nuevo.nombre, "Mostrar segundos en el reloj");
    strcpy(Nuevo.ruta, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced");
    strcpy(Nuevo.llave, "ShowSecondsInSystemClock");
    InsertarSiguiente(&*Raiz, Nuevo);

    Nuevo.id = 2;
    Nuevo.raiz = HKEY_CLASSES_ROOT;
    strcpy(Nuevo.nombre, "OneDrive en el explorador de archivos");
    strcpy(Nuevo.ruta, "CLSID\\{018D5C66-4533-4307-9B53-224DE2ED1FE6}");
    strcpy(Nuevo.llave, "System.IsPinnedToNameSpaceTree");
    InsertarSiguiente(&*Raiz, Nuevo);

    Nuevo.id = 3;
    Nuevo.raiz = HKEY_LOCAL_MACHINE;
    strcpy(Nuevo.nombre, "Cortana");
    strcpy(Nuevo.ruta, "SOFTWARE\\Policies\\Microsoft\\Windows\\Windows Search");
    strcpy(Nuevo.llave, "AllowCortana");
    InsertarSiguiente(&*Raiz, Nuevo);

    Nuevo.id = 4;
    Nuevo.raiz = HKEY_LOCAL_MACHINE;
    strcpy(Nuevo.nombre, "Windows Consumer Features");
    strcpy(Nuevo.ruta, "SOFTWARE\\Policies\\Microsoft\\Windows\\CloudContent");
    strcpy(Nuevo.llave, "DisableWindowsConsumerFeatures");
    InsertarSiguiente(&*Raiz, Nuevo);

    return;
}

HKEY AbrirLlave(HKEY Raiz, char *Llave)
{
    HKEY Objetivo;
    if (RegOpenKeyEx(Raiz, Llave, 0, KEY_ALL_ACCESS, &Objetivo) == ERROR_FILE_NOT_FOUND)
    {
        puts("No se encontro el registro.");
        return Raiz;
    }
    return Objetivo;
}

void EstablecerValor(HKEY Raiz, char *Llave, DWORD Data)
{
    if (RegSetValueEx(Raiz, Llave, 0, REG_DWORD, (LPBYTE)&Data, sizeof(DWORD)))
    {
        puts("Error al establecer el valor");
    }
}

DWORD ObtenerValor(HKEY Raiz, char *Llave)
{
    DWORD Data, Tipo = REG_DWORD, Tam = sizeof(Data);
    if (RegQueryValueEx(Raiz, Llave, NULL, &Tipo, (LPBYTE)&Data, &Tam) == ERROR_FILE_NOT_FOUND)
    {
        puts("Llave no encontrada");
        Data = 2;
    }
    return Data;
}

int ActualizarRegistro(Lista **ListaRegistro, int id)
{
    HKEY Llave;
    DWORD Data;
    Lista *Registro = ObtenerNodoRegistro(*ListaRegistro, id);

    if (Registro == NULL)
    {
        puts("Id del registro no encontrada");
        return EXIT_FAILURE;
    }

    Llave = AbrirLlave(Registro->info.raiz, Registro->info.ruta);
    if (Llave == Registro->info.raiz)
    {
        if (id == 3)
        {
            HKEY SubLlave;
            if(RegCreateKeyEx(Registro->info.raiz, Registro->info.ruta, 0, 0, REG_OPTION_NON_VOLATILE,KEY_ALL_ACCESS,NULL, &SubLlave, NULL))
            {
                puts("No se puede crear el registro");
                return EXIT_FAILURE;
            }
        }

        return EXIT_FAILURE;
    }

    Data = ObtenerValor(Llave, Registro->info.llave);
    if (Data == 2)
    {
        printf("Creando llave %s por primera vez\n", Registro->info.llave);
        EstablecerValor(Llave, Registro->info.llave, Data);
    }

    Registro->info.valor = !Data;
    EstablecerValor(Llave, Registro->info.llave, !Data);
    RegCloseKey(Llave);
    return EXIT_SUCCESS;
}