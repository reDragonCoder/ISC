// Author: reDragonCoder

//LIBRERIAS
#include <stdio.h>

//MAIN
int main() {
    /*we declare the size of the matrix, stating that n MUST be 5*/
    int n = 5, x = 1, i, j, a;
    int M[n + 1][n + 1];
    for (a = 1; a <= n / 2; a++) {/*main cycle*/
        for (i = a; i <= n - a; i++) {/*first cycle*/
            M[a][i] = x;
            x++;
        }
        for (i = a; i <= n - a; i++) {/*second cycle*/
            M[i][n - a + 1] = x;
            x++;
        }
        for (i = n - a + 1; i >= a + 1; i--) {/*third cycle*/
            M[n - a + 1][i] = x;
            x++;
        }
        for (i = n - a + 1; i >= a + 1; i--) {/*fourth cycle*/
            M[i][a] = x;
            x++;
        }
    }
    if (n % 2 == 1) {
        M[n / 2 + 1][n / 2 + 1] = x;
    }
    for (i = 1; i <= n; i++) {/*print matrix*/
        for (j = 1; j <= n; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}

