#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void my_exit(int exit_code, int** tab = NULL, int n = 0) {
	if (tab) {
		for (int i = 0; i < n; i++) {
			if (tab[i]) {
				free(tab[i]);
				tab[i] = NULL;
			}
		}
		free(tab);
		tab = NULL;
	}

	int ch;

	printf("--------------------------------------------------------------------- \n");
	printf("\nKoniec programu \nNacisnij [Ctrl + Z] Enter, aby zakonczyc \n");
	while ((ch = getchar()) != EOF);
	exit(exit_code);
}

int losowa_liczba(int min, int max) {
	return min + rand() % (max + 1 - min);
}

void wypelnij(int** tab, int n, int min, int max) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = losowa_liczba(min, max);
}

void wypisz(int** tab, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
}

void zad1(int** B, int n, int a, int b) {
	int suma = 0;

	printf("Zad 1. \n");
	printf("--------------------------------------------- \n");
	printf("Macierz B: \n");
	wypisz(B, n);
	printf("--------------------------------------------- \n");

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (B[i][j] >= a && B[i][j] <= b) {
				suma += B[i][j];
			}
		}
	}

	printf("Suma elementow ponizej przekatnej z zakresu [%d, %d] wynosi %d \n", a, b, suma);
	printf("--------------------------------------------- \n");
	printf("\n\n");
}

void zad2(int** B, int n) {
	int suma = 0;

	printf("Zad 2. \n");
	printf("--------------------------------------------- \n");
	printf("Macierz B: \n");
	wypisz(B, n);
	printf("--------------------------------------------- \n");

	for (int i = 0; i < n; i++) {
		if (i == n - 1 - i) {
			if (sin(B[i][i]) >= 0 || sin(B[i][n - 1 - i]) >= 0.5) {
				suma += B[i][i];
			}
		}
		else {
			if (sin(B[i][i]) >= 0) {
				suma += B[i][i];
			}
			if (sin(B[i][n - 1 - i]) >= 0.5) {
				suma += B[i][n - 1 - i];
			}
		}

	}

	printf("Suma elementow na przekatnych spelniajacych dany warunek wynosi %d \n", suma);
	printf("--------------------------------------------- \n");
	printf("\n\n");
}

int main(int argc, char* argv[]) {
	int n, min, max, a, b;
	int ret = -1;
	srand((unsigned)time(NULL));

	printf("Podaj rozmiar macierzy B: ");
	ret = scanf("%d", &n);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1);
		return 0;
	}

	if (n <= 0) {
		printf("Liczba kolumn / wierzy powinna byc wieksza od zera! \n");
		my_exit(3);
		return 0;
	}

	//tworze macierz B
	int** B = NULL;
	B = (int**)malloc(n * sizeof(int*));
	if (!B) {
		printf("Blad alokacji! \n");
		my_exit(2);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		B[i] = (int*)malloc(n * sizeof(int));
		if (!B[i]) {
			printf("Blad alokacji! \n");
			my_exit(2, B, n);
			return 0;
		}
	}

	printf("Podaj zakres z jakiego wybiore liczby dla powstajacej macierzy: \n");
	printf("MIN: ");
	ret = scanf("%d", &min);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1, B, n);
		return 0;
	}
	printf("MAX: ");
	ret = scanf("%d", &max);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1, B, n);
		return 0;
	}

	wypelnij(B, n, min, max);
	
	printf("Podaj przedzial dla warunku z zad 1: \n");
	printf("a: ");
	ret = scanf("%d", &a);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1, B, n);
		return 0;
	}
	printf("b: ");
	ret = scanf("%d", &b);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1, B, n);
		return 0;
	}

	system("cls");

	zad1(B, n, a, b);
	zad2(B, n);

	my_exit(0, B, n);
	return 0;
}