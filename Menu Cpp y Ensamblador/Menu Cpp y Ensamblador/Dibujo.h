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
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { x - 1, y - 1 };
    SetConsoleCursorPosition(handle, coord);
}
// Fin Función gotoxy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
