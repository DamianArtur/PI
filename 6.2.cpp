#include <stdio.h>
#include <stdlib.h>

int isCyclic(int **tab, int n, int *visited, int node) {
	visited[node] = 1;

	for(int i = 0; i < n; i++) {
		if(tab[node][i] == 1) {
			if(visited[i] == 1) {
				return 0;
			} else {
				visited[i] = 1;
				return isCyclic(tab, n, visited, i);
			}
		}
	}
	return 1;
}

int _isCyclic(int **tab, int n) {
	for(int i = 0; i < n; i++) {
		int *visited = (int*)calloc(n, sizeof(int));
		if(isCyclic(tab, n, visited, i) == 0) {
			return 0;
		}
		free(visited);
	}
	return 1;
}

int check(int *tab, int n, int a) {
	for(int i = 0; i < n; i++) {
		if(tab[i] == a) {
			return 1;
		}
	}
	return 0;
}

void findPath(int **tab, int *path, int n) {
	int p = 0;
	while(p < n) {
		for(int j = 0; j < n; j++) {
			int is = 1;
			for(int k = 0; k < n; k++) {
				if(tab[k][j] == 1){
					is = 0;
					break;
				}
			}
			if(is == 1 && check(path, n, j) == 0) {
				path[p] = j;
				p++;
				for(int k = 0; k < n; k++) {
					tab[j][k] = 0;
				}
				break;
			}
		}
	}
}

int main() {
	int n = 0;
	int k = 0;

	scanf("%d", &n);
	scanf("%d", &k);
	
	int **tab = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++) {
		tab[i] = (int*)calloc(n, sizeof(int));
	}
	
	for(int i = 0; i < k; i++) {
		int a = 0;
		int b = 0;
		scanf("%d", &a);
		scanf("%d", &b);
		tab[a][b] = 1;
	}
	
	if(_isCyclic(tab, n) == 0) {
		printf("CYCLE\n");
	} else {
		printf("OK\n");
		int *path = (int*)calloc(n, sizeof(int));
		for(int i = 0; i < n; i++) {
			path[i] = -1;
		}
		findPath(tab, path, n);
		for(int i = 0; i < n; i++) {
			printf("%d ", path[i]);
		}
	}
	
	return 0;
}
