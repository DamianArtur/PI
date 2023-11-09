#include <stdio.h>
#include <stdlib.h>

int parent(int i) {
	return i / 2;
}

int left(int i) {
	return i * 2;
}

int right(int i) {
	return i * 2 + 1;
}

void heapify(int k[], int i) {
	int l = left(i);
	int r = right(i);
	int maks = i;
	if(l <= k[0] && k[l] > k[maks]) {
		maks = l;
	}
	if(r <= k[0] && k[r] > k[maks]) {
		maks = r;
	}
	if(maks != i) {
		int tmp = k[i];
		k[i] = k[maks];
		k[maks] = tmp;
		heapify(k, maks);
	}
}

void buildHeap(int k[]) {
	for(int i = k[0] / 2; i > 0; i--) {
		heapify(k, i);
	}
}

void heapSort(int k[]) {
	buildHeap(k);
	for(int i = k[0]; i > 1; i--) {
		int tmp = k[i];
		k[i] = k[1];
		k[1] = tmp;
		k[0]--;
		heapify(k, 1);
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
		tab = (int*)malloc((n+1) * sizeof(int));
		tab[0] = n;
		for(int j = 0; j < n; j++) {
			scanf("%d", &tab[j+1]);
		}
		heapSort(tab);
		wyniki = (int*)realloc(wyniki, (size + n) * sizeof(int));
		for(int j = 0; j < n; j++) {
			wyniki[size+j] = tab[j+1];
		}
		size += n;
		free(tab);
	}
	
	for(int i = 0; i < size; i++) {
		printf("%d\n", wyniki[i]);
	}
	return 0;
}
