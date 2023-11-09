#include <stdio.h>
#include <stdlib.h>

#define N 1000

int check(int **tab, int n, int a, int b) {
	int *visited = (int*)calloc(n, sizeof(int));
	visited[a] = 1;
	
	int Queue[N];
	int start = 0;
	int length = 0;
	
	Queue[0] = a;
	length++;
	
	while(length != 0) {
		int u = Queue[start];
		start = (start + 1) % N;
		length--;
		
		for(int v = 0; v < n; v++) {
			if(tab[u][v] == 1) {
				if(v == b) {
					return 1;
				}
				if(visited[v] == 0) {
					visited[v] = 1;
					
					Queue[(start+length) % N] = v;
					length++;
				}
			}
		}
	}
	
	return 0;
}

int main() {
	int n = 0;
	int k = 0;
	int p = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &p);
	
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
		tab[b][a] = 1;
	}
	
	for(int i = 0; i < p; i++) {
		int a = 0;
		int b = 0;
		scanf("%d", &a);
		scanf("%d", &b);
		if(check(tab, n, a, b) == 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;	
}
