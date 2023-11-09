#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

void kolo(double r, double* w1, double* w2) {
	*w1 = M_PI * r * r;
	*w2 = 2 * M_PI * r;
}

void zamien(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int rownanie(double* x, double* y, double* z) {
	if(*x * *x + *y * *y <= 1) {
		*z = *x * *x + *y;
		return 1;
	}

	if (*y > *x + 5) {
		*z = 2 * *x + *y * *y;
		return 2;
	}

	*z = (1. / 2) * *x * *x + *y;
	return 3;
}

int suma_rec(int n) {
	if (n > 1)
		return n + suma_rec(n - 1);
	return 1;
}

void hanoi(int N, char A, char B, char C) {
	if (N == 1) {
		printf("%c ----> %c \n", A, B);
		return;
	}

	hanoi(N - 1, A, C, B);
	printf("%c ----> %c \n", A, B);
	hanoi(N - 1, C, B, A);
}

void zad9() {
	double r, pole, obwod;
	int ret = -1;

	printf("Liczenie pola i obwodu kola \n");
	printf("-------------------------- \n");
	printf("Podaj promien kola: ");
	ret = scanf("%lf", &r);
	if (ret != 1) {
		printf("Blad wczytywania. \n");
		printf("-------------------------- \n\n\n");
		return;
	}

	if (r < 0) {
		printf("Promien kola nie moze byc ujemny. \n");
		printf("-------------------------- \n\n\n");
		return;		
	}

	kolo(r, &pole, &obwod);
	printf("Pole kola wynosi %lf, obwod kola wynosi %lf \n", pole, obwod);

	printf("-------------------------- \n");
	printf("\n\n");
}

void zad10() {
	int x, y;
	int ret = -1;

	printf("Funkcja zamieniania na wskaznikach \n");
	printf("-------------------------- \n");
	printf("Podaj dwie liczby calkowite: \n");
	ret = scanf("%d%d", &x, &y);
	if (ret != 2) {
		printf("Blad wczytywania. \n");
		printf("-------------------------- \n\n\n");
	}

	printf("Przed zamiana: \n");
	printf("x = %d; y = %d \n", x, y);

	zamien(&x, &y);

	printf("Po zamianie: \n");
	printf("x = %d; y = %d \n", x, y);

	printf("-------------------------- \n");
	printf("\n\n");
}

void zad11() {
	double x, y, z;
	int nr_rownania;
	int ret = -1;
	
	printf("Liczenie wartosci liczby z \n");
	printf("-------------------------- \n");
	printf("Podaj x i y: ");
	ret = scanf("%lf%lf", &x, &y);
	if (ret != 2) {
		printf("Blad wczytywania. \n");
		printf("-------------------------- \n\n\n");
		return;
	}

	nr_rownania = rownanie(&x, &y, &z);
	printf("z = %lf, obliczono rownaniem nr %d \n", z, nr_rownania);

	printf("-------------------------- \n");
	printf("\n\n");
}

void zad12() {
	int n;
	int ret = -1;

	printf("Obliczanie sumy liczb naturalnych od 1 do n \n");
	printf("-------------------------- \n");
	printf("Podaj liczbe n: ");
	ret = scanf("%d", &n);
	if (ret != 1) {
		printf("Blad wczytywania. \n");
		printf("-------------------------- \n\n\n");
		return;
	}

	if (n < 1) {
		printf("Liczba powinna byc wieksza od 0. \n");
		printf("-------------------------- \n\n\n");
		return;
	}

	printf("Suma od 1 do n: %d \n", suma_rec(n));
	printf("-------------------------- \n");
	printf("\n\n");
}

void zad13() {
	int n;
	int ret = -1;
	
	printf("Wieze Hanoi \n");
	printf("-------------------------- \n");
	printf("Podaj liczbe krazkow: \n");
	ret = scanf("%d", &n);
	if (ret != 1) {
		printf("Blad wczytywania. \n");
		printf("-------------------------- \n\n\n");
		return;
	}
	if (n < 1) {
		printf("Liczba krazkow powinna wynosic przynajmniej 1. \n");
		printf("-------------------------- \n\n\n");
		return;
	}

	hanoi(n, 'A', 'B', 'C');

	printf("-------------------------- \n");
	printf("\n\n");
}

int main(int argc, char* argv[]) {
	zad9();
	zad10();
	zad11();
	zad12();
	zad13();

	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;

	return 0;
}