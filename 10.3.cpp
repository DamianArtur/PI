#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 210

int minimum(int a, int b, int c) {
	if(a <= b && a <= c) {
		return a;
	} else if(b <= a && b <= c) {
		return b;
	} else {
		return c;
	}
}

int distance(char *str1, char *str2) {
	int m = strlen(str1) - 1;
	int n = strlen(str2) - 1;
	
	if(m == 0) {
		return n;
	}
	if(n == 0) {
		return m;
	}
	
	int **arr = (int**)malloc((m+1) * sizeof(int*));
	for(int i = 0; i < m+1; i++) {
		arr[i] = (int*)calloc(n+1, sizeof(int));
	}
	
	
	for(int i = 1; i <= m; i++) {
		arr[i][0] = i;
	}
	for(int j = 1; j <= n; j++) {
		arr[0][j] = j;
	}
	
	int cost;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(str1[i-1] == str2[j-1]) {
				cost = 0;
			} else {
				cost = 1;
			}
			
			arr[i][j] = minimum(arr[i-1][j] + 1, arr[i][j-1] + 1, arr[i-1][j-1] + cost);
		}
	}
	
	return arr[m][n];
}

int main() {
	char str1[N];
	char str2[N];
	
	fgets(str1, N, stdin);
	fgets(str2, N, stdin);
	
	printf("%d", distance(str1, str2));
	
	return 0;
}
