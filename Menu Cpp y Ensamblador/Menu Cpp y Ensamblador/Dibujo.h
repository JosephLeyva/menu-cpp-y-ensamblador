#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <windows.h>


// Declaración de funciones.
void gotoxy(int x, int y);


// Función gotoxy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void gotoxy(int x, int y)
{
    if (x <= 0) x = 1;
    if (y <= 0) y = 1;

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { x - 1, y - 1 };
    SetConsoleCursorPosition(handle, coord);
}
// Fin Función gotoxy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
