#include <iostream>
#include "Menu.h"

using namespace std;

// Función main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    // Variables -----------------------------------------
    int opcionUsuario;
	int posX = 5, posY = 3;

	gotoxy(posX, posY);
	cout << "Introduzca una cadena inicial: ";
	cin.get(cadenaEntrada, 100);

	leng = strlen(cadenaEntrada);

    // Ciclo principal
    do
    {
        // Limpar la pantalla.
        system("CLS");

        // Imprimir el menu y campurar la opción del usuario.
        ImprimirMenu(opcionUsuario, posX, posY);


		// Invocar la función que corresponde con la elección del usuario.
		switch (opcionUsuario) {
			case ENCONTRAR_LETRA:
				system("CLS");
				EncontrarLetra(posX, posY);
				break;
			case MOSTRAR_PALABRAS:
				system("CLS");
				MostrarPalabras(posX, posY);
				break;
			case POSICIONES_LETRA:
				system("CLS");
				PosicionLetra(posX, posY);
				break;
			case LONGITUD_CADENA:
				LongitudCadena(posX, posY);
				break;
		}


		gotoxy(3, 20); system("PAUSE");

    } while (opcionUsuario != SALIR);

    return 0;
}
// Fin Función main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

