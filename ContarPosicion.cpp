#include <iostream>

using namespace std;

char CadEntrada[50];
char MensajeI[] = "Introdzca una cadena inicial: ";
char hola[] = "Su cadena es: ";
char menu3[] = "3. Identificar posiciones de una letra";
char No_Encontrado[] = "El caracter no fue encontrado en la cadena";
char msg_letra[] = "Ingrese la letra a buscar: ";
char letra;
int posicion;
int leng = 0;
char msg_posicion[] = "Las posiciones en las que la letra se encuentra son: ";


void entrada(void)
{
    cout << MensajeI;
    cin.getline(CadEntrada,50,'\n');
    leng = strlen(CadEntrada);
    cout << hola;
    cout << CadEntrada;
    return;
}

void posicion_letra(void)
{
    //Se muestra en pantalla la pantalla del menú y la captura de la letra
    cout << menu3 << endl << endl;
    cout << msg_letra;
    cin >> letra;
    cout << msg_posicion;

    _asm {
        //Se pone en la posicion de la cadena para empezar el recorrido
        lea        edi, CadEntrada - 1
        //Se obtiene la longitud y ecx lo copia
        mov        ecx, leng
        //ebx obtendrá la posición, por lo que inicia en 1
        mov        ebx, 1

        recorrer :
            inc     edi
            mov        dl, [edi] //Al hacer el recorrido, dl obtiene le valor de la letra que está en la cadena
            cmp     dl, '\0' //Se compara con el fin de cadena para ver si se necesita comparar mas
            je      finalizar
            cmp        letra, dl //Si todavia sigue, se compara con la letra ingresada
            je        impr_posi //Si es igual, se va a impr_posi
            jmp        incremento

        impr_posi :
            mov posicion, ebx //la variable posicion obtiene el valor de ebx (para posteriormente imprimirlo)
    }


    cout << posicion <<  ", "; //Aqui se imprime el valor

    _asm {
        incremento:
            //En incremento se incrementa la posición de ebx y se regresa al ciclo de recorrer
            inc        ebx
            loop    recorrer
            finalizar :
                ret
    }

    return;

}
int main()
{
    entrada();
    cout << endl << endl;
    posicion_letra();
}
