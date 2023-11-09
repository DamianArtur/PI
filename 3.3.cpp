#include <stdio.h>
#include <math.h>

int czyPierwsza(int n) {
	if (n <= 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	int i = 5;
	while(i <= sqrt(n)) {
		if (n % i == 0)
			return 0;
		i += 2;
		if (n % i == 0)
			return 0;
		i += 4;
	}
	return 1;
}

int czyRosnaca(int n) {
	int wynik = 1;
	int last = 9;
	while(n > 0) {
		if(n % 10 > last) {
			wynik = 0;
			break;
		}
		last = n % 10;
		n /= 10;
	}
	return wynik;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	for(int i = 2; i < n; i++) {
		if(czyRosnaca(i) == 1 && czyPierwsza(i) == 1) printf("%d\n", i);
	}
	return 0;
}
