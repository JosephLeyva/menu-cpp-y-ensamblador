#include <iostream>
#include "Menu.h"

using namespace std;


// Función main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int main()
{
    // Variables -----------------------------------------
    int opcionUsuario;
	const char cadenaPrueba[] = "Hola nundo";

    // Ciclo principal
    do
    {
        // Limpar la pantalla.
        system("CLS");

        // Imprimir el menu y campurar la opción del usuario.
        ImprimirMenu(opcionUsuario);


		// ------------------------------------------
		switch (opcionUsuario) {
		case ENCONTRAR_LETRA:
			system("CLS");
			cout << "\nOPCION 1\n";
			break;
		case MOSTRAR_PALABRAS:
			system("CLS");
			cout << "\nOPCION 2\n";
			break;
		case POSICIONES_LETRA:
			system("CLS");
			cout << "\nOPCION 3\n";
			break;
		case LONGITUD_CADENA:
			LongitudCadena(cadenaPrueba);
			break;
		}


        system("PAUSE");

    } while (opcionUsuario != SALIR);


    cout << "\n\n\n\n\n\n";

    return 0;
}
// Fin Función main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

