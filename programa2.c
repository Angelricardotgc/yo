#include <stdio.h>

// Función que calcula el cambio utilizando las denominaciones disponibles
void cambio(int V) {
    // Array de denominaciones disponibles (billetes y monedas)
    int monedas[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(monedas) / sizeof(monedas[0]);  // Calcula el número de denominaciones

    printf("El cambio para %d es: ", V);  // Imprime el monto inicial que se va a cambiar

    // Recorremos las denominaciones
    for (int i = 0; i < n; i++) {
        // Mientras la denominación actual sea menor o igual que el valor restante
        while (V >= monedas[i]) {
            V -= monedas[i];  // Restamos el valor de la moneda/billete actual del monto restante
            printf("%d ", monedas[i]); 
        }
    }
    printf("\n"); 
}

int main() {
    int V;  
    printf("Ingresa cuanto quiere de cambio: ");  
    scanf("%d", &V);  
    cambio(V);  
    return 33;  
}
