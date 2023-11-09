#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define plus_inf 2000000
#define minus_inf -2000000
using namespace std;

int existPath(int **G, int n, int a, int b) {
	int *visited = (int*)calloc(n, sizeof(int));
	visited[a] = 1;
	queue < int > Q;
	Q.push(a);
	
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for(int v = 0; v < n; v++) {
			if(G[u][v] != minus_inf) {
				if(visited[v] == 0) {
					visited[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	
	if(visited[b] == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Bellman_Ford(int **G, int *distance, int n, int start) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(G[i][j] != minus_inf) {
				if(distance[j] > distance[i] + G[i][j]) {
					distance[j] = distance[i] + G[i][j];
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(G[i][j] != minus_inf) {
				if(distance[i] + G[i][j] < distance[j] && existPath(G, n, start, i) == 1) {
					return 1;
				}
			}
		}
	}
	
	return 0;
}

int main() {
	int n = 0;
	int k = 0;
	int start = 0;
	int end = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &start);
	scanf("%d", &end);
	
	int **G = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++) {
		G[i] = (int*)malloc(n * sizeof(int));
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			G[i][j] = minus_inf;
		}
	}
	
	for(int i = 0; i < k; i++) {
		int x = 0;
		int y = 0;
		int v = 0;
		scanf("%d", &x);
		scanf("%d", &y);
		scanf("%d", &v);
		G[x][y] = v;
	}

	int *distance = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		distance[i] = plus_inf;
	}
	distance[start] = 0;	
	
	if(Bellman_Ford(G, distance, n, start) == 1) {
		printf("CYCLE\n");
	} else {
		if(distance[end] == plus_inf) {
			printf("NO\n");
		} else {
			printf("%d", distance[end]);
		}
	}
	
	return 0;
}
