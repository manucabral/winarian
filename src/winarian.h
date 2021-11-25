#ifndef WINARIAN_H_INCLUDED
#define WINARIAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define NOMBRE "WINARIAN"
#define VERSION "0.0.5"
#define AUTOR "ne0de"

#define DESACTIVADO 0
#define ACTIVADO 1

#define _MAX_TITLE 64

typedef struct InfoRegistro
{
    int id, valor;
    HKEY raiz;
    char nombre[_MAX_PATH], llave[_MAX_FNAME], ruta[_MAX_PATH];
} Registro;

typedef struct Lista
{
    Registro info;
    struct Lista *sig;
} Lista;

void AjustarVentana(void);
void EstablecerTituloConsola(void);
void MostrarSubtitulo(void);
void MostrarMenu(Lista *);
char *InterpretarValor(int);
int InterpretarColor(int);
Lista *GenerarLista(void);
void InsertarSiguiente(Lista **, Registro);
void AgregarOpciones(Lista **);
int ActualizarRegistro(Lista **, int);

#endif // WINARIAN_H_INCLUDED
