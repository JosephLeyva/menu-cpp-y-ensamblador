#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <windows.h>


// Declaraci�n de funciones.
void gotoxy(int x, int y);


// Funci�n gotoxy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { x - 1, y - 1 };
    SetConsoleCursorPosition(handle, coord);
}
// Fin Funci�n gotoxy ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
