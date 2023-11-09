#include <stdio.h>
#include <stdlib.h>

void countingSort(int **tab, int n, int k, int p) {
    int **output = (int**)malloc(n * sizeof(int*));
    int *klucze = (int*)calloc(10, sizeof(int));
    int i;

    for(i = 0; i < n; i++) {
        klucze[tab[i][p]]++;
    }

    for(i = 1; i < 10; i++) {
        klucze[i] += klucze[i-1];
    }

    for(i = n-1; i >= 0; i--) {
        output[klucze[tab[i][p]] - 1] = tab[i];
        klucze[tab[i][p]]--;
    }

    for(i = 0; i < n; i++) {
        tab[i] = output[i];
    }

    free(klucze);
    free(output);
}

void radixSort(int **tab, int n, int k) {
    for(int i = k - 1; i >= 0; i--) {
        countingSort(tab, n, k, i);
    }
}

int main() {
    int z = 0;
    scanf("%d", &z);

    for(int i = 0; i < z; i++) {
        int n = 0;
        int k = 0;
        scanf("%d", &n);
        scanf("%d", &k);

        int** tab = (int**)malloc(n * sizeof(int*));
        for(int j = 0; j < n; j++) {
            tab[j] = (int*)calloc(k, sizeof(int));
            for(int m = 0; m < k; m++) {
                scanf("%1d", &tab[j][m]);
            }
        }

        radixSort(tab, n, k);

        for (int j = 0; j < n; j++) {
            for (int m = 0; m < k; m++) {
                printf("%1d", tab[j][m]);
            }
            free(tab[j]);
            printf("\n");
        }

        free(tab);
    }

    return 0;
}
