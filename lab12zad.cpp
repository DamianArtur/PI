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

int dlugosc_listy(node* head, node* tail) { //funkcja zwraca dlugosc listy
	int licznik = 0;

	while (head->next != NULL) {
		head = head->next;
		licznik++;
	}

	return licznik;
}

void bubbleSort_1(int rozmiar, node* head) //sortowanie listy po kwotach stypendium
{
	node* ptr;
	node* node_prev;
	node* node_next;
	node* node_next_2;

	for (node_prev = head; node_prev->next!= NULL; node_prev = node_prev->next) {
		for (node_next_2 = node_prev; node_next_2->next != NULL; node_next_2 = node_next_2->next) {
			if (node_next_2->stypendium > node_next_2->next->stypendium) {

				node_next = node_next_2->next;
				ptr = node_next_2->prev;

				if (ptr != NULL) {
					ptr->next = node_next;
				}
					
				if (node_next->next != NULL) {
					node_next->next->prev = node_next_2;
				}

				node_next_2->next = node_next->next;
				node_next_2->prev = node_next->prev;
				node_next->next = node_next_2;
				node_next->prev = ptr;
			}
		}
	}
}

void bubbleSort_2(int rozmiar, node* head) //sortowanie listy po nzwiskach
{
	node* ptr;
	node* node_prev;
	node* node_next;
	node* node_next_2;

	for (node_prev = head; node_prev->next != NULL; node_prev = node_prev->next) {
		for (node_next_2 = node_prev; node_next_2->next != NULL; node_next_2 = node_next_2->next) {
			if (strcmp(node_next_2->nazwisko, node_prev->next->nazwisko) > 0) {

				node_next = node_next_2->next;
				ptr = node_next_2->prev;

				if (ptr != NULL) {
					ptr->next = node_next;
				}

				if (node_next->next != NULL) {
					node_next->next->prev = node_next_2;
				}

				node_next_2->next = node_next->next;
				node_next_2->prev = node_next->prev;
				node_next->next = node_next_2;
				node_next->prev = ptr;
			}
		}
	}
}

int compare(node* node_1, node* node_2, int tryb) {
	if (tryb == 0) {
		return strcmp(node_1->imie, node_2->imie);
	}
	else if (tryb == 1) {
		return strcmp(node_1->nazwisko, node_2->nazwisko);
	}
	else if (tryb == 2) {
		return strcmp(node_1->adres, node_2->adres);
	}
	else if (tryb == 3) {
		return strcmp(node_1->data_urodzenia, node_2->data_urodzenia);
	}
	else if (tryb == 4) {
		return node_1->stypendium - node_2->stypendium;
	}
}

void bubbleSort_3(int rozmiar, node* head, int tryb) //sortowanie listy po dowolnym polu
{
	node* ptr;
	node* node_prev;
	node* node_next;
	node* node_next_2;

	for (node_prev = head; node_prev->next != NULL; node_prev = node_prev->next) {
		for (node_next_2 = node_prev; node_next_2->next != NULL; node_next_2 = node_next_2->next) {
			if (compare(node_next_2, node_prev->next, tryb) > 0) {

				node_next = node_next_2->next;
				ptr = node_next_2->prev;

				if (ptr != NULL) {
					ptr->next = node_next;
				}

				if (node_next->next != NULL) {
					node_next->next->prev = node_next_2;
				}

				node_next_2->next = node_next->next;
				node_next_2->prev = node_next->prev;
				node_next->next = node_next_2;
				node_next->prev = ptr;
			}
		}
	}
}

void dodaj_do_posortowanej(node* head, node* tail) { //wstawianie do posortowanej listy
	node* new_node = NULL;
	new_node = (node*)malloc(sizeof(node)); 
	if (!new_node) {
		printf("Blad alokacji! \n");
		my_exit(3, NULL, head, tail);
	}
	new_node->prev = NULL;
	new_node->next = NULL;

	strcpy(new_node->imie, "Jan");
	strcpy(new_node->nazwisko, "Kowalski");
	strcpy(new_node->data_urodzenia, "01.01.2000");
	strcpy(new_node->adres, "Krakow");
	new_node->stypendium = 1000;

	node* ptr = head->next;

	while (ptr != tail && ptr->stypendium > new_node->stypendium) {
		ptr = ptr->next;
	}

	new_node->prev = ptr->prev->prev;
	new_node->next = ptr;
	ptr->prev->next = new_node;
	ptr->prev = new_node;
}

int main(int argc, char* argv[]) {

	node* head = NULL;
	node* tail = NULL;

	printf("Inicjalizacja listy... \n");
	inicjalizacja(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Lista: \n");
	wyswietl_liste(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Sortuje liste: \n");
	bubbleSort_1(dlugosc_listy(head, tail), head);

	printf("-------------------------------------------------------------- \n");
	printf("Lista: \n");
	wyswietl_liste(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Dodaje do posortowanej listy: \n");
	dodaj_do_posortowanej(head, tail);

	printf("-------------------------------------------------------------- \n");
	printf("Lista: \n");
	wyswietl_liste(head, tail);

	my_exit(0, NULL, head, tail);
	return 0;
}