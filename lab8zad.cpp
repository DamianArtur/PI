#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

void my_exit(int exit_code, int* t1 = NULL, int* t2 = NULL) { // wlasna funkcja konczaca program
	if (t1 != NULL) {
		free(t1);
		t1 = NULL;
	}
	if (t2 != NULL) {
		free(t2);
		t2 = NULL;
	}

	int ch;

	printf("--------------------------------------------------------------------- \n");
	printf("\nKoniec programu \nNacisnij [Ctrl + Z] Enter, aby zakonczyc \n");
	while ((ch = getchar()) != EOF);
	exit(exit_code);
}

int losowa_liczba() {
	return rand() % 100;
}

void wypelnij(int* tab, int n) {
	for (int i = 0; i < n; i++)
		tab[i] = losowa_liczba();
}

void znajdz_min_max(int* tab, int n, int& max, int& min, int& max_ind, int& min_ind) {
	min = tab[0];
	min_ind = 0;
	max = tab[0];
	max_ind = 0;

	for (int i = 1; i < n; i++) {
		if (min < tab[i]) {
			min = tab[i];
			min_ind = i;
		}
		if (max > tab[i]) {
			max = tab[i];
			max_ind = i;
		}
	}
}

void wyswietl(int* tab, int n) {
	for (int i = 0; i < n; i++)
		printf("%d ", tab[i]);
	printf("\n\n");
}

void zad1() {
	int n;
	int ret = -1;

	printf("Zad. 1 \n");
	printf("------------------------------------------------- \n\n");
	printf("Wprowadz rozmiar tablicy: ");
	
	ret = scanf("%d", &n);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1);
	}

	if (n <= 0) {
		printf("Rozmiar tablicy powinien byc wiekszy niz 0. \n");
		my_exit(1);
	}

	int* t1 = (int*)malloc(n * sizeof(int)); //alokacja tablic
	int* t2 = (int*)malloc(n * sizeof(int));

	if (t1 == NULL || t2 == NULL) { //jesli alokacja sie nie powiedzie
		printf("Alokacja pamieci nie powiodla sie! \n");
		my_exit(1, t1, t2);
	}

	wypelnij(t1, n); //wypelnianie tablicy losowymi liczbami

	int min, max, max_ind, min_ind;
	znajdz_min_max(t1, n, min, max, min_ind, max_ind); //znajdowanie minimum i maksimum w tablicy

	printf("Tablica t1: \n"); //wyswietlanie tablicy, minimum i maksimum
	wyswietl(t1, n);
	printf("Maksimum w tablicy t1 to %d, a minimum to %d \n", max, min);
	printf("Indeks maksimum to %d, indeks minimum to %d \n\n", max_ind, min_ind);

	memmove(t2, t1, n*sizeof(int)); //kopiowanie t1 do t2

	printf("Tablica t2: \n");
	wyswietl(t2, n);

	my_exit(0, t1, t2);
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	zad1();
	return 0;
}