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

void MostrarMenu(Nodo *ListaRegistro)
{
    while (ListaRegistro)
    {
        CambiarColorConsola(BLANCO);
        puts("Opciones del registro\n");
        CambiarColorConsola(CYAN);
        printf("[%d] %s ", ListaRegistro->info.id, ListaRegistro->info.nombre);
        CambiarColorConsola(VERDE);
        printf("%s\n", InterpretarValor(ListaRegistro->info.valor));
        ListaRegistro = ListaRegistro->sig;
    }
}

Nodo *ObtenerNodoRegistro(Nodo *ListaRegistro, int Numero)
{
    while (ListaRegistro && ListaRegistro->info.id != Numero)
        ListaRegistro = ListaRegistro->sig;
    return ListaRegistro;
}

Nodo *InicializarWinarian(void)
{
    Nodo *Raiz = malloc(sizeof(Nodo));
    Raiz->sig = NULL;
    Raiz->info.id = 1;
    strcpy(Raiz->info.nombre, "Mostrar segundos en el reloj");
    strcpy(Raiz->info.ruta, "Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Advanced");
    strcpy(Raiz->info.llave, "ShowSecondsInSystemClock");
    // ObtenerValorRegistro(&MostrarSegundos);
    return Raiz;
}

int ObtenerValorRegistro(Nodo **ListaRegistro, int id)
{
    HKEY Llave;
    DWORD Data;
    DWORD DataTam = sizeof(Data);
    Nodo *Registro = ObtenerNodoRegistro(*ListaRegistro, id);

    puts("Obteniendo registro..");

    if (Registro == NULL)
    {
        puts("No existe ese id de registro");
        return EXIT_FAILURE;
    }

    printf("Obteniendo ruta %s", Registro->info.ruta);

    if (RegOpenKeyEx(HKEY_CURRENT_USER, Registro->info.ruta, 0, KEY_QUERY_VALUE, &Llave) != ERROR_SUCCESS)
    {
        puts("Error al leer el registro principal.");
        RegCloseKey(Llave);
        return EXIT_FAILURE;
    }

    if (RegQueryValueEx(Llave, Registro->info.llave, 0, 0, (PVOID)&Data, &DataTam) != ERROR_SUCCESS)
    {
        puts("Error al leer la subllave registro.");
        RegCloseKey(Llave);
        return EXIT_FAILURE;
    }
    RegCloseKey(Llave);
    Registro->info.valor = Data;
    return EXIT_SUCCESS;
}