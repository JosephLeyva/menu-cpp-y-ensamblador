#pragma once

// Librer�as
#include <iostream>
#include "Dibujo.h"
#include "CapturaSegura.h"

using namespace std;

// Enumeraci�n para las opciones del men�.
enum MENU_OPCIONES { SALIR, ENCONTRAR_LETRA, MOSTRAR_PALABRAS, POSICIONES_LETRA, LONGITUD_CADENA };

// Declaraci�n de funciones.
void ImprimirMenu(int& opcionUsuario);


// Funci�n ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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

    // Capturar la opci�n elegida por el usuario
    do {
        CapturaNumero(opcionUsuario, "\n Elige una opci\242n: ");

        if (opcionUsuario < SALIR || opcionUsuario > LONGITUD_CADENA)
            cout << "---> ERROR: Debe elegir una opci\242n del men\243. Vuelve a intentarlo.\n";

    } while (opcionUsuario < SALIR || opcionUsuario > LONGITUD_CADENA);
}
// Fin Funci�n ImprimirMenu ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~