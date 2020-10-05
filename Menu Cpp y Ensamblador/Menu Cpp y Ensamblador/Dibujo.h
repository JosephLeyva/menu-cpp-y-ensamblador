#pragma once

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <windows.h>

#define ANCHO_VENTANA 100
#define ALTO_VENTANA 35

// Simbolos para pintar el marco de la carta.
enum { BV = 179, BH = 196, ESD = 191, ESI = 218, EID = 217, EII = 192 };


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


// Función dibujaMarco ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ImprimeMarco(int ancho = ANCHO_VENTANA, int alto = ALTO_VENTANA, int x = 1, int y = 1)
{
    // Parte superior
    gotoxy(x, y);
    std::cout << (char)ESI;
    for (int i = 2; i < ancho; ++i) std::cout << (char)BH;
    std::cout << (char)ESD;

    // Parte media
    for (int i = 2; i < alto; ++i) {
        gotoxy(x, ++y);
        std::cout << (char)BV;
        for (int k = 2; k < ancho; ++k) std::cout << " ";
        std::cout << (char)BV;
    }

    // Parte inferior
    gotoxy(x, ++y);
    std::cout << (char)EII;
    for (int i = 2; i < ancho; ++i) std::cout << (char)BH;
    std::cout << (char)EID;
}
// Fin Función dibujaMarco ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función TamVentana ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void TamVentana(int Ancho, int Alto)
{
    _COORD coord;
    coord.X = Ancho;
    coord.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Alto - 1;
    Rect.Right = Ancho - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}
// Fin Función TamVentana ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~