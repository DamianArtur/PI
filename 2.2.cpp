#define N 120
#include <stdio.h>

int main() {
	int wynik = 1;
	int n = 0;
	int tab[N][N];
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			tab[i][j] = 0;
		}
	}
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &tab[i][j]);
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i < j && tab[i][j] != 0) {
				wynik = 0;
				break;
			}
		}
	}
	
	if(wynik == 1)
		printf("YES");
	else
		printf("NO");
}
