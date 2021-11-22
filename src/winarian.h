#ifndef WINARIAN_H_INCLUDED
#define WINARIAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define NOMBRE "WINARIAN" 
#define VERSION "0.0.1"
#define AUTOR "ne0de"

#define DESACTIVADO 0
#define ACTIVADO 1

#define _MAX_TITLE 64

typedef struct Config
{
    int MostrarCortana;
    int MostrarReloj;
    int ArchivosOcultos;
    int WCF;
} Configuracion;

void AjustarVentana(void);
void EstablecerTituloConsola(void);
void MostrarSubtitulo(void);
void MostrarMenu(void);

#endif // WINARIAN_H_INCLUDED
