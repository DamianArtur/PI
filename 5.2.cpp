#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main() {
	int n = 0;
	int k = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	
	int **tab = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++) {
		tab[i] = (int*)calloc(n, sizeof(int));
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &tab[i][j]);
		}
	}
	
	int start = 0;
	int end = 0;
	int kolejka[N][3];
	
	for(int i = 0; i < k; i++) {
		scanf("%d", &kolejka[end][0]);
		scanf("%d", &kolejka[end][1]);
		scanf("%d", &kolejka[end][2]);
		end++;
	} 
	
	while(start != end) {
		int x = kolejka[start][0];
		int y = kolejka[start][1];
		int c = kolejka[start][2];
		//wyciagam element z kolejki i wykonuje
		tab[x][y] = c;
		//dodaje nowy element do kolejki
		if(x-1 >= 0 && tab[x-1][y] == 0) {
			kolejka[end][0] = x-1;
			kolejka[end][1] = y;
			kolejka[end][2] = c;
			end = (end + 1) % N;
		}
		if(x+1 < n && tab[x+1][y] == 0) {
			kolejka[end][0] = x+1;
			kolejka[end][1] = y;
			kolejka[end][2] = c;
			end = (end + 1) % N;
		}
		if(y-1 >= 0 && tab[x][y-1] == 0) {
			kolejka[end][0] = x;
			kolejka[end][1] = y-1;
			kolejka[end][2] = c;
			end = (end + 1) % N;
		}
		if(y+1 < n && tab[x][y+1] == 0) {
			kolejka[end][0] = x;
			kolejka[end][1] = y+1;
			kolejka[end][2] = c;
			end = (end + 1) % N;
		}
		start = (start + 1) % N;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
