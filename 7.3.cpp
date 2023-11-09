#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define inf 2000000
using namespace std;

struct Node {
	int number;
	int distance;
};

bool operator<(const Node& a, const Node& b) {
	return a.distance > b.distance;
}

int Dijkstra(int **G, int n, int start, int end) {
	int *processed = (int*)calloc(n, sizeof(int));
	int *distance = (int*)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++) {
		distance[i] = inf;
	}
	distance[start] = 0;
	priority_queue < Node > queue;
	for(int i = 0; i < n; i++) {
		struct Node N;
		N.number = i;
		N.distance = distance[i];
		queue.push(N);
	}
	
	while(!queue.empty()) {
		struct Node u = queue.top();
		queue.pop();
		if(processed[u.number] == 0) {
			for(int i = 0; i < n; i++) {
				if(G[u.number][i] != inf) {
					if(distance[i] > distance[u.number] + G[u.number][i]) {
						distance[i] = distance[u.number] + G[u.number][i];
						struct Node M;
						M.number = i;
						M.distance = distance[i];
						queue.push(M);
					}
				}
			}
		}
		processed[u.number] = 1;
	}
	
	return distance[end];
}

int main() {
	int t = 0;
	int n = 0;
	int k = 0;
	scanf("%d", &t);
	scanf("%d", &n);
	scanf("%d", &k);
	
	int **G = (int**)malloc(t * sizeof(int*));
	for(int i = 0; i < t; i++) {
		G[i] = (int*)calloc(t, sizeof(int));
	}
	
	for(int i = 0; i < t; i++) {
		for(int j = 0; j < t; j++) {
			G[i][j] = inf;
		}
	}
	
	for(int i = 0; i < n; i++) {
		int stacje = 0;
		scanf("%d", &stacje);
		int *tab = (int*)calloc(2*stacje-1, sizeof(int));
		for(int j = 0; j < 2*stacje-1; j++) {
			scanf("%d", &tab[j]);
		}
	
		for(int j = 1; j < 2*stacje-1; j+=2) {
			if(tab[j] < G[tab[j-1]][tab[j+1]]) {
				G[tab[j-1]][tab[j+1]] = tab[j];
				G[tab[j+1]][tab[j-1]] = tab[j];
			}
		}
		free(tab);
	}
	
	for(int i = 0; i < k; i++) {
		int start = 0;
		int end = 0;
		scanf("%d", &start);
		scanf("%d", &end);
		printf("%d\n", Dijkstra(G, t, start, end));
	}
	
	return 0;
}
