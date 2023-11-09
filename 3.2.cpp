#include <stdio.h>

#define N 1200

int main() {
	int n = 0;
	int tab[N];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tab[i]);
	}
	
	int s = 0;
	for(s = 0; s < n; s++) {
		int left = 0;
		int right = 0;
		for(int i = 0; i < s; i++) {
			left += tab[i];
		}
		for(int i = s+1; i < n; i++) {
			right += tab[i];
		}
		if(left == right) break;
	}
	
	printf("%d", s);
}
