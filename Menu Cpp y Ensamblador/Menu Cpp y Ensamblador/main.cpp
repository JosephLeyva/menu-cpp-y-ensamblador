#include <iostream>
#include "Menu.h"

using namespace std;


// Función main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    // Variables -----------------------------------------
    int opcionUsuario;

	cout << "Introduzca una cadena inicial: ";
	cin.get(cadenaEntrada, 100);

    // Ciclo principal
    do
    {
        // Limpar la pantalla.
        system("CLS");

        // Imprimir el menu y campurar la opción del usuario.
        ImprimirMenu(opcionUsuario, 5, 3);


		// ------------------------------------------
		switch (opcionUsuario) {
		case ENCONTRAR_LETRA:
			system("CLS");
			cout << "\nOPCION 1\n";
			break;
		case MOSTRAR_PALABRAS:
			system("CLS");
			Separar_Palabras();
			break;
		case POSICIONES_LETRA:
			system("CLS");
			cout << "\nOPCION 3\n";
			break;
		case LONGITUD_CADENA:
			LongitudCadena(cadenaEntrada);
			break;
		}


        system("PAUSE");

    } while (opcionUsuario != SALIR);


    cout << "\n\n\n\n\n\n";

    return 0;
}
// Fin Función main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

