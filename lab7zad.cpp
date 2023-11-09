#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define N 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losowa_liczba1() {
	return rand() % 11;
}

void wypelnij1(int(&tab)[N]) {
	for (int i = 0; i < N; i++) {
		tab[i] = losowa_liczba1();
	}
}

void zad1() {
	printf("---------------------------------------------------- \n");
	printf("Zad1. Tablica z losowymi liczbami: \n");

	int tab[N];
	wypelnij1(tab);

	printf("Otrzymana tablica: \n");
	for (int i = 0; i < N; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");

	printf("---------------------------------------------------- \n");
	return;
}

int losowa_liczba2() {
	static int liczba_wywolan;
	liczba_wywolan++;

	printf("Wywolanie nr %d \n", liczba_wywolan);

	return rand() % 11;
}

void wypelnij2(int* tab) {
	for (int i = 0; i < N; i++) {
		tab[i] = losowa_liczba2();
	}
}

void zad2() {
	printf("---------------------------------------------------- \n");
	printf("Zad2. Tablica z losowymi liczbami oraz zliczaniem wywolan funkcji generujacej: \n");

	int tab[N];
	wypelnij2(tab);

	printf("Otrzymana tablica: \n");
	for (int i = 0; i < N; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");

	printf("---------------------------------------------------- \n");
	return;
}

void wypelnij1_kopia(int(&tab)[N]) {
	printf("Rozmiar tablicy w funcji z zadania pierwszego to %d \n", sizeof(tab));

	for (int i = 0; i < N; i++) {
		tab[i] = losowa_liczba1();
	}
}

void wypelnij2_kopia(int* tab) {
	printf("Rozmiar tablicy w funcji z zadania drugiego to %d \n", sizeof(tab));
	printf("(W zasadzie jest to rozmiar samego wskaznika do tej tablicy) \n");

	for (int i = 0; i < N; i++) {
		tab[i] = losowa_liczba1();
	}
}

void zad3() {
	printf("---------------------------------------------------- \n");
	printf("Zad3. Tablica z losowymi liczbami oraz mierzeniem rozmiaru tablicy: \n");

	int tab[N];
	printf("Rozmiar tablicy po deklaracji %d \n", sizeof(tab));

	wypelnij1_kopia(tab);
	wypelnij2_kopia(tab);

	printf("---------------------------------------------------- \n");
	return;
}

void zad4() {
	printf("---------------------------------------------------- \n");
	printf("Zad. 4 Szukanie elementu w tablicy bez indeksow \n");
	int tab[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int szukany_element = 5;

	int* ptr = tab;
	for (int i = 0; i < szukany_element; i++) {
		ptr++;
	}

	printf("Element tablicy o indeksie %d to %d. \n", szukany_element, *ptr);
	printf("---------------------------------------------------- \n");

	return;
}

int main(int argc, char* argv[]) {
	srand(time(NULL));

	zad1();
	zad2();
	zad3();
	zad4();

	printf("\nKoniec programu \n");
	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;

	return 0;
}