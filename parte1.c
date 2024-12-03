#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Definición de la estructura punto para representar coordenadas en 2D
typedef struct{
    double x;
    double y;
}punto;

// Función que genera un punto aleatorio dentro de un rango de -100 a 100 para ambas coordenadas
punto generar(){
    punto p;
    p.x = ((double)rand() / RAND_MAX) * 200 - 100;  // Genera un valor aleatorio para la coordenada x
    p.y = ((double)rand() / RAND_MAX) * 200 - 100;  // Genera un valor aleatorio para la coordenada y
    return p;  // Devuelve el punto generado
}

// Función que calcula la distancia euclidiana entre dos puntos p1 y p2
double distancia(punto p1, punto p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));  // Calcula y devuelve la distancia entre los dos puntos
}

// Función que busca los dos puntos más cercanos en el arreglo de puntos
void puntocer(punto* puntos, int n, punto* p1, punto* p2, double* dismin){
    *dismin = distancia(puntos[0], puntos[1]);  // Inicializa la distancia mínima con la distancia entre los dos primeros puntos
    *p1 = puntos[0];  // Asigna el primer punto a p1
    *p2 = puntos[1];  // Asigna el segundo punto a p2
    for(int i = 0; i < n-1; i++){  // Recorre todos los puntos
        for(int j = i + 1; j < n; j++){  // Compara cada par de puntos solo una vez
            double dis = distancia(puntos[i], puntos[j]);  // Calcula la distancia entre los dos puntos
            if(dis < *dismin){  // Si la distancia calculada es menor que la mínima actual
                *dismin = dis;  // Actualiza la distancia mínima
                *p1 = puntos[i];  // Actualiza el primer punto más cercano
                *p2 = puntos[j];  // Actualiza el segundo punto más cercano
            }
        }
    }
}

int main(){
    // Define diferentes tamaños de arreglos para probar
    int n[] = {10, 100, 1000, 10000, 100000};
    srand(time(NULL));  // Inicializa la semilla para los números aleatorios usando el tiempo actual
    
    // Repite el proceso para cada tamaño de arreglo en n[]
    for (int k = 0; k < 5; k++) {  
        printf("n = %d\n", n[k]);  // Imprime el tamaño de puntos que se va a procesar
        punto* puntos = (punto*)malloc(n[k] * sizeof(punto));  // Reserva memoria para el arreglo de puntos
        for (int i = 0; i < n[k]; i++) {
            puntos[i] = generar();  // Genera puntos aleatorios y los almacena en el arreglo
        }

        punto p1, p2; 
        double dismin; 
        clock_t inicio = clock();  // Registra el tiempo de inicio
        puntocer(puntos, n[k], &p1, &p2, &dismin);  // Llama a la función para encontrar los puntos más cercanos
        clock_t fin = clock();  // Registra el tiempo de fin
        double tiempoeje = (double)(fin - inicio) / CLOCKS_PER_SEC;  // Calcula el tiempo de ejecución en segundos
        printf("Los puntos más cercanos son: (%.2f, %.2f) y (%.2f, %.2f)\n", p1.x, p1.y, p2.x, p2.y);  
        printf("Distancia mínima: %.6f\n", dismin); 
        printf("Tiempo de ejecución: %.6f segundos\n\n", tiempoeje);  
        
        free(puntos); 
    }
    return 33; 
}
