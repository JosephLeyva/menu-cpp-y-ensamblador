#pragma once

// Librerías
#include <iostream>
#include "Dibujo.h"
#include "CapturaSegura.h"

using namespace std;

// Función Nombre ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Fin Función Nombre ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Enumeración para las opciones del menú.
enum MENU_OPCIONES { SALIR, ENCONTRAR_LETRA, MOSTRAR_PALABRAS, POSICIONES_LETRA, LONGITUD_CADENA };

// Declaración de funciones.
void ImprimirMenu(int& opcionUsuario);
void LongitudCadena(const char cadena[]);


// Función ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void ImprimirMenu(int& opcionUsuario)
{
    const char opcion1[] = "Encontrar y contar una letra.";
    const char opcion2[] = "Mostrar palabras con enter.";
    const char opcion3[] = "Identificar posiciones de una letra.";
    const char opcion4[] = "Obtener y mostrar longitud de una cadena.";
    const char opcion0[] = "Salir.";

    cout << "======= MENU GENERAL C++ Y ENSAMBLADOR =======\n\n";    
    cout << "[" << ENCONTRAR_LETRA     << "] " << opcion1 << "\n";
    cout << "[" << MOSTRAR_PALABRAS    << "] " << opcion2 << "\n";
    cout << "[" << POSICIONES_LETRA    << "] " << opcion3 << "\n";
    cout << "[" << LONGITUD_CADENA     << "] " << opcion4 << "\n";
    cout << "[" << SALIR               << "] " << opcion0 << "\n\n";

    // Capturar la opción elegida por el usuario
    do {
        CapturaNumero(opcionUsuario, "\n Elige una opci\242n: ");

        if (opcionUsuario < SALIR || opcionUsuario > LONGITUD_CADENA)
            cout << "---> ERROR: Debe elegir una opci\242n del men\243. Vuelve a intentarlo.\n";

    } while (opcionUsuario < SALIR || opcionUsuario > LONGITUD_CADENA);
}
// Fin Función ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función LongitudCadena ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void LongitudCadena(const char cadena[])
{
    int longitudCadena = 0;

    system("CLS"); // Se limpia la pantalla.

    // Titulo.
    cout << "\n\n ======= LONGITUD DE UNA CADENA =======\n\n";

    // cadena original.
    cout << "La cadena es: " << cadena << "\n";

    // código ensamblador...

    // Mostrar resultado.
    cout << "Longitud: " << longitudCadena << "\n\n";
}
// Fin Función LongitudCadena ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~