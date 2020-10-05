#pragma once

// Deifnimos la cadena que se va a utilizar.
char cadenaEntrada[100];
int leng = 0;


// Función LongitudCadenaASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int EncontrarLetraASM(char letraBuscada, int posX, int posY)
{
    int ocurrencias = 0;

    _asm 
    {
            LEA	EDI, cadenaEntrada - 1  // Tomamos la direccion de referencia de la cadena

        BUSCAR:
            INC EDI	                    // Incrementamos el apuntador.
            MOV	DL, [EDI]               // Pasamos el valor del caracter a dl
            CMP	DL, '\0'                // Compara con fin de cadena
            JE	TERMINAR                // Si se tiene el fin de cadena termina el proceso
            CMP	letraBuscada, DL        // Comparamos el caracter en dl con la letra ingresada
            JE	ACUMULADOR              // Si son iguales saltamos al acumulador
            JMP	BUSCAR                  // Si no son iguales regresa a contar.

        ACUMULADOR :
            ADD	ocurrencias, 1          // Añade 1 al contar.
            JMP	BUSCAR                  // Regresa a buscar.

        TERMINAR :
    }

    return ocurrencias;
}
// Fin Función LongitudCadenaASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función MostrarPalabrasASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MostrarPalabrasASM(int posX, int posY)
{
    int contPalabras = 1;
    char palabra[50];

    _asm
    {
            LEA EDI, cadenaEntrada  // Inicializamos la cadena de entrada en el registro DI
            LEA ESI, palabra        // Inicializamos la palabra en el registro SI
            DEC EDI

        INIC :
            INC EDI                 // Avanzamos al siguiente caracter de la cadena de entrada
            MOV AL, [EDI]           // Movemos el caracter de la cadena a AL
            CMP AL, '\0'            // Comparamos el caracter de la cadena con el fin de cadena
            JE FINALIZAR_MP         // Si es el fin de cadena saltamos a finalizarSP
            CMP al, 20h             // Comparamos el caracter de la cadena con un espacio
            JE ESPACIO_MP           // Si es un espacio salta a espacioSP
            MOV[ESI], AL            // Cualquier otro caracter es agregado a la cadena "palabra"
            INC ESI                 // Avanzamos al siguiente espacio para la palabra
            JMP INIC                // Regresamos al ciclo

        ESPACIO_MP :
            MOV AL, '\0'            // Cuando encuentra un espacio en la cadenaEntrada se agrega un fin de cadena en la palabra
            MOV[ESI], AL
    }

    gotoxy(posX, posY++);
    std::cout << contPalabras++ << ".- " << palabra;    // Imprime la palabra

    _asm 
    {
            LEA ESI, palabra        // Volvemos al inicio de la palabra para volver a utilizar la misma cadena
            JMP INIC                // Regresamos al inicio del ciclo para continuar con la busqueda

        FINALIZAR_MP :
            //mov al, '\0'
            MOV[ESI], AL            // Agregamos el ultimo caracter a la palabra, la imprimimos y termina el programa
    }

    gotoxy(posX, posY++);
    std::cout << contPalabras++ << ".- " << palabra;    // Imprime la palabra
    return;
}
// Fin Función MostrarPalabrasASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función LongitudCadenaASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int LongitudCadenaASM()
{
    int longitud = 0;

    _asm
    {
        LEA EDI, cadenaEntrada          // Inicializamos la cadena de entrada en el registro DI.
        DEC EDI

        COMIENZO :
            INC EDI                     // Avanzamos al siguiente caracter de la cadena de entrada.
            MOV AL, [EDI]               // Movemos el caracter de la cadena a AL.

            CMP AL, '\0'                // Se compara el caracter con el caracter de fin de cadena.
            JE TERMINAR                 // Si es el fin de cadena saltamos a TERMINAR.

            ADD longitud, 1             // Añadimos 1 a la variable de la longitud.

            JMP COMIENZO                // Regresamos al comienzo.

            TERMINAR :
        // Finaliza la función.
    }

    return longitud;
}
// Fin Función LongitudCadenaASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// Función PosicionLetraASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int PosicionLetraASM(char letraBuscada, int posX, int posY)
{
    int posicion;       // Posición de la letra.
    int bandera = 1;    // Bandera para saber si no se encontro el caracter.

    _asm 
    {
            LEA EDI, cadenaEntrada - 1      // Se pone en la posicion de la cadena para empezar el recorrido.
            MOV ECX, leng                   // Se obtiene la longitud y ecx lo copia.
        
            MOV EBX, 1                      // ebx obtendrá la posición, por lo que inicia en 1.
            MOV EAX, 0                      // eax checa las ocurrencias que hay en la cadena de la letra a buscar.

        RECORRER:
            INC EDI
            MOV DL, [EDI]                   // Al hacer el recorrido, dl obtiene le valor de la letra que está en la cadena.
            CMP DL, '\0'                    // Se compara con el fin de cadena para ver si se necesita comparar mas.
            JE  PREG_ENCONTRADO
            CMP letraBuscada, DL            // Si todavia sigue, se compara con la letra ingresada.
            JE  IMPRIMIR_POSICION           // Si es igual, se va a impr_posi.
            JMP INCREMENTO

        IMPRIMIR_POSICION:
            MOV posicion, EBX               // La variable posicion obtiene el valor de ebx (para posteriormente imprimirlo).
            INC EAX                         // Se incrementa eax puesto que se encontró una letra.
    }

    gotoxy(posX, posY++);
    cout << "Posicion: " << posicion;       // Aqui se imprime el valor

    _asm 
    {
        INCREMENTO:
            INC EBX                         // En incremento se incrementa la posición de ebx y se regresa al ciclo de recorrer
            LOOP RECORRER

        PREG_ENCONTRADO:
            CMP EAX, 0                      // Aqui checa si se encontró o no la letra y si es el caso imprime un mensaje que no la encontró
            JE NO_ENC
            JMP FINALIZAR_PL
        
        NO_ENC:
            MOV bandera, 0                  // Con una bandera cambiamos el valor para que pueda mostrarse el mensaje en pantalla

    }

    if (bandera == 0) 
    { 
        gotoxy(posX, posY++);
        cout << "El caracter no fue encontrado en la cadena."; 
    }

    _asm 
    {
        FINALIZAR_PL:
    }
}
// Fin Función PosicionLetraASM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
