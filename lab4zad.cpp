#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

double silnia(int n) {
	double result = 1.0;

	for (int i = 1; i <= n; i++) {
		result *= i;
	}

	return result;
}

void zad4() {
	int n;
	int ret = -1;

	printf("------------------------- \n");
	printf("Program wypisuje n razy 'Hello World!' \n");
	printf("Podaj liczbe powtorzen: ");
	ret = scanf("%d", &n);

	if (ret != 1) {
		printf("Blad wczytania! \n");
		printf("------------------------- \n\n");
		return;
	}

	if (n < 0) {
		printf("Liczba powotrzen powinna byc nieujemna. \n");
		printf("------------------------- \n\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		printf("Hello World! \n");
	}

	printf("------------------------- \n\n");
}

void zad5() {
	int n;
	int ret = -1;

	printf("------------------------- \n");
	printf("Program liczy silnie z liczby n \n");
	printf("Podaj liczbe n: ");
	ret = scanf("%d", &n);

	if (ret != 1) {
		printf("Blad wczytania! \n");
		printf("------------------------- \n\n");
		return;
	}

	if (n < 0) {
		printf("Liczba n powinna byc nieujemna. \n");
		printf("------------------------- \n\n");
		return;
	}

	printf("Silnia z liczby n wynosi %0.lf \n", silnia(n));
	printf("------------------------- \n\n");
}

void zad7() {
	printf("------------------------- \n");
	printf("Program wczytuje znaki dopoki nie pododano 'e' \n");

	while (1) {
		char character;
		scanf(" %c", &character);
		if (character == 'e') break;
	}

	printf("Podano 'e' - wyjscie z funkcji \n");
	printf("------------------------- \n\n");
}

void zad8() {
	printf("------------------------- \n");
	printf("Program wczytuje znaki dopoki nie pododano 'e' oraz zlicza wystapienia: 'a', 'b' i 'c' \n");

	int numberOfa = 0;
	int numberOfb = 0;
	int numberOfc = 0;
	int numberOfOthers = 0;

	while (1) {
		char character;
		scanf(" %c", &character);
		if (character == 'a') {
			numberOfa++;
			continue;
		}
		if (character == 'b') {
			numberOfb++;
			continue;
		}
		if (character == 'c') {
			numberOfc++;
			continue;
		}
		numberOfOthers++;
		if (character == 'e')
			break;
	}

	printf("Podano 'e' - wyjscie z funkcji \n");
	printf("Znakow 'a' bylo %d \nZnakow 'b' bylo %d \nZnakow 'c' bylo %d \nPozostalych znakow bylo %d \n", numberOfa, numberOfb, numberOfc, numberOfOthers);
	printf("------------------------- \n\n");
}

void zad9() {
	printf("------------------------- \n");
	printf("Program wczytuje znaki dopoki nie pododano 'e' oraz zlicza wystapienia: 'a', 'b' i 'c' \noraz ilosc znakow 'c' sumuje do pozostalych znakow \n");

	int numberOfa = 0;
	int numberOfb = 0;
	int numberOfc = 0;
	int numberOfOthers = 0;

	while (1) {
		char character;
		scanf(" %c", &character);
		if (character == 'a') {
			numberOfa++;
			continue;
		}
		if (character == 'b') {
			numberOfb++;
			continue;
		}
		if (character == 'c') {
			numberOfc++;
			goto addToOthers;
		}
		addToOthers:
		numberOfOthers++;
		if (character == 'e')
			break;
	}

	printf("Podano 'e' - wyjscie z funkcji \n");
	printf("Znakow 'a' bylo %d \nZnakow 'b' bylo %d \nZnakow 'c' bylo %d \nPozostalych znakow (razem z c) bylo %d \n", numberOfa, numberOfb, numberOfc, numberOfOthers);
	printf("------------------------- \n\n");
}

void zad13() {
	printf("------------------------- \n");
	printf("Program odczytuje, o ile istnieje, zawartosc pliku plik.txt \n");

	FILE *fp = NULL;
	fp = fopen("plik.txt", "r");

	if (fp == NULL) {
		printf("Nie moge otworzyc pliku plik.txt do odczytu! \n");
		printf("------------------------- \n\n");
		return;
	}

	printf("Odczytana wartosc: ");

	char character;
	while (fscanf(fp, "%c", &character) != EOF) {
		printf("%c", character);
	}

	fclose(fp);
	fp = NULL;
	printf("\n------------------------- \n\n");
}

int main(int argc, char* argv[]) {
	//kolejne zadania wywolywane w osobnych funkcjach
	zad4();
	zad5();
	zad7();
	zad8();
	zad9();
	zad13();

	printf("Wyjscie - Ctrl + Z Enter \n"); //wyjscie z programu
	int ch;
	while ((ch = getchar()) != EOF)
		;

	return 0;
}