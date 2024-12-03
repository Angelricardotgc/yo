#include <stdio.h>
#define TAMANO 9  // Definir el tamaño del arreglo como 9

int nums[TAMANO] = {1, 1, 2, 2, 3, 3, 4, 5, 5};  // Arreglo global

// Función para eliminar duplicados
int remover() {
    int tamano = TAMANO;  // Usa el tamaño inicial definido
    if (tamano == 0) return 0;  // Si el tamaño del arreglo es 0, no hay elementos, retorna 0

    int k = 1;  // Contador para el nuevo tamaño sin duplicados
    for (int i = 1; i < tamano; i++) {  // Comienza un ciclo desde el segundo elemento
        if (nums[i] != nums[i - 1]) {  // Si el valor actual es diferente al anterior
            nums[k] = nums[i];  // Mueve el valor actual a la nueva posición sin duplicados
            k++;  // Incrementa el índice para el próximo valor único
        }
    }
    return k;  // Devuelve el nuevo tamaño del arreglo sin duplicados
}

int main() {
    int tamano = TAMANO;  // Definir el tamaño del arreglo en la función principal
    
    // Imprime el arreglo original
    printf("Arreglo original: ");
    for (int i = 0; i < tamano; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNumero de elementos en k en el arreglo original: %d\n", tamano);
    
    // Llama a la función remover y obtiene el nuevo tamaño
    int k = remover();  
    // Imprime el arreglo sin duplicados
    printf("Arreglo sin duplicados: ");
    for (int i = 0; i < k; i++) {  // Imprime el arreglo sin duplicados
        printf("%d ", nums[i]);
    }
    printf("\nNumero de elementos en k: %d\n", k);

    return 0;  // Retorna 0 para indicar que el programa terminó correctamente
}