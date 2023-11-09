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

int minimum_way(int **G, int n, int start, int end) {
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
				if(G[u.number][i] != -1) {
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
	int n = 0;
	int k = 0;
	int s = 0;
	int e = 0;
	
	scanf("%d", &n);
	scanf("%d", &k);
	scanf("%d", &s);
	scanf("%d", &e);
	
	int **G = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++) {
		G[i] = (int*)calloc(n, sizeof(int));
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			G[i][j] = -1;
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
		G[y][x] = v;
	}
	
	int result = minimum_way(G, n, s, e);
	printf("%d", result);
	
	return 0;
}
