#ifndef WINARIAN_H_INCLUDED
#define WINARIAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NOMBRE "WINARIAN"
#define VERSION "0.0.3"
#define AUTOR "ne0de"

#define DESACTIVADO 0
#define ACTIVADO 1

#define _MAX_TITLE 64

#define R_EXPLORADOR_AVANZADO "Software\vMicrosoft\\Windows\\CurrentVersion\\Explorer\\Advanced"

typedef struct InfoRegistro
{
    int id, valor;
    char nombre[_MAX_PATH], llave[_MAX_FNAME], ruta[_MAX_PATH];
} Registro;

typedef struct InfoNodo
{
    Registro info;
    struct InfoNodo *sig;
} Nodo;

void AjustarVentana(void);
void EstablecerTituloConsola(void);
void MostrarSubtitulo(void);
void MostrarMenu(Nodo *ListaRegistro);
char *InterpretarValor(int);
Nodo *ObtenerNodoRegistro(Nodo *, int);
Nodo *InicializarWinarian(void);
int ObtenerValorRegistro(Nodo **, int);

#endif // WINARIAN_H_INCLUDED
