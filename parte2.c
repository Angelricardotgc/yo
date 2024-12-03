#include <stdio.h>
#include <float.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Estructura para representar un punto
typedef struct {
    int x, y;
} Point;

// Estructura para representar el par de puntos más cercanos
typedef struct {
    Point p1, p2;
    float distancia;
} ParMinimo;

// Función para comparar los puntos según la coordenada X
int compareX(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);  // Devuelve la diferencia entre las coordenadas X
}

// Función para comparar los puntos según la coordenada Y
int compareY(const void* a, const void* b) {
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);  // Devuelve la diferencia entre las coordenadas Y
}

// Función para calcular la distancia entre dos puntos
float dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));  // Distancia Euclidiana
}

// Función que encuentra el par más cercano utilizando fuerza bruta
ParMinimo bruteForce(Point P[], int n) {
    ParMinimo minPar;
    minPar.distancia = FLT_MAX;  // Inicializa la distancia mínima con el valor máximo posible

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            float distancia_actual = dist(P[i], P[j]);  // Calcula la distancia entre los puntos
            if (distancia_actual < minPar.distancia) {  // Si la distancia es menor que la actual mínima
                minPar.distancia = distancia_actual;  // Actualiza la distancia mínima
                minPar.p1 = P[i];  // Asigna los puntos más cercanos
                minPar.p2 = P[j];
            }
        }
    }

    return minPar;  // Devuelve el par de puntos más cercanos
}

// Encuentra la distancia mínima en una lista de puntos ordenados por la coordenada Y
ParMinimo stripClosest(Point strip[], int size, float d, ParMinimo minPar) {
    qsort(strip, size, sizeof(Point), compareY);  // Ordena los puntos por Y

    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minPar.distancia; ++j) {
            float distancia_actual = dist(strip[i], strip[j]);  // Calcula la distancia entre los puntos
            if (distancia_actual < minPar.distancia) {  // Si la distancia es menor que la mínima actual
                minPar.distancia = distancia_actual;  // Actualiza la distancia mínima
                minPar.p1 = strip[i];  // Asigna los puntos más cercanos
                minPar.p2 = strip[j];
            }
        }
    }

    return minPar;  // Devuelve el par más cercano
}

// Una función recursiva para encontrar el par más cercano
ParMinimo closestUtil(Point P[], int n) {
    // Si hay menos de 3 puntos, usamos la fuerza bruta
    if (n <= 3)
        return bruteForce(P, n);

    // Encuentra el punto medio
    int mid = n / 2;
    Point midPoint = P[mid];

    // Divide en dos subarrays
    ParMinimo minIzq = closestUtil(P, mid);
    ParMinimo minDer = closestUtil(P + mid, n - mid);

    // Encuentra el par con la menor distancia
    ParMinimo minPar = (minIzq.distancia < minDer.distancia) ? minIzq : minDer;

    // Construye el arreglo de puntos en la franja
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < minPar.distancia)  // Si el punto está en la franja
            strip[j++] = P[i];

    // Encuentra el par más cercano en la franja
    return stripClosest(strip, j, minPar.distancia, minPar);
}

// La función principal que encuentra el par de puntos más cercanos
ParMinimo closest(Point P[], int n) {
    qsort(P, n, sizeof(Point), compareX);  // Ordena los puntos según X
    return closestUtil(P, n);  // Llama a la función recursiva para encontrar el par más cercano
}

// Función para generar puntos aleatorios
void generar_puntos_aleatorios(Point* P, int n) {
    for (int i = 0; i < n; i++) {
        P[i].x = rand() % 200 - 100;  // Genera un número aleatorio en el rango [-100, 100]
        P[i].y = rand() % 200 - 100;  // Genera un número aleatorio en el rango [-100, 100]
    }
}

int main() {
    srand(time(NULL)); // Inicializa la semilla para números aleatorios

    // Definición de los valores de n
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        Point* P = malloc(n * sizeof(Point)); // Reserva memoria para los puntos
        if (P == NULL) {
            fprintf(stderr, "Error al asignar memoria\n");
            return 1;
        }

        generar_puntos_aleatorios(P, n); // Genera los puntos aleatorios

        clock_t start = clock(); // Inicia el temporizador
        ParMinimo minPar = closest(P, n); // Llama a la función para encontrar el par más cercano
        clock_t end = clock(); // Finaliza el temporizador

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Calcula el tiempo de ejecución
        printf("Para n=%d: La distancia más corta es %.6f entre los puntos (%d, %d) y (%d, %d) | Tiempo de ejecución: %.6f segundos\n", 
                n, minPar.distancia, minPar.p1.x, minPar.p1.y, minPar.p2.x, minPar.p2.y, time_taken);

        free(P); // Libera la memoria asignada
    }

    return 0;
}
