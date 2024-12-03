#include <stdio.h>  
#include <string.h> 

// Función para comprimir la cadena
void compressString(const char *word, char *comp) {
    int i = 0;  // Variable para recorrer la cadena original
    int length = strlen(word);  // Longitud de la cadena original
    int compIndex = 0;  // Índice para la cadena comprimida

    // Recorre la cadena original
    while (i < length) {
        char c = word[i];  // Caracter actual en la cadena original
        int count = 0;  // Contador de repeticiones consecutivas del carácter

        // Cuenta las repeticiones consecutivas del mismo carácter 'c'
        // El bucle interno permite contar hasta 9 repeticiones consecutivas
        while (i < length && word[i] == c && count < 9) {
            count++;  // Incrementar el contador por cada repetición consecutiva
            i++;  // Avanzar al siguiente carácter en la cadena
        }

        // Añade el número de repeticiones seguido del carácter a la cadena comprimida
        comp[compIndex++] = count + '0'; // Convertimos el número a su representación en carácter (por ejemplo, 3 se convierte en '3')
        comp[compIndex++] = c;  // Añadimos el carácter actual a la cadena comprimida
    }

    comp[compIndex] = '\0'; // Añadimos el carácter nulo ('\0') al final de la cadena comprimida para marcar su fin
}

int main() {
    char word[100];  // Arreglo para almacenar la palabra de entrada
    char comp[200];  // Arreglo para almacenar la cadena comprimida (puede ser hasta el doble de largo que la original)

    // Solicita al usuario que ingrese una palabra
    printf("Ingrese una palabra para comprimir: ");
    scanf("%s", word);  // Lee la palabra ingresada por el usuario

    // Llama a la función para comprimir la palabra
    compressString(word, comp);

    
    printf("Cadena comprimida: %s\n", comp);

    return 0;  
}
