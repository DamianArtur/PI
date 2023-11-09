#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define N 32 // rozmiar tablicy do zadania 2
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex {
	double real;
	double imaginary;
} COMPLEX;

typedef struct STUDENT {
	char imie[256];
	char nazwisko[256];
	char data_urodzenia[256];
	char adres[256];
	int stypendium;
} student;

void my_exit(int exit_code, FILE* fp = NULL) {

	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;
	exit(exit_code);
}

void zad1() {
	double a, b, c;
	int ret = -1;
	COMPLEX x1, x2, suma;

	printf("Zad. 1 Liczby zespolone \n");
	printf("------------------------------------------------------------- \n");

	printf("Mamy rownanie kwadratowe: ax^2 + bx + c = 0 \n");
	printf("Podaj a: ");
	ret = scanf("%lf", &a);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1);
	}
	printf("Podaj b: ");
	ret = scanf("%lf", &b);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1);
	}
	printf("Podaj c: ");
	ret = scanf("%lf", &c);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		my_exit(1);
	}

	printf("\nWprowadzone rownanie: %lf*x^2 + %lf*x + %lf = 0 \n\n", a, b, c);

	double delta = b * b - 4 * a * c;
	if (fabs(delta) <= 1e-15) {
		x1.real = x2.real = -1 * b / (2 * a);
		x1.imaginary = x2.imaginary = 0.0;
	}
	else {
		if (delta > 0) {
			x1.real = (-b - sqrt(delta)) / 2 * a;
			x2.real = (-b + sqrt(delta)) / 2 * a;
			x1.imaginary = x2.imaginary = 0.0;
		}
		else {
			x1.real = x2.real = -1 * b / (2 * a);
			x1.imaginary = sqrt(fabs(pow(b / (2 * a), 2) - c / a));
			x2.imaginary = -sqrt(fabs(pow(b / (2 * a), 2) - c / a));
		}
	}

	printf("Uzyskane pierwiastki: \n");
	printf("x1 = %lf + %lf * i \n", x1.real, x1.imaginary);
	printf("x2 = %lf + %lf * i \n", x2.real, x2.imaginary);

	printf("\n");
	printf("------------------------------------------------------------- \n");

	printf("Podaj liczbe zespolona z1 [jako dwie liczby double a+bi]: ");
	ret = scanf("%lf %lf", &x1.real, &x1.imaginary);
	if (ret != 2) {
		printf("Blad wczytywania! \n");
		my_exit(1);
	}
	printf("Podaj liczbe zespolona z2 [jako dwie liczby double a+bi]: ");
	ret = scanf("%lf %lf", &x2.real, &x2.imaginary);
	if (ret != 2) {
		printf("Blad wczytywania! \n");
		my_exit(1);
	}

	suma.real = x1.real + x2.real;
	suma.imaginary = x1.imaginary + x2.imaginary;
	
	printf("Suma tych dwoch liczb to: %lf + %lf * i \n", suma.real, suma.imaginary);

	printf("\n");
	printf("------------------------------------------------------------- \n");
}

void zad2() {
	FILE* fp = NULL;
	student* tab = NULL;
	tab = (student*)malloc(N * sizeof(student));
	if (!tab) {
		printf("Blad alokacji! \n");
		my_exit(4);
		return;
	}


	fp = fopen("dane.txt", "r");
	if (fp == NULL) {
		printf("Nie moge otworzyc pliku dane.txt, moze taki plik nie istnieje? \n");
		printf("------------------------------------------------------------------------------------------------------- \n\n");
		my_exit(2, fp);
		return;
	}

	int size = 0;
	int ret = -1;
	while (1) {
		ret = fscanf(fp, "%s", &tab[size].imie);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%s", &tab[size].nazwisko);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%s", &tab[size].data_urodzenia);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%s", &tab[size].adres);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%d", &tab[size].stypendium);
		if (ret == EOF)	break;
		size++;
	}

	int max = tab[0].stypendium;
	int max_ind = 0;
	for (int i = 1; i < size; i++) {
		if (tab[i].stypendium > max) {
			max = tab[i].stypendium;
			max_ind = i;
		}
	}

	printf("Najwieksze stypendium o wartosci %d otrzymuje %s %s \n", tab[max_ind].stypendium, tab[max_ind].imie, tab[max_ind].nazwisko);
	
	printf("\n");
	printf("------------------------------------------------------------- \n");

	free(tab);
	tab = NULL;
}

int main(int argc, char* argv[]) {
	zad1();
	zad2();

	my_exit(0);
	return 0;
}