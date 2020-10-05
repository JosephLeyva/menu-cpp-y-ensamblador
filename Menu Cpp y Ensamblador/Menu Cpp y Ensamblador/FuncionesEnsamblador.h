#pragma once
char cadenaEntrada[100];

// Función Nombre ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int LongitudCadenaASM(const char cadena[])
{
	int longitud = 0;

	return longitud;
}

// Fin Función Nombre ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Separar Palabras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void SepararPalabrasASM()
{
    char palabra[50];
    _asm {
        lea edi, cadenaEntrada
        lea esi, palabra
        dec edi
    inic :
        inc edi
        mov al, [edi]
        cmp al, '\0'
        je s1
        cmp al, 20h
        je mostrar_res2
        mov[esi], al
        inc esi
        jmp inic

    mostrar_res2 :
        mov al, '\0'
        mov[esi], al
    }
    std::cout << palabra << std::endl;
    _asm {
        lea esi, palabra
        jmp inic

    s1 :
        mov al, '\0'
        mov[esi], al
    }
    std::cout << palabra << std::endl << std::endl;
    return;
}

// Fin Separar Palabras ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~