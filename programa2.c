#include <stdio.h> 

// Función que calcula y muestra el cambio utilizando las denominaciones disponibles
void cambio(int V) {
    // Arreglo con las denominaciones de monedas y billetes disponibles, de mayor a menor
    int monedas[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    
    // Calculamos el número de denominaciones disponibles
    int n = sizeof(monedas) / sizeof(monedas[0]);
    
    // Imprimimos un mensaje indicando el valor para el cual se calculará el cambio
    printf("El cambio para %d es: ", V);

    // Recorremos las denominaciones de mayor a menor
    for (int i = 0; i < n; i++) {
        // Mientras el valor actual (V) sea mayor o igual a la denominación de la moneda/billete
        while (V >= monedas[i]) {
            V -= monedas[i];  // Restamos el valor de la denominación actual de V
            printf("%d ", monedas[i]);  // Imprimimos la denominación utilizada (billete/moneda)
        }
    }
    
    printf("\n");
}

int main() {
    int V;  // Variable para almacenar el valor para el cual se requiere el cambio

    // Pedimos al usuario que ingrese el valor para el cual quiere el cambio
    printf("Ingresa cuanto quiere de cambio: ");
    
    // Leemos el valor ingresado por el usuario
    scanf("%d", &V);

    // Llamamos a la función cambio para calcular y mostrar el cambio
    cambio(V);

 
    return 33;
}
