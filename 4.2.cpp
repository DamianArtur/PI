#include <stdio.h>
#include <stdlib.h>

int partition(int tab[], int p, int k) {
	int s = tab[k];
	int i = p - 1;
	
	for(int j = p; j <= k - 1; j++) {
		if(tab[j] < s) {
			i++;
			int tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
	}
	
	int tmp = tab[i+1];
	tab[i+1] = tab[k];
	tab[k] = tmp;
	
	return i + 1;
} 

quickSort(int tab[], int p, int k) {
	if(p < k) {
		int s = partition(tab, p, k);
		quickSort(tab, p, s-1);
		quickSort(tab, s+1, k);
	}
}

int main() {
	int z = 0;
	scanf("%d", &z);
	int *wyniki;
	wyniki = (int*)malloc(0 * sizeof(int));
	int size = 0;
	
	for(int i = 0; i < z; i++) {
		int n = 0;
		int *tab;
		scanf("%d", &n);
		tab = (int*)malloc(n * sizeof(int));
		for(int j = 0; j < n; j++) {
			scanf("%d", &tab[j]);
		}
		quickSort(tab, 0, n-1);
		wyniki = (int*)realloc(wyniki, (size + n) * sizeof(int));
		for(int j = 0; j < n; j++) {
			wyniki[size+j] = tab[j];
		}
		size += n;
		free(tab);
	}
	
	for(int i = 0; i < size; i++) {
		printf("%d\n", wyniki[i]);
	}
	return 0;
}
