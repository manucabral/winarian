#include "winarian.h"
#include "color.h"

void AjustarVentana(void)
{
    SMALL_RECT Tam = {0 , 0 , 70, 30};
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

void MostrarMenu(void)
{
    CambiarColorConsola(BLANCO);
    puts("Opciones del registro\n");
    CambiarColorConsola(CYAN); printf("[1] Buscador cortana "); CambiarColorConsola(VERDE); printf("Activado\n");
    CambiarColorConsola(CYAN); printf("[2] Mostrar segundos en el reloj "); CambiarColorConsola(VERDE); printf("Activado\n");
    CambiarColorConsola(CYAN); printf("[3] Mostrar archivos ocultos "); CambiarColorConsola(ROJO); printf("Desactivado\n");
    CambiarColorConsola(CYAN); printf("[4] Windows Consumer Features "); CambiarColorConsola(ROJO); printf("Desactivado\n");
}