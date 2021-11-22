#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#ifndef _WINCON_
#include <windows.h>
#endif

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004

#define ROJO (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define VERDE (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define BLANCO (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define CYAN (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define GRIS (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#define GRIS_FUERTE FOREGROUND_INTENSITY

int LimpiarConsola(void);
int CambiarColorConsola(unsigned short Color);

#endif //COLOR_H_INCLUDED
