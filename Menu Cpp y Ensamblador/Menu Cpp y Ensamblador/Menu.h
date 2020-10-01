#pragma once

// Librerías
#include <iostream>
#include "Dibujo.h"

using namespace std;

// Enumeración para las opciones del menú.
enum MENU_OPCIONES { SALIR, ENCONTRAR_LETRA, MOSTRAR_PALABRAS, POSICIONES_LETRA, LONGITUD_CADENA, OCURRENCIAS_PALABRA };

// Declaración de funciones.
void ImprimirMenu(int x = 0, int y = 0);


// Función ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ImprimirMenu(int posicionX, int posicionY)
{
    int posicionXActual = posicionX;
    int posicionYActual = posicionY;

    const char opcion1[] = "Encontrar y contar una letra.";
    const char opcion2[] = "Mostrar palabras con enter.";
    const char opcion3[] = "Identificar posiciones de una letra.";
    const char opcion4[] = "Obtener y mostrar longitud de una cadena.";
    const char opcion5[] = "Ocurrencias de una palabra en la cadena de entrada.";
    const char opcion0[] = "Salir.";

    gotoxy(posicionX, posicionY++);
    cout << "[" << ENCONTRAR_LETRA     << "] " << opcion1 << "\n";         gotoxy(posicionXActual, posicionYActual++);
    cout << "[" << MOSTRAR_PALABRAS    << "] " << opcion2 << "\n";         gotoxy(posicionXActual, posicionYActual++);
    cout << "[" << POSICIONES_LETRA    << "] " << opcion3 << "\n";         gotoxy(posicionXActual, posicionYActual++);
    cout << "[" << LONGITUD_CADENA     << "] " << opcion4 << "\n";         gotoxy(posicionXActual, posicionYActual++);
    cout << "[" << OCURRENCIAS_PALABRA << "] " << opcion5 << "\n";         gotoxy(posicionXActual, posicionYActual++);
    cout << "[" << SALIR               << "] " << opcion0 << "\n";
}
// Fin Función ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~