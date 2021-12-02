#include "src/winarian.h"
#include "src/color.h"

int main(int argc, char *argv[])
{
    int id;
    struct Lista *Lista = GenerarLista();
    AgregarOpciones(&Lista);

    AjustarVentana();
    EstablecerTituloConsola();

<<<<<<< HEAD
    for (size_t i = 1; i <= 3; i++) ActualizarRegistro(&Lista, i);
    system("cls");
=======
>>>>>>> f48dff8d1faf68e7a9cc45eb89db8e58175ccba8
    while (1)
    {
        MostrarSubtitulo();
        MostrarMenu(Lista);
        scanf("%d", &id);
        if(id == 5)
            break;
        CambiarValorRegistro(&Lista, id);
        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}
