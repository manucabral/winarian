#include "color.h"

int LimpiarConsola(void)
{
    HANDLE hStdOut;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;

    if (!GetConsoleMode(hStdOut, &mode))
        return EXIT_FAILURE;

    const DWORD originalMode = mode;
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(hStdOut, mode))
        return EXIT_FAILURE;

    DWORD written = 0;
    PCWSTR sequence = L"\x1b[2J";
    if (!WriteConsoleW(hStdOut, sequence, (DWORD)wcslen(sequence), &written, NULL))
    {
        SetConsoleMode(hStdOut, originalMode);
        return 0;
    }

    SetConsoleMode(hStdOut, originalMode);
    return EXIT_SUCCESS;
}

int CambiarColorConsola(unsigned short Color)
{
    HANDLE ManipuladorConsola = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(ManipuladorConsola, Color);
    return EXIT_SUCCESS;
}
