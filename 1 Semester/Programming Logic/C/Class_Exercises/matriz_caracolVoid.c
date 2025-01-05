// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//FUNCIONES
void generarMatrizCaracol(int n, int x, int M[n + 1][n + 1]) {
    int a, i;
    for (a = 1; a <= n / 2; a++) {
        for (i = a; i <= n - a; i++) {
            M[a][i] = x;
            x++;
        }
        for (i = a; i <= n - a; i++) {
            M[i][n - a + 1] = x;
            x++;
        }
        for (i = n - a + 1; i >= a + 1; i--) {
            M[n - a + 1][i] = x;
            x++;
        }
        for (i = n - a + 1; i >= a + 1; i--) {
            M[i][a] = x;
            x++;
        }
    }
    if (n % 2 == 1) {
        M[n / 2 + 1][n / 2 + 1] = x;
    }
}

//MAIN
int main() {
    int n = 5, x = 1, i, j;
    int M[n + 1][n + 1];
    generarMatrizCaracol(n, x, M);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}

