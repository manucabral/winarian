#include "src/winarian.h"
#include "src/color.h"

int main(int argc, char *argv[])
{
    int id;
    Nodo *ListaRegistro = InicializarWinarian();

    AjustarVentana();
    EstablecerTituloConsola();

    while (1)
    {
        MostrarSubtitulo();
        MostrarMenu(ListaRegistro);
        scanf("%d", &id);
        ObtenerValorRegistro(&ListaRegistro, id);
        LimpiarConsola();
    }
    system("pause");
    return 0;
}