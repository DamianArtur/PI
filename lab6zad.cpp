#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define MAX_LINE 256
#define MAX_LINES 200
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffor() {
	while (getchar() != '\n');
}

void my_exit(int exit_code) {
	int ch;

	printf("--------------------------------------------------------------------- \n");
	printf("\nKoniec programu \nNacisnij [Ctrl + Z] Enter, aby zakonczyc \n");
	while ((ch = getchar()) != EOF);
	exit(exit_code);
}

void zad15() {
	FILE* fd;
	char* d[MAX_LINES], bufor[MAX_LINE]; //tablica z tekstem
	char nazwa_pliku[MAX_LINE];
	int ret = -1;
	int len, i, l, liczba_linii = 0, linia1, linia2;

	printf("Zad 15. \n");
	printf("--------------------------------------------------------------------- \n");
	printf("Wprowadz nazwe pliku [maks 256 znakow]: ");
	fgets(nazwa_pliku, MAX_LINE, stdin);
	nazwa_pliku[strlen(nazwa_pliku) - 1] = '\0';

	if (!(fd = fopen(nazwa_pliku, "r")))
	{
		printf("Blad otwarcia pliku! Czy plik na pewno istnieje? \n");
		my_exit(1);
		return;
	}

	i = 0;
	l = 0;
	while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd))
	{
		len = strlen(bufor);
		if (len > 0)
			bufor[len - 1] = '\0';
		if (!(d[i] = (char*)malloc((unsigned)len)))
		{
			printf("Brak pamieci\n");
			my_exit(1);
		}
		strcpy(d[i], bufor);
		i++;
	}
	d[i] = (char*)0;

	for (int i = 0; i < MAX_LINES; i++) {
		if (d[i] != NULL) {
			liczba_linii += 1;
		}
		else {
			break;
		}
	}

	printf("Tekst ma %d linii, podaj dwie [liczac od 1], ktore chcesz zamienic: ", liczba_linii);
	ret = scanf("%d%d", &linia1, &linia2);

	linia1--;
	linia2--;

	if (ret != 2) {
		printf("Blad wczytywania! \n");
		fclose(fd);
		my_exit(1);
		return;
	}

	if (linia1 > liczba_linii || linia2 > liczba_linii || linia1 == linia2) {
		printf("Numer linii jest nieprawidlowy! \n");
		fclose(fd);
		my_exit(1);
		return;
	}

	char* temp;
	if (linia1 < MAX_LINES && linia2 < MAX_LINES) {
		temp = d[linia1]; //zamiania linii
		d[linia1] = d[linia2];
		d[linia2] = temp;
	}

	printf("--------------------------------------------------------------------- \n");
	printf("Zamieniono linie %d i %d. \n", linia1+1, linia2+1);
	printf("--------------------------------------------------------------------- \n");

	printf("Tekst po zamianie: \n"); //wyswietlenie tekstu po zmianie linii
	for (int i = 0; i < liczba_linii; i++) {
		printf("%s \n", d[i]);
	}

	if (fd != NULL) { //zamkniecie pliku
		fclose(fd);
		fd = NULL;
	}

	for (int i = 0; i < liczba_linii; i++) {
			free(d[i]); //zwalnianie pamieci
	}

	printf("--------------------------------------------------------------------- \n");
	printf("\n\n");
	clearBuffor();
	return;
}
 
void zad16() {
	FILE* fd;
	char* d[MAX_LINES], bufor[MAX_LINE]; //tablica z tekstem
	char nazwa_pliku[MAX_LINE];
	char szukany_tekst[MAX_LINE];
	int ret = -1;
	int len, i, l, liczba_linii = 0;

	printf("Zad 16. \n");
	printf("--------------------------------------------------------------------- \n");
	printf("Wprowadz nazwe pliku: [maks 256 znakow]: ");
	fgets(nazwa_pliku, MAX_LINE, stdin);
	nazwa_pliku[strlen(nazwa_pliku) - 1] = '\0';

	if (!(fd = fopen(nazwa_pliku, "r")))
	{
		printf("Blad otwarcia pliku! Czy plik na pewno istnieje? \n");
		my_exit(1);
		return;
	}

	i = 0;
	l = 0;
	while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd))
	{
		len = strlen(bufor);
		if (len > 0)
			bufor[len - 1] = '\0';
		if (!(d[i] = (char*)malloc((unsigned)len)))
		{
			printf("Brak pamieci\n");
			my_exit(1);
		}
		strcpy(d[i], bufor);
		i++;
	}
	d[i] = (char*)0;

	for (int i = 0; i < MAX_LINES; i++) {
		if (d[i] != NULL) {
			liczba_linii += 1;
		}
		else {
			break;
		}
	}

	printf("Tekst ma %d linii, wprowadz tekst od ktorego zaczynac maja sie szukane linie [maks 256 znakow]: \n", liczba_linii);
	fgets(szukany_tekst, MAX_LINE, stdin);
	szukany_tekst[strlen(szukany_tekst) - 1] = '\0';

	int liczba_znalezionych_linii = 0;
	printf("Znaleziono nastepujace linie: \n");

	for (int i = 0; i < liczba_linii; i++) { //szukanie pasujacych linii
		int boolean = 1;
		int j = 0;
		int k = 0;
		while (szukany_tekst[j] != '\0' and d[i][k] != '\0') {
			if (szukany_tekst[j] != d[i][k]) {
				boolean = 0;
				break;
			}
			j++;
			k++;
		}
		if (boolean == 1) {
			liczba_znalezionych_linii++;
			printf("%s \n", d[i]);
		}
	}

	if (liczba_znalezionych_linii == 0) {
		printf("Nie znaleziono linii spelniajacych podane kryteria. \n");
	}

	if (fd != NULL) { //zamkniecie pliku
		fclose(fd);
		fd = NULL;
	}

	for (int i = 0; i < liczba_linii; i++) {
		free(d[i]); //zwalnianie pamieci
	}

	printf("--------------------------------------------------------------------- \n");
	printf("\n\n");
	return;
}

void zad17() {
	FILE* fd;
	char* d[MAX_LINES+1], bufor[MAX_LINE]; //tablica z tekstem
	char nazwa_pliku[MAX_LINE];
	char nowa_linia[MAX_LINE];
	int ret = -1;
	int len, i, l, n, liczba_linii = 0;

	printf("Zad 17. \n");
	printf("--------------------------------------------------------------------- \n");
	printf("Wprowadz nazwe pliku [maks 256 znakow]: ");
	fgets(nazwa_pliku, MAX_LINE, stdin);
	nazwa_pliku[strlen(nazwa_pliku) - 1] = '\0';

	if (!(fd = fopen(nazwa_pliku, "r")))
	{
		printf("Blad otwarcia pliku! Czy plik na pewno istnieje? \n");
		my_exit(1);
		return;
	}

	i = 0;
	l = 0;
	while (i < MAX_LINES && fgets(bufor, MAX_LINE, fd))
	{
		len = strlen(bufor);
		if (len > 0)
			bufor[len - 1] = '\0';
		if (!(d[i] = (char*)malloc(MAX_LINE)))
		{
			printf("Brak pamieci\n");
			exit(3);
		}
		strcpy(d[i], bufor);
		i++;
	}
	d[i] = (char*)0;

	for (int i = 0; i < MAX_LINES; i++) {
		if (d[i] != NULL) {
			liczba_linii += 1;
		}
		else {
			break;
		}
	}

	printf("Tekst ma %d linii, wprowadz tekst nowej linii [maks 256 znakow]: \n", liczba_linii);
	fgets(nowa_linia, MAX_LINE, stdin);
	nowa_linia[strlen(nowa_linia) - 1] = '\0';
	printf("Wprowadz numer linii [liczac od 1] po ktorej chcesz dodac nowa linie: ");
	ret = scanf("%d", &n);
	if (ret != 1) {
		fclose(fd);
		my_exit(1);
	}

	if (n > liczba_linii) {
		printf("podana linia poza tesktem! \n");
		my_exit(1);
		return;
	}

	d[liczba_linii] = (char*)malloc(MAX_LINE);
	for (int i = liczba_linii; i > n; i--) { //przesuwam pozostale linie
		strcpy(d[i], d[i - 1]);
	}

	strcpy(d[n], nowa_linia); //wklejam nowa linie
	liczba_linii++;

	printf("--------------------------------------------------------------------- \n");
	printf("Dodano nowa linie po linii o nr %d \n", n);
	printf("--------------------------------------------------------------------- \n");

	printf("Tekst po dodaniu nowej linii: \n\n");
	for (int i = 0; i < liczba_linii; i++) {
		printf("%s \n", d[i]);
	}

	if (fd != NULL) { //zamkniecie pliku
		fclose(fd);
		fd = NULL;
	}

	for (int i = 0; i < liczba_linii; i++) {
		free(d[i]); //zwalnianie pamieci
	}

	printf("--------------------------------------------------------------------- \n");
	printf("\n\n");
	clearBuffor();
	return;
}

void wypisz_slowo(FILE* fd, int szukana_pozycja) {
	int poz = 1;
	char character;

	if (poz == szukana_pozycja) {
		while (fscanf(fd, "%c", &character) != EOF) {
			if (character == ':') {
				return;
			}
			printf("%c", character);
		}
	}

	while (fscanf(fd, "%c", &character) != EOF) {
		if (character == ':') {
			poz++;
			if (poz == szukana_pozycja) {
				while (fscanf(fd, "%c", &character) != EOF) {
					if (character == ':') {
						return;
					}
					printf("%c", character);
				}
			}
		}
	}
}
 
void zad18() {
	FILE* fd;
	char nazwa_pliku[MAX_LINE];
	int ret = -1;
	int len, szukana_pozycja;

	printf("Zad 18. \n");
	printf("--------------------------------------------------------------------- \n");
	printf("Wprowadz nazwe pliku [maks 256 znakow]: ");
	fgets(nazwa_pliku, MAX_LINE, stdin);
	nazwa_pliku[strlen(nazwa_pliku) - 1] = '\0';

	if (!(fd = fopen(nazwa_pliku, "r")))
	{
		printf("Blad otwarcia pliku! Czy plik na pewno istnieje? \n");
		my_exit(1);
		return;
	}

	fseek(fd, 0, SEEK_END);
	len = ftell(fd);
	fseek(fd, 0, SEEK_SET);

	printf("Wprowadz pozycje szukanego slowa: ");
	ret = scanf("%d", &szukana_pozycja);
	if (ret != 1) {
		printf("Blad wczytywania! \n");
		fclose(fd);
		my_exit(1);
		return;
	}

	wypisz_slowo(fd, szukana_pozycja);
	printf(" \n");

	if (fd != NULL) { //zamkniecie pliku
		fclose(fd);
		fd = NULL;
	}

	printf("--------------------------------------------------------------------- \n");
	printf("\n\n");
	clearBuffor();
	return;
}

void konwersja1(FILE* fd) {
	int len = 88;
	char character;
	char litery[] = { 'a',165,'b','c',134,'d','e',169,'f','g','h','i','j','k','l',136, 'm','n',228,'o',162,'p','q','r','s',152,'t','u','v','w','x','y','z',190,171,'A',164,'B','C',143,'D','E',168,'F','G','H','I','J','K','L',157,'M','N',227,'O',224,'P','Q','R','S',151,'T','U','V','W','X','Y','Z',189,141,' ','.',',','?',':','-','0','1','2','3','4','5','6','7','8','9','!','\0' };
	char mors[][8] = { ".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--",".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.", "...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--"," ",".-.-.-","--..--","..--..","---...","-....-","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","!",0};

	while (fscanf(fd, "%c", &character) != EOF) {
		for (int i = 0; i < 88; i++) {
			if (litery[i] == character) {
				printf("%s ", mors[i]);
				break;
			}
		}
	}
}

void konwersja2(FILE* fd) {
	int len = 88;
	int i = 0;
	char character;
	char mors_character[20];
	char litery[] = { 'a',165,'b','c',134,'d','e',169,'f','g','h','i','j','k','l',136, 'm','n',228,'o',162,'p','q','r','s',152,'t','u','v','w','x','y','z',190,171,'A',164,'B','C',143,'D','E',168,'F','G','H','I','J','K','L',157,'M','N',227,'O',224,'P','Q','R','S',151,'T','U','V','W','X','Y','Z',189,141,' ','.',',','?',':','-','0','1','2','3','4','5','6','7','8','9','!','\0' };
	char mors[][8] = { ".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--",".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---.",".--.","--.-",".-.", "...","...-...","-","..-","...-",".--","-..-","-.--","--..","--..-","--"," ",".-.-.-","--..--","..--..","---...","-....-","-----",".----","..---","...--","....-",".....","-....","--...","---..","----.","!",0 };

	while (fscanf(fd, "%s", &mors_character) != EOF) {
		for (int i = 0; i < 88; i++) {
			if (strcmp(mors[i], mors_character) == 0) {
				printf("%c", litery[i]);
				break;
			}
		}
	}

	return;
}

void zad19() {
	FILE* fd;
	char* d[MAX_LINES], bufor[MAX_LINE];
	char nazwa_pliku[MAX_LINE];
	int len, i, l;
	int tryb;
	
	printf("Zad. 19 \n");
	printf("Program zamienia tekst z pliku na kod Morse'a i odwrotnie\n");
	printf("--------------------------------------------------------------------- \n");
	printf("Wprowadz nazwe pliku [maks 256 znakow]: ");

	fgets(nazwa_pliku, MAX_LINE, stdin);
	nazwa_pliku[strlen(nazwa_pliku) - 1] = '\0';

	if (!(fd = fopen(nazwa_pliku, "r")))
	{
		printf("Blad otwarcia pliku! Czy plik na pewno istnieje? \n");
		my_exit(1);
		return;
	}

	printf("Wybierz tryb pracy: \n");
	printf("1 - konwersja z tekstu na kod Morse'a \n2 - konwersja z Morse'a na zwykły tekst \n");
	printf("--------------------------------------------------------------------- \n");
	scanf("%d", &tryb);

	switch (tryb) {
	case 1:
		konwersja1(fd);
		break;
	case 2:
		konwersja2(fd);
		break;
	default:
		printf("Wybierz 1 lub 2! \n");
		my_exit(1);
	}

	fclose(fd);
	printf("\n");
	printf("--------------------------------------------------------------------- \n");
	clearBuffor();
	return;
}

int main(int argc, char* argv[]) {
	zad15();
	zad16();
	zad17();
	zad18();
	zad19();

	printf("\nKoniec programu \n");
	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;

	return 0;
}