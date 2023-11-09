#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 101

int przesun(int z, int s) {
	if(z == 32) return z;
	while(s > 0) {
		z++;
		if(z == 91 || z == 123)
			z -= 26;
		s--;
	}
	return z;
}

void encrypt(char* message) {
	int b_wiodace = 1;
	int wiodace = 0;
	int s = 0;
	while((message[s] >= 65 && message[s] <= 90) || (message[s] >= 97 && message[s] <= 122) || b_wiodace == 1) { 
		if(message[s] == 32) {
			wiodace++;
		} else {
			b_wiodace = 0;
		}
		s++;
	}
	s -= wiodace;
	
	int i = 0;
	while((message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122) || message[i] == 32) {
		message[i] = przesun(message[i], s);
		i++;
	}
}

int main() {
	char message[N];
	fgets(message, N, stdin);
	encrypt(message);
	printf("%s\n", message);
}

