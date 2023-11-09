#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void my_exit() {
	int ch;

	printf("\nNacisnij [Ctrl + Z] Enter, aby zakonczyc \n");

	while ((ch = getchar()) != EOF)
		;
	exit(0);
}

void my_exit_error() {
	printf("\nBlad wczytywania - Zamkniecie programu! \n");
	printf("------------------------------------------------------------------------------------------------------- \n\n");
	my_exit();
}

double f_scisla(double x) { //funkcja do znajdowania wartosci scislej
	return cbrt(1 - x);
}

double f_szereg(double x, double eps, int max_N, int* ilosc_wyrazow, char* warunek_stopu) { //funckcja do obliaszania metoda szeregu
	double d = 1, res = 1;
	int n = 1, a = 1, b = 3;

	do {
		d *= (x * a) / b; //wartosc kolejnego wyrazu

		a = b - 1; //a, b - wspolczynniki kolejnych wyrazow szeregu
		b += 3;

		res -= d; //uaktualnienie wyniku o nowy wyraz
		n++;
	} while (fabs(d) >= eps && n <= max_N); //warunki stopu

	*ilosc_wyrazow = n-1; //informacja o ilosci liczonych wyrazow

	if (fabs(d) < eps) { //okreslenie warunku stopu
		if (n-1 == max_N)
			*warunek_stopu = 'c'; //c tzn. ze warunkiem stopu zarowno ograniczenie na N, jak i dokladnosc obliczen
		else
			*warunek_stopu = 'a'; //a tzn. ze warunkiem stopu byla dokladnosc obliczen
	} else {
		*warunek_stopu = 'b'; //b tzn. ze warunkiem stopu bylo ograniczenie na N
	}

	return res; //zwracanie wyniku
}

int main(int argc, char* argv[]) {
	double a, b, eps;
	int i, n, max_N, ret = 0;

	printf("Program oblicza wartosc funkcji (1-x)^(1/3) z rozwiniecia w szereg Taylora dla |x| <= 1 \n\n"); //wczytywanie danych
	printf("------------------------------------------------------------------------------------------------------- \n");

	printf("Podaj poczatek przedzialu a = ");
	ret = scanf("%lf", &a);
	if (ret != 1) my_exit_error();
	ret = 0;
	if (a < -1 || a >= 1) {
		printf("Poczatek przedzialu wybierz z zakresu [-1, 1) \n");
		my_exit();
	}

	printf("Podaj koniec przedzialu b = ");
	ret = scanf("%lf", &b);
	if (ret != 1) my_exit_error();
	ret = 0;
	if (b <= -1 || b > 1) {
		printf("Koniec przedzialu wybierz z zakresu (-1, 1] \n");
		my_exit();
	}

	if (b - a < 0) {
		printf("Koniec przedzialu wybierz po poczatku \n");
		my_exit();
	}

	printf("Podaj liczbe podzialow przedzialu n = ");
	ret = scanf("%d", &n);
	if (ret != 1) my_exit_error();
	ret = 0;

	printf("Podaj dokladnosc wynikow eps = ");
	ret = scanf("%lf", &eps);
	if (ret != 1) my_exit_error();
	ret = 0;

	printf("Podaj maksymalna ilosc liczonych wyrazow max_N = ");
	ret = scanf("%d", &max_N);
	if (ret != 1) my_exit_error();

	printf("------------------------------------------------------------------------------------------------------- \n\n");

	printf("------------------------------------------------------------------------------------------------------- \n"); //wyswietlanie wprowadzonych danych
	printf("Wprowadzono nastepujace dane: \n");
	printf("[a, b] = [%lf, %lf] (n = %d, dx = %lf) \n", a, b, n, (b - a) / n);
	printf("Maksymalna liczba wyrazow w szeregu: %d \n", max_N);
	printf("Dokladnosc eps = %le \n", eps);
	printf("------------------------------------------------------------------------------------------------------- \n\n");

	FILE* fp = NULL; //otwieranie pliku do zapisu
	fp = fopen("wyniki.txt", "a");
	if (fp == NULL) { //w przypadku niepowodzenia
		printf("Nie moge otworzyc lub utworzyc pliku wyniki.txt do zapisu! \n");
		printf("------------------------------------------------------------------------------------------------------- \n\n");
	}
	printf("------------------------------------------------------------------------------------------------------- \n");
	printf("Otwarto / utworzono plik wyniki.txt w ktorym zapisano nastepujace dane: \n");
	printf("------------------------------------------------------------------------------------------------------- \n\n");

	printf("+-----------+-----------------------+-----------------------+---------+-------------------------------+ \n"); //naglowek tabeli
	printf("|     x     |       f_szereg(x)     |       f_scisle(x)     | wyrazy  |          warunek stopu        | \n");
	printf("|           |                       |                       | szeregu |                               | \n");
	printf("+-----------+-----------------------+-----------------------+---------+-------------------------------+ \n");

	for (i = 0; i <= n; i++) {
		double wynik_szereg, wynik_scisly, x;
		int ilosc_wyrazow;
		char war_stopu;

		x = a + (b - a) * (double)i / n;
		wynik_scisly = f_scisla(x); //wywolanie funkcji - znajdowanie wartosci scislej
		wynik_szereg = f_szereg(x, eps, max_N, &ilosc_wyrazow, &war_stopu); //wywolanie funckji - znajdowanie wartosci przez szereg

		printf("| %+.6lf | %.15le | %.15le |    %2d   |", x, wynik_szereg, wynik_scisly, ilosc_wyrazow); //wypisywanie wynikow
		if (fp != NULL) fprintf(fp, "| %+.6lf | %.15le | %.15le |    %2d   |", x, wynik_szereg, wynik_scisly, ilosc_wyrazow); //zapis do pliku

		if (war_stopu == 'a') {
			printf("     osiagnieto dokladnosc     | \n");
			if (fp != NULL) fprintf(fp, "     osiagnieto dokladnosc     | \n");
		}
		else if (war_stopu == 'b') {
			printf("         limit wyrazow         | \n");
			if (fp != NULL) fprintf(fp, "         limit wyrazow         | \n");
		}
		else if (war_stopu == 'c') {
			printf(" limit wyrazow oraz dokladnosc | \n");
			if (fp != NULL) fprintf(fp, " limit wyrazow oraz dokladnosc | \n");
		}
	}

	printf("+-----------+-----------------------+-----------------------+---------+-------------------------------+ \n\n"); //dolna belka tabeli

	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

	my_exit();
	return 0;
}