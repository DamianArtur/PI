#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define N 10 //w zadaniu 6 rozmiar tablicy
#define MAX_SIZE 256
#include <stdio.h>
#include <string.h>

int moje_strcmp(const char*, const char*);
char* moje_strcat(char*, const char*);
char* moje_strcpy(char*, const char*);

void clearBuffor() {
	while (getchar() != '\n');
}

void zad1() {
	printf("------------------------- \n");
	printf("Zad 1. Program znajduje pozycje wybranego znaku w tekscie. \n");
	
	int rozmiar;
	char znak;
	char tekst[MAX_SIZE];

	printf("Wprowadz przykladowy tekst: (maks. 255 znakow) \n");
	fgets(tekst, MAX_SIZE, stdin);
	printf("Wprowadz szukany znak: \n");
	znak = getchar();
	clearBuffor();

	rozmiar = strlen(tekst);
	for (int i = 0; i < rozmiar; i++) {
		if (tekst[i] == znak) {
			printf("Znak %c znaleziono na pozycji %d [liczac od zera]. \n", znak, i);
			printf("------------------------- \n\n");
			return;
		}
	}

	printf("Znaku nie znaleziono. \n");
	printf("------------------------- \n\n");
}

void zad2() {
	printf("------------------------- \n");
	printf("Zad 2. Program usuwa pierwsze wystapienie danego znaku. \n");

	int p;
	char znak;
	char tekst[MAX_SIZE];
	printf("Wprowadz tekst: (maks. 255 znakow) \n");
	fgets(tekst, MAX_SIZE, stdin);
	printf("Wprowadz znak do usuniecia: \n");
	znak = getchar();
	clearBuffor();

	p = 0;
	while (tekst[p] != znak && tekst[p] != '\0') p++;

	if (tekst[p] == '\0') {
		printf("Znaku nie znaleziono. \n");
		printf("------------------------- \n\n");
		return;
	}

	while (tekst[p] != '\0') {
		tekst[p] = tekst[p+1];
		p++;
	}
	tekst[p] = tekst[p + 1];

	printf("Tekst po usunieciu znaku: \n");
	printf("%s", tekst);
	printf("------------------------- \n\n");
}

void zad3() {
	printf("------------------------- \n");
	printf("Zad 3. Program zamienia kazde wystapienie danego znaku. \n");

	int p = 0;
	char a, b;
	char tekst[MAX_SIZE];

	printf("Wprowadz tekst (maks. 255 znakow): \n");
	fgets(tekst, MAX_SIZE, stdin);
	printf("Wprowadz znak do zamienienia: \n");
	a = getchar();
	clearBuffor();
	printf("Wprowadz znak na ktory chcesz zamienic: \n");
	b = getchar();
	clearBuffor();

	while (tekst[p] != '\0') {
		if (tekst[p] == a) {
			tekst[p] = b;
		}
		p++;
	}

	printf("Tekst po zamianie: \n");
	printf("%s", tekst);
	printf("------------------------- \n\n");
}

void zad4() {
	printf("------------------------- \n");
	printf("Zad 4. Program laczy tekst do tekstu. \n");

	char tekst1[2*MAX_SIZE], tekst2[MAX_SIZE];
	
	printf("Wprowadz pierwszy tekst (maks. 255 znakow): \n");
	fgets(tekst1, MAX_SIZE, stdin);
	printf("Wprowadz drugi tekst (maks. 255 znakow): \n");
	fgets(tekst2, MAX_SIZE, stdin);


	tekst1[strlen(tekst1) - 1] = '\0';
	tekst2[strlen(tekst2) - 1] = '\0';

	printf("\nLacze teksty... \n");
	strcat(tekst1, tekst2);

	printf("Po polaczniu: \n");
	printf("%s \n", tekst1);
	printf("------------------------- \n\n");
}

void zad5() {
	printf("------------------------- \n");
	printf("Zad 5. Program laczy tekst od znaku o podanej pozycji na koniec innego tekstu. \n");

	int poz, ret = -1;
	char tekst1[MAX_SIZE], tekst2[2*MAX_SIZE];

	printf("Wprowadz pierwszy tekst (maks. 255 znakow): \n");
	fgets(tekst1, MAX_SIZE, stdin);
	printf("Wprowadz drugi tekst (maks. 255 znakow): \n");
	fgets(tekst2, MAX_SIZE, stdin);
	printf("Podaj pozycje od ktorej laczymy teksty: ");
	ret = scanf("%d", &poz);
	clearBuffor();

	if (ret != 1) {
		printf("Blad wczytywania! \n");
		printf("------------------------- \n\n");
		return;
	}

	if (poz > (int)strlen(tekst1)) {
		printf("Pozycja poza tekstem! \n");
		printf("------------------------- \n\n");
		return;
	}

	printf("\nLacze teksty... Na koniec drugiego doklejam pierwszy od %d znaku [liczac od zera] \n", poz);
	tekst2[strlen(tekst2) - 1] = '\0';
	strcat(tekst2, &tekst1[poz]);

	printf("Po polaczniu: \n");
	printf("%s \n", tekst2);
	printf("------------------------- \n\n");
}

void zad6() {
	printf("------------------------- \n");
	printf("Zad 6. Program przesuwa elementy tablicy o jedno miesjce w gore. \n");
	
	int tab[N] = { 2, 3, 5, 7, 11, 13, 17, 19, 21, 23 };
	
	printf("Mamy tablice: \n");
	for (int i = 0; i < 10; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n\n");

	int temp = tab[N - 1];
	for (int i = N - 1; i > 0; i--) {
		tab[i] = tab[i - 1];
	}
	tab[0] = temp;

	printf("Po przesunieciu: \n");
	for (int i = 0; i < N; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");

	printf("------------------------- \n\n");
}

int moje_strcmp(const char* str1, const char* str2) {
	while (*str1 == *str2) {
		if (*str1 == '\0' || *str2 == '\0')
			break;
		str1++;
		str2++;
	}

	if (*str1 == '\0' && *str2 == '\0')
		return 0;
	else {
		return *str1 - *str2;
	}
}

char* moje_strcat(char* strTo, const char* strFrom) {
	char* poz = strTo + strlen(strTo);

	while (*strFrom != '\0')
		*poz++ = *strFrom++;

	*poz = '\0';
	return strTo;
}

char* moje_strcpy(char* dest, const char* src) {
	if (dest == NULL) {
		return NULL;
	}

	char* poz = dest;

	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return poz;
}

void zad7() {
	printf("------------------------- \n");
	printf("Zad 7. Program testuje wlasne funkcje strcmp, strcat, strcpy. \n");

	char tekst1[2*MAX_SIZE], tekst2[2*MAX_SIZE], tekst3[MAX_SIZE], tekst4[MAX_SIZE];

	printf("Wprowadz pierwszy tekst (maks. 255 znakow): \n");
	fgets(tekst1, MAX_SIZE, stdin);
	printf("Wprowadz drugi tekst (maks. 255 znakow): \n");
	fgets(tekst2, MAX_SIZE, stdin);

	tekst1[strlen(tekst1)-1] = '\0';
	tekst2[strlen(tekst2)-1] = '\0';
	printf("\n");

	printf("Test moje_strcmp: \n");
	if (strcmp(tekst1, tekst2) == 0) {
		printf("strcmp: Teksty rowne! \n");
	}
	else {
		printf("strcmp: Teksty nie rowne! \n");
	}
	if (moje_strcmp(tekst1, tekst2) == 0) {
		printf("moje_strcmp: Teksty rowne! \n");
	}
	else {
		printf("moje_strcmp: Teksty nie rowne! \n");
	}
	printf("\n");

	printf("Test moje_strcpy: \n");
	strcpy(tekst3, tekst1);
	moje_strcpy(tekst4, tekst2);
	printf("strcpy: skopiowalem tekst1 do tekst3 \n");
	printf("Tekst 3: %s \n", tekst3);
	printf("moje_strcpy: skopiowalem tekst2 do tekst4 \n");
	printf("Tekst 4: %s \n", tekst4);
	printf("\n");

	printf("Test moje_strcat: \n");
	strcat(tekst1, tekst3);
	moje_strcat(tekst2, tekst4);
	printf("strcat: dopisuje tekst3 do tekst1 \n");
	printf("moje_strcat: dopisuje tekst4 do tekst2 \n");
	printf("Tekst1: %s \n", tekst1);
	printf("Tekst2: %s \n", tekst2);
	printf("\n");
}

int main(int argc, char* argv[]) {
	zad1();
	zad2();
	zad3();
	zad4();
	zad5();
	zad6();
	zad7();

	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;

	return 0;
}