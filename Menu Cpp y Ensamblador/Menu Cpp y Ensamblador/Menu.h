#pragma once

// Librerías
#include <iostream>
#include "Dibujo.h"
#include "CapturaSegura.h"
#include "FuncionesEnsamblador.h"

using namespace std;

// Función Nombre ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Fin Función Nombre ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Enumeración para las opciones del menú.
enum MENU_OPCIONES { SALIR, ENCONTRAR_LETRA, MOSTRAR_PALABRAS, POSICIONES_LETRA, LONGITUD_CADENA };


// Función ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ImprimirMenu(int& opcionUsuario, int posX, int posY)
{
    int actualPosX = posX;
    int actualPosY = posY;

    const char opcion1[] = "Encontrar y contar una letra.";
    const char opcion2[] = "Mostrar palabras con enter.";
    const char opcion3[] = "Identificar posiciones de una letra.";
    const char opcion4[] = "Obtener y mostrar longitud de una cadena.";
    const char opcion0[] = "Salir.";

    gotoxy(actualPosX, actualPosY++);
    cout << "======= MENU GENERAL C++ Y ENSAMBLADOR =======";       gotoxy(actualPosX, actualPosY++);
    cout << "[" << ENCONTRAR_LETRA     << "] " << opcion1;          gotoxy(actualPosX, actualPosY++);
    cout << "[" << MOSTRAR_PALABRAS    << "] " << opcion2;          gotoxy(actualPosX, actualPosY++);
    cout << "[" << POSICIONES_LETRA    << "] " << opcion3;          gotoxy(actualPosX, actualPosY++);
    cout << "[" << LONGITUD_CADENA     << "] " << opcion4;          gotoxy(actualPosX, actualPosY++);
    cout << "[" << SALIR               << "] " << opcion0;          gotoxy(actualPosX, actualPosY++);

    // Capturar la opción elegida por el usuario
    gotoxy(actualPosX, actualPosY++);
    do {
        CapturaNumero(opcionUsuario, "\n Elige una opci\242n: ");

        if (opcionUsuario < SALIR || opcionUsuario > LONGITUD_CADENA)
            cout << "---> ERROR: Debe elegir una opci\242n del men\243. Vuelve a intentarlo.\n";

    } while (opcionUsuario < SALIR || opcionUsuario > LONGITUD_CADENA);
}
// Fin Función ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Funcion MostrarPalabras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void EncontrarLetra(int posX, int posY)
{
    char letraBuscada;

    // Titulo.
    gotoxy(posX, posY++);
    cout << "======= ENCONTRAR Y CONTAR UNA LETRA =======";

    // Cadena original.
    posY++;
    gotoxy(posX, posY++);
    cout << "La cadena es: " << cadenaEntrada;

    // Capturar la letra que se va a buscar.
    posY++;
    gotoxy(posX, posY++);
    cout << "Introduce la letra  a buscar: ";
    cin >> letraBuscada;

    // Posiciones.
    posY++;
    gotoxy(posX, posY++);
    cout << "Ocurrencias: " << EncontrarLetraASM(letraBuscada, posX, posY);
}
// Fin MostrarPalabras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Funcion MostrarPalabras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MostrarPalabras(int posX, int posY)
{
    // Titulo.
    gotoxy(posX, posY++);
    cout << "======= MOSTRAR PALABRAS =======";

    // cadena original.
    posY++;
    gotoxy(posX, posY++);
    cout << "La cadena es: " << cadenaEntrada;

    // Palabras
    posY++;
    gotoxy(posX, posY++);
    cout << "Las palabras de la cadena son:";

    posX += 5; posY += 1;
    MostrarPalabrasASM(posX, posY);
}
// Fin MostrarPalabras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función PosicionLetra ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void PosicionLetra(int posX, int posY)
{
    char letraBuscada;

    // Titulo.
    gotoxy(posX, posY++);
    cout << "======= POSICION LETRA =======";

    // Cadena original.
    posY++;
    gotoxy(posX, posY++);
    cout << "La cadena es: " << cadenaEntrada;

    // Capturar la letra que se va a buscar.
    posY++;
    gotoxy(posX, posY++);
    cout << "Introduce la letra  a buscar: ";
    cin >> letraBuscada;

    // Posiciones.
    posY++;
    gotoxy(posX, posY++);
    cout << "Las posiciones de la letra son:";

    posX += 5; posY += 1;
    PosicionLetraASM(letraBuscada, posX, posY);
}
// Fin Función PosicionLetra ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función LongitudCadena ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LongitudCadena(int posX, int posY)
{
    system("CLS"); // Se limpia la pantalla.

    // Titulo.
    gotoxy(posX, posY++);
    cout << "======= LONGITUD DE UNA CADENA =======";

    // cadena original.
    posY++;
    gotoxy(posX, posY++);
    cout << "La cadena es: " << cadenaEntrada;

    // Calculamos la longitud de la cadena y mostramos el resultado
    posY++;
    gotoxy(posX, posY++);
    cout << "Longitud: " << LongitudCadenaASM();
}
// Fin Función LongitudCadena ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
