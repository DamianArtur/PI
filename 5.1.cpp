#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n = 0;
	int k = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	int *tab = (int*)malloc(n * sizeof(int*));

	int p = 0;
	n += (n-1);
	for(int i = 0; i < n; i++) {
		char str[k];
		scanf("%s", &str);
		
		if(strcmp(str, "+") == 0) {
			tab[p-2] = tab[p-2] + tab[p-1];
			p--;
		} else if(strcmp(str, "-") == 0) {
			tab[p-2] = tab[p-2] - tab[p-1];
			p--;
		} else if(strcmp(str, "*") == 0) {
			tab[p-2] = tab[p-2] * tab[p-1];
			p--;
		} else if(strcmp(str, "/") == 0) {
			tab[p-2] = tab[p-2] / tab[p-1];
			p--;
		} else {
			tab[p] = atoi(str);
			p++;
		}
	}
	
	printf("%d", tab[0]);
	return 0;
}
