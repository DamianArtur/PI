#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>

enum MY_INTERFACE {
	EMPTY,
	TOP,
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

void my_exit(int exit_code, node* stack) { //wlasna funkcja konczaca program

	node* tmp = NULL;

	while (stack != NULL) { //zwalnianie pamieci stosu
		tmp = stack;
		stack = stack->next;
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

int empty(node* stack) { //funkcja sprawdzająca czy stos jest pusty
	return (stack == NULL ? 1 : 0);
}

void top(node* stack) { //funkcja wypisuje pierwszy element stosu
	if (empty(stack) == 1) {
		printf("Stos jest pusty! \n\n");
		return;
	}
	printf("Odczytano: %s %s %s \n\n", stack->imie, stack->nazwisko, stack->data_urodzenia);
}

void push(node** stack) { //funkcja dodaje element do stosu
	node* new_node = NULL;
	new_node = (node*)malloc(sizeof(node)); //alokacja nowego wezla

	if (new_node == NULL) {
		printf("Blad alokacji! \n");
		my_exit(1, *stack);
		return;
	}

	new_node->next = NULL;

	int ret = -1;
	printf("Podaj imie, nazwisko i date urodzenia w formacie dd.mm.rrrr: \n"); //wczytanie danych
	ret = scanf("%s %s %s", &new_node->imie, &new_node->nazwisko, &new_node->data_urodzenia);

	if (ret == 0) {
		printf("Blad wczytywania! \n");
		free(new_node);
		my_exit(2, *stack);
		return;
	}

	new_node->next = *stack;
	*stack = new_node;
	
	printf("Zapisano \n\n");
}

void pop(node** stack) { //funkcja usuwa ostatni element ze stosu
	if (empty(*stack) == 1) {
		printf("Stos jest pusty! \n\n");
		return;
	}

	printf("Usunieto: %s %s %s \n\n", (*stack)->imie, (*stack)->nazwisko, (*stack)->data_urodzenia);

	node* tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

int main(int argc, char* argv[]) {

	enum MY_INTERFACE mode;
	int ret = -1;
	node* stack = NULL; //wskaznik na pierwszy element stosu

	printf("To jest implementacja stosu na liscie jednokierunkowej \n");

	while (1) {
		printf("------------------------------------------------------------ \n");
		printf("Wybierz funkcje: \n");
		printf("0 - empty, 1 - top, 2 - push, 3 - pop, 4 - exit: ");

		ret = scanf("%d", &mode);
		if (ret != 1) {
			printf("Blad wczytywania! \n");
			my_exit(2, stack);
		}

		switch (mode)
		{
		case EMPTY:
			if (empty(stack) == 1)
				printf("Stos jest pusty \n\n");
			else
				printf("Stos nie jest pusty \n\n");
			break;

		case TOP:
			top(stack);
			break;

		case POP:
			pop(&stack);
			break;

		case PUSH:
			push(&stack);
			break;

		case EXIT:
			my_exit(0, stack);
			break;

		default:
			printf("Podana opcja jest niepoprawna! Podaj liczbe z zakresu 0-4 \n\n");
			break;
		}
	}

	return 0;
}