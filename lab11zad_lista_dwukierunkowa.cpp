#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char imie[256];
	char nazwisko[256];
	char data_urodzenia[256];
	char adres[256];
	int stypendium;
	struct NODE* next;
	struct NODE* prev;
} node;

void my_exit(int exit_code, FILE* fp = NULL, node* head = NULL, node* tail = NULL) {

	if (fp != NULL) {
		fclose(fp);
		fp = NULL;
	}

	node* tmp = NULL;
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}

	printf("\n");
	printf("-------------------------------------------------------------- \n");
	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;
	exit(exit_code);
}

void inicjalizacja(node*& head, node*& tail) { //wczytanie z pliku danych do listy
	FILE* fp = NULL;

	head = (node*)malloc(sizeof(node)); //utworzenie wartownika z lewej
	if (!head) {
		printf("Blad alokacji! \n");
		my_exit(1, fp);
		return;
	}

	tail = head;
	head->next = NULL;
	head->prev = NULL;

	fp = fopen("dane.txt", "r"); //otwieranie pliku
	if (fp == NULL) {
		printf("Nie moge otworzyc pliku dane.txt, moze taki plik nie istnieje? \n");
		printf("------------------------------------------------------------------------------------------------------- \n\n");
		my_exit(1, fp, head);
		return;
	}

	int ret = -1;
	while (1) { //wczytwanie danych z pliku
		node* new_node = NULL;
		new_node = (node*)malloc(sizeof(node));
		if (!new_node) {
			printf("Blad alokacji! \n");
			my_exit(1, fp, head);
			return;
		}

		ret = fscanf(fp, "%s", &new_node->imie);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%s", &new_node->nazwisko);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%s", &new_node->data_urodzenia);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%s", &new_node->adres);
		if (ret == EOF)	break;
		ret = fscanf(fp, "%d", &new_node->stypendium);
		if (ret == EOF)	break;
		
		if (head == tail) {
			tail = new_node;
		}
		new_node->next = head->next;
		new_node->prev = head;
		head->next = new_node;
	}

	if (fp != NULL) {
		fclose(fp); //zamykanie pliku
		fp = NULL;
	}
}

void najwieksze_stypendium(node* head, node* tail) { //funkcja wyszukujaca studenta o najwiekszym stypendium
	if (head->next == NULL) {
		printf("Lista jest pusta! \n");
		return;
	}

	int max_val = INT_MIN;
	node* max = head->next;

	while (head != NULL) {
		if (max_val < head->stypendium) {
			max_val = head->stypendium;
			max = head;
		}
		head = head->next;
	}

	printf("Najwieksze stypendium otrzymuje %s %s o wartosci %d. \n", max->imie, max->nazwisko, max->stypendium);
}

void wyswietl_liste(node* head, node* tail) { //funkcja wyswietlajaca liste
	if (head->next == NULL) {
		printf("Lista pusta! \n");
		return;
	}

	head = head->next;

	while (head != NULL) {
		printf("%s %s %s %s %d zl \n", head->imie, head->nazwisko, head->data_urodzenia, head->adres, head->stypendium);
		head = head->next;
	}
}

void dodaj_na_poczatek(node*& head, node*& tail, const char imie[256], const char nazwisko[256], const char data_urodzenia[256], const char adres[256], int stypendium) { //funkcja dodaje na poczatek listy
	node* new_node = NULL;
	new_node = (node*)malloc(sizeof(node));
	if (!new_node) {
		printf("Blad alokacji! \n");
		return;
	}
	new_node->next = NULL;
	new_node->prev = NULL;

	strcpy(new_node->imie, imie);
	strcpy(new_node->nazwisko, nazwisko);
	strcpy(new_node->data_urodzenia, data_urodzenia);
	strcpy(new_node->adres, adres);
	new_node->stypendium = stypendium;

	if (head == tail) {
		tail = new_node;
	}

	new_node->next = head->next;
	new_node->prev = head;
	head->next = new_node;
}

void dodaj_na_koniec(node*& head, node*& tail, const char imie[256], const char nazwisko[256], const char data_urodzenia[256], const char adres[256], int stypendium) { //funkcja dodaje na koniec listy
	node* new_node = NULL;
	new_node = (node*)malloc(sizeof(node));
	if (!new_node) {
		printf("Blad alokacji! \n");
		return;
	}
	new_node->next = NULL;
	new_node->prev = NULL;

	strcpy(new_node->imie, imie);
	strcpy(new_node->nazwisko, nazwisko);
	strcpy(new_node->data_urodzenia, data_urodzenia);
	strcpy(new_node->adres, adres);
	new_node->stypendium = stypendium;

	new_node->prev = tail;
	new_node->next = tail->next;
	tail->next = new_node;
	tail = new_node;
}

int dlugosc_listy(node* head, node* tail) { //funkcja zwraca dlugosc listy
	int licznik = 0;

	while (head->next != NULL) {
		head = head->next;
		licznik++;
	}

	return licznik;
}

void usun_z_poczatku(node* head, node* tail) { //funkcja usuwania z poczatku listy
	if (!head->next) //gdy lista byla juz pusta
		return;

	node* ptr = head->next;
	head->next = ptr->next;
	free(ptr);
}

void usun_z_konca(node* head, node* tail) { //funkcja usuwania z konca listy
	if (!head->next) //gdy lista byla juz pusta
		return;

	node* ptr = tail->prev;
	ptr->next = tail->next;
	free(tail);
	tail = ptr;
}

int main(int argc, char* argv[]) { //sprawdzenie poprawnosci pozwyzszych funkcji

	node* head = NULL;
	node* tail = NULL;

	printf("Inicjalizacja listy... \n");
	inicjalizacja(head, tail);
	printf("-------------------------------------------------------------- \n");
	najwieksze_stypendium(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Lista: \n");
	wyswietl_liste(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Dodanie na poczatku listy \n");
	dodaj_na_poczatek(head, tail, "Anna", "Nowak", "01.01.2000", "Krakow", 1000);
	printf("Dodanie na koniec listy \n");
	dodaj_na_koniec(head, tail, "Jan", "Kowalski", "31.12.1999", "Warszawa", 3000);

	printf("-------------------------------------------------------------- \n");
	printf("Lista: \n");
	wyswietl_liste(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Lista ma dlugosc %d \n", dlugosc_listy(head, tail));

	printf("-------------------------------------------------------------- \n");
	printf("Usuwanie z poczatku listy \n");
	usun_z_poczatku(head, tail);
	printf("Usuwanie z konca listy \n");
	usun_z_konca(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Lista: \n");
	wyswietl_liste(head, tail);

	my_exit(0, NULL, head, tail);
	return 0;
}