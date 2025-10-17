/* prueba.c
    Programa de matriz en C sin funciones (todo en main)
    - Lee dimensiones y elementos
    - Muestra la matriz
    - Muestra la transpuesta
    - Calcula suma total, suma por fila y por columna
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
     const int MAX = 100;
     int filas, cols;
     int matriz[MAX][MAX];
     int i, j;

     printf("Ingrese numero de filas (1-%d): ", MAX);
     if (scanf("%d", &filas) != 1 || filas < 1 || filas > MAX) {
          printf("Dimension de filas invalida.\n");
          return 1;
     }
     printf("Ingrese numero de columnas (1-%d): ", MAX);
     if (scanf("%d", &cols) != 1 || cols < 1 || cols > MAX) {
          printf("Dimension de columnas invalida.\n");
          return 1;
     }

     printf("Ingrese los elementos de la matriz (%d x %d):\n", filas, cols);
     for (i = 0; i < filas; ++i) {
          for (j = 0; j < cols; ++j) {
                printf("Elemento [%d][%d]: ", i, j);
                if (scanf("%d", &matriz[i][j]) != 1) {
                     printf("Entrada invalida.\n");
                     return 1;
                }
          }
     }

     printf("\nMatriz ingresada:\n");
     for (i = 0; i < filas; ++i) {
          for (j = 0; j < cols; ++j) {
                printf("%6d", matriz[i][j]);
          }
          printf("\n");
     }

     /* Transpuesta */
     printf("\nTranspuesta (%d x %d):\n", cols, filas);
     for (j = 0; j < cols; ++j) {
          for (i = 0; i < filas; ++i) {
                printf("%6d", matriz[i][j]);
          }
          printf("\n");
     }

     /* Sumas */
     int sumaTotal = 0;
     printf("\nSuma por fila:\n");
     for (i = 0; i < filas; ++i) {
          int sumaFila = 0;
          for (j = 0; j < cols; ++j) sumaFila += matriz[i][j];
          printf("Fila %d: %d\n", i, sumaFila);
          sumaTotal += sumaFila;
     }

     printf("\nSuma por columna:\n");
     for (j = 0; j < cols; ++j) {
          int sumaCol = 0;
          for (i = 0; i < filas; ++i) sumaCol += matriz[i][j];
          printf("Columna %d: %d\n", j, sumaCol);
     }

     printf("\nSuma total de elementos: %d\n", sumaTotal);

     return 0;
}