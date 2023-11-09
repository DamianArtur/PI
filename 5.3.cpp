#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	scanf("%d", &n);
	
	int start = 0;
	int end = 0;
	
	char ***kolejka = (char***)malloc(n * sizeof(char**));
		for(int i = 0; i < n; i++) {
			kolejka[i] = (char**)malloc(6 * sizeof(char*));
			for(int j = 0; j < 6; j++) {
				kolejka[i][j] = (char*)calloc(17, sizeof(char));
			}
		}
	
	for(int i = 0; i < n; i++) {
		char ch;
		scanf(" %c", &ch);
		
		if(ch == 'a') {
			scanf("%s", *&kolejka[end][0]);
			scanf("%s", *&kolejka[end][1]);
			end++;
		} else {
			int t = 0;
			scanf("%d", &t);
			int czas = t - atoi(kolejka[start][0]);
			printf("%s %d\n", kolejka[start][1], czas);
			start++;
		}
	}
		
	return 0;
}
