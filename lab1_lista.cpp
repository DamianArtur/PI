#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>

enum MY_INTERFACE {
	EMPTY,
	FRONT,
	PUSH,
	POP,
	EXIT
};

typedef struct NODE {
	char imie[256];
	char nazwisko[256];
	char data_urodzenia[11]; //dd.mm.rrrr\0
	struct NODE* next;
} node;

void my_exit(int exit_code, node* head) { //wlasna funkcja konczaca program

	node* tmp = NULL;

	while (head != NULL) { //zwalnianie pamieci kolejki
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

int empty(node* head) { //spr czy kolejka jest pusta
	return (head == NULL ? 1 : 0);
}

void front(node* head) { //funkcja wypisuje poczatek kolejki
	if (empty(head) == 1) {
		printf("Kolejka jest pusta! \n\n");
		return;
	}
	printf("Odczytano: %s %s %s \n\n", head->imie, head->nazwisko, head->data_urodzenia);
}

void push(node** head, node** tail) { //funkcja dodaje element do kolejki
	node* new_node = NULL;
	new_node = (node*)malloc(sizeof(node)); //alokacja nowego wezla

	if (new_node == NULL) {
		printf("Blad alokacji! \n");
		my_exit(1, *head);
		return;
	}

	new_node->next = NULL;

	int ret = -1;
	printf("Podaj imie, nazwisko i date urodzenia w formacie dd.mm.rrrr: \n"); //wczytanie danych
	ret = scanf("%s %s %s", &new_node->imie, &new_node->nazwisko, &new_node->data_urodzenia);

	if (ret == 0) {
		printf("Blad wczytywania! \n");
		free(new_node);
		my_exit(2, *head);
		return;
	}

	if (*tail != NULL) {
		(*tail)->next = new_node;
	}
	else {
		(*head) = new_node;
	}
	*tail = new_node;

	printf("Zapisano \n\n");
}

void pop(node** head, node** tail) { //funkcja wyjmuje element z kolejki
	if (empty(*head) == 1) {
		printf("Kolejka jest pusta! \n\n");
		return;
	}

	printf("Usunieto: %s %s %s: \n\n", (*head)->imie, (*head)->nazwisko, (*head)->data_urodzenia);

	node* tmp = *head;
	*head = (*head)->next;
	free(tmp);
	if (*head == NULL) {
		*tail = NULL;
	}
}

int main(int argc, char* argv[]) {

	enum MY_INTERFACE mode;
	int ret = -1;
	node* head = NULL; //wskaznik na pierwszy element kolejki
	node* tail = NULL; //wskaznik na ostatni element kolejki

	printf("To jest implementacja kolejki na liscie jednokierunkowej \n");

	while (1) {
		printf("------------------------------------------------------------ \n");
		printf("Wybierz funkcje: \n");
		printf("0 - empty, 1 - front, 2 - push, 3 - pop, 4 - exit: ");

		ret = scanf("%d", &mode);
		if (ret != 1) {
			printf("Blad wczytywania! \n");
			my_exit(2, head);
		}

		switch (mode)
		{
		case EMPTY:
			if (empty(head) == 1)
				printf("Kolejka jest pusta \n\n");
			else
				printf("Kolejka nie jest pusta \n\n");
			break;

		case FRONT:
			front(head);
			break;

		case POP:
			pop(&head, &tail);
			break;

		case PUSH:
			push(&head, &tail);
			break;

		case EXIT:
			my_exit(0, head);
			break;

		default:
			printf("Podana opcja jest niepoprawna! Podaj liczbe z zakresu 0-4 \n\n");
			break;
		}
	}

	return 0;
}