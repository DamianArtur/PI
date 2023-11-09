#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define MAX_SIZE 256 //maksymalny rozmiar wprowadzanych danych
#define DATE_SIZE 12 //dlugosc daty w formacie dd.mm.rrrr
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void clearBuffor() {
	while (getchar() != '\n');
}

void my_exit(FILE* fp = NULL, FILE* fp_results = NULL) { // wlasna funkcja konczaca program
	int ch;

	if (fp != NULL) {
		fclose(fp); //zamkniecie pliku z danymi
		fp = NULL;
	}

	if (fp_results != NULL) {
		fclose(fp_results); //zamkniecie pliku z wynikami
		fp_results = NULL;
	}

	printf("\nKoniec programu \nNacisnij [Ctrl + Z] Enter, aby zakonczyc \n");
	while ((ch = getchar()) != EOF);
	exit(0);
}

void my_exit_error() {
	printf("\nBlad wczytywania - Zamkniecie programu! \n");
	printf("------------------------------------------------------------------------------------------------------- \n\n");
	my_exit();
}

int main(int argc, char* argv[]) {
	int znakow_na_stronie = 1;
	char* tekst;
	char* tytul;
	char* data;
	char* wlasciciel;

	printf("Zad 5. Program stronnicuje tekst z zadanego pliku tekstowego\n\t-wyswietla utworzone strony i zapisuje do osobnych plikow. \n\n"); //naglowek programu
	printf("------------------------------------------------------------------------------------------------------- \n");

	if (argc == 6) { //jesli program wywolano z argumentami

		tekst = argv[1];
		znakow_na_stronie = atoi(argv[2]);
		tytul = argv[3];
		data = argv[4];
		wlasciciel = argv[5];

	}
	else if (argc == 1) { // jesli program uruchomiono bez argumentow

		int ret = -1;

		char tekstTab[MAX_SIZE];
		char tytulTab[MAX_SIZE];
		char dataTab[DATE_SIZE];
		char wlascicielTab[MAX_SIZE];

		tekst = tekstTab;
		tytul = tytulTab;
		data = dataTab;
		wlasciciel = wlascicielTab;

		printf("Nie podano argumentow przy wywolaniu, mozesz podac je teraz (nie dluzsze niz 255 znakow): \n");
		printf("------------------------------------------------------------------------------------------------------- \n");

		printf("Wprowadz nazwe pliku (lub sciezke na dysku do niego): "); //pobieranie danych od uzytkownika jesli nie podal ich w argumentach funkcji
		fgets(tekst, MAX_SIZE, stdin);
		tekst[strlen(tekst) - 1] = '\0';
		printf("Wprowadz liczbe znakow na stronie: ");
		ret = scanf("%d", &znakow_na_stronie);
		if (ret != 1) {
			my_exit_error();
			return 1;
		}
		clearBuffor();
		printf("Wprowadz tytul tekstu: ");
		fgets(tytul, MAX_SIZE, stdin);
		tytul[strlen(tytul) - 1] = '\0';
		printf("Wprowadz date wydruku w formacie dd.mm.rrrr: ");
		fgets(data, DATE_SIZE, stdin);
		data[strlen(data) - 1] = '\0';
		printf("Wprowadz wlasciciela pliku: ");
		fgets(wlasciciel, MAX_SIZE, stdin);
		wlasciciel[strlen(wlasciciel) - 1] = '\0';

		printf("------------------------------------------------------------------------------------------------------- \n");

	}
	else { //jesli liczba argumentow nie byla prawidlowa

		printf("Liczba argumentow jest nie prawidlowa! \n");
		printf("Prawidlowe wywolanie powinno wygladac nastepujaco: \n\n");
		printf("stronnicowanie.exe [nazwa_pliku] [liczba_znakow_na_stronie]\n[tytul] [data_wydruku] [nazwa_wlasciciela] \n");
		printf("------------------------------------------------------------------------------------------------------- \n");
		my_exit();
		return 1;

	}

	FILE* fp = NULL; //otwieranie pliku do odczytu
	fp = fopen(tekst, "r");
	if (fp == NULL) { //w przypadku niepowodzenia
		printf("Nie moge otworzyc pliku %s, moze taki plik nie istnieje? \n", tekst);
		printf("------------------------------------------------------------------------------------------------------- \n\n");
		my_exit();
		return 1;
	}

	FILE* fp_results = NULL; //tworzenie pliku do zapisu wynikow
	fp_results = fopen("wyniki.txt", "a");
	if (fp_results == NULL) {
		printf("Nie moge utworzyc pliku wyniki.txt! \n");
		printf("------------------------------------------------------------------------------------------------------- \n\n");
		my_exit(fp);
		return 1;
	}
	
	fseek(fp, 0, SEEK_END); //sprawdzenie ile potrzeba stron
	int znakow_w_tekscie = ftell(fp);
	int liczba_stron = (int)ceil(znakow_w_tekscie/(double)znakow_na_stronie);
	fseek(fp, 0, SEEK_SET);

	system("cls");

	for (int i = 1; i <= liczba_stron; i++) { //w tej petli wyswiatlane kolejne strony
		printf("%s - Strona %d - %s - %s \n", tytul, i, data, wlasciciel); //naglowek kazdej strony
		fprintf(fp_results, "%s - Strona %d - %s - %s \n", tytul, i, data, wlasciciel);
		printf("------------------------------------------------------------------------------------------------------- \n");
		fprintf(fp_results, "------------------------------------------------------------------------------------------------------- \n");

		int poz = 0; //ta zmienna pilnuje liczby znakow na stronie
		char znak;

		while (poz < znakow_na_stronie) { //wyswietlanie znakow na stronie
			znak = fgetc(fp);
			if (znak == EOF)
				break;
			printf("%c", znak);
			fputc(znak, fp_results);
			poz++;
		}

		printf("\n------------------------------------------------------------------------------------------------------- \n\n\n");
		fprintf(fp_results, "\n------------------------------------------------------------------------------------------------------- \n\n\n");
	}

	my_exit(fp, fp_results);
	return 0;
}