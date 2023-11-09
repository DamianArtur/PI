#include <stdio.h>
#include <stdlib.h>

int game(int **arr, int n, int x1, int y1, int x2, int y2) {
	if(x1 == x2 && y1 == y2) {
		return 1;
	}
	
	int result = 0;
	
	if(x1+1 < n && arr[x1+1][y1] == 1) {
		result += game(arr, n, x1+1, y1, x2, y2);
	}
	if(y1+1 < n && arr[x1][y1+1] == 1) {
		result += game(arr, n, x1, y1+1, x2, y2);
	}
	if(x1+1 < n && y1+1 < n && arr[x1+1][y1+1] == 1) {
		result += game(arr, n, x1+1, y1+1, x2, y2);
	}
	
	return result;
}

int main() {
	int n, x1, y1, x2, y2 = 0;
	scanf("%d", &n);
	scanf("%d", &x1);
	scanf("%d", &y1);
	scanf("%d", &x2);
	scanf("%d", &y2);
	
	int **arr = (int**)malloc(n * sizeof(int*));
	for(int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(n * sizeof(int));
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	printf("%d", game(arr, n, x1, y1, x2, y2));
	
	return 0;
}
