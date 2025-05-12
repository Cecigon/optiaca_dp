// Cecilia Gómez Jiménez - Proyecto final de Matemáticas Discretas
// Optimización del tiempo de estudio mediante programación dinámica
// Basado en el problema clásico de mochila 0-1 con enfoque personalizado al entorno académico estudiantil
// Referencias: [3] GeeksforGeeks, [4] BaseMax GitHub, [6] CS 161 Stanford - Lecture 12

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función auxiliar para obtener el máximo de dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Implementación con programación dinámica usando tabulación (bottom-up)
// Esta implementación sigue la estructura clásica descrita en [3] y adaptada por [4] para C
// Justificación teórica: según [6], almacenar los resultados intermedios evita recomputación innecesaria
int mochilaDP(int horas[], int beneficios[], int n, int tiempoDisponible) {
    int dp[n + 1][tiempoDisponible + 1];
// Construcción de la tabla dp siguiendo la estrategia de tabulación descrita en [3]
    for (int i = 0; i <= n; i++) {
        for (int t = 0; t <= tiempoDisponible; t++) {
            if (i == 0 || t == 0)
                dp[i][t] = 0; // Caso base: sin materias o sin tiempo, beneficio es 0
            else if (horas[i - 1] <= t)
                dp[i][t] = max(beneficios[i - 1] + dp[i - 1][t - horas[i - 1]], dp[i - 1][t]);
             // Se elige el máximo entre estudiar o no estudiar la materia i-1
            else
                dp[i][t] = dp[i - 1][t];
             // Si no cabe, se conserva el valor anterior
        }
    }
// Resultado final según [6]: solución óptima se encuentra en dp[n][tiempoDisponible]
    return dp[n][tiempoDisponible];
}

int main() {
    int n, tiempoDisponible;
    printf("¿Cuántas materias tienes? ");
    scanf("%d", &n);

    char materias[n][30];
    int horas[n];
    int beneficios[n];

    // Entrada interactiva por parte del usuario
    for (int i = 0; i < n; i++) {
        printf("Nombre de la materia %d: ", i + 1);
        scanf(" %s", materias[i]);
        printf("Horas necesarias para %s: ", materias[i]);
        scanf("%d", &horas[i]);
        printf("Beneficio académico de %s (1-10): ", materias[i]);
        scanf("%d", &beneficios[i]);
    }

    printf("¿Cuántas horas en total tienes disponibles para estudiar? ");
    scanf("%d", &tiempoDisponible);

    
 // Llamado a la función con PD basada en referencias [3], [4], [6]
    int resultado = mochilaDP(horas, beneficios, n, tiempoDisponible);
    printf("\nEl beneficio máximo posible es: %d\n", resultado);

    return 0;
}
