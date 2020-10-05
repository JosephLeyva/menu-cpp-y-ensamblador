/* ---------------------------------------------------------------------------------------
  Nombre: CapturaSegura.h
  Autor: Aguilera Luzania José Luis
  Fecha: 11/ ABRIL/2019
  Descripción: Archivo de cabecera que define las plantillas de funciones de captura
			   segura de números y vectores (evita valores no númericos).

 * ---------------------------------------------------------------------------------------
 */

#ifndef CAPTURASEGURA_H_INCLUDED
#define CAPTURASEGURA_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include "Dibujo.h"

using std::cout;
using std::cin;

/** \brief Función que captura un número con formato adecuado (Plantilla).
 *
 * \param Puntero a la variable donde se almacenará el valor capturado.
 * \param Solicitud, cadena de caracteres que solicita el dato a capturar.
 *
*/
// Función CapturaNumero ----------------------------------------------------------------------
template <typename T>
void CapturaNumero(T& valorNum, const char solicitud[])
{
	while (true) {
		cout << solicitud;
		cin >> valorNum;

		if (cin.bad()) {
			cout << "\n---> ERROR: Ocurri\242 un error irrecuperable en el flijo de entrada. \n\n";
			system("pause");
			return;
		}

		if (cin.fail()) {
			cout << "\n---> ERROR: No es un n\243mero. Vuelve a intentarlo. \n\n";
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		return;
	}
}
// Fin Función CapturaNumero ------------------------------------------------------------------

#endif // CAPTURASEGURA_H_INCLUDED
