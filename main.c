#include "src/winarian.h"
#include "src/color.h"

int main(int argc, char *argv[])
{
    int id;
    struct Lista *Lista = GenerarLista();
    AgregarOpciones(&Lista);

    AjustarVentana();
    EstablecerTituloConsola();

    //for (size_t i = 1; i <= 3; i++) ActualizarRegistro(&Lista, i);
    
    while (1)
    {
        MostrarSubtitulo();
        MostrarMenu(Lista);
        scanf("%d", &id);
        ActualizarRegistro(&Lista, id);
        //system("cls");
    }
    system("pause");
    return 0;
}