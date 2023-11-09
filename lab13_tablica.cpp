#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define N 10
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
} node;

void my_exit(int exit_code) { //wlasna funkcja konczaca program

	printf("\n");
	printf("-------------------------------------------------------------- \n");
	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;
	exit(exit_code);
}

int empty(int* sptr) { //funkcja sprawdzająca czy stos jest pusty
	return (*sptr == 0) ? 1 : 0;
}

void top(node stack[N], int* sptr) { //funkcja wypisuje pierwszy element stosu
	if (empty(sptr) == 1) {
		printf("Stos jest pusty! \n\n");
		return;
	}
	printf("Odczytano: %s %s %s \n\n", stack[*sptr-1].imie, stack[*sptr-1].nazwisko, stack[*sptr-1].data_urodzenia);
}

void push(node stack[N], int* sptr) { //funkcja dodaje element do stosu

	if (*sptr == N) {
		printf("Stos jest pelny! \n\n");
		return;
	}

	int ret = -1;
	printf("Podaj imie, nazwisko i date urodzenia w formacie dd.mm.rrrr: \n"); //wczytanie danych
	ret = scanf("%s %s %s", stack[*sptr].imie, stack[*sptr].nazwisko, stack[*sptr].data_urodzenia);

	if (ret == 0) {
		printf("Blad wczytywania! \n");
		my_exit(2);
		return;
	}

	(*sptr)++;
	printf("Zapisano \n\n");
}

void pop(node stack[N], int* sptr) { //funkcja usuwa ostatni element ze stosu
	if (empty(sptr) == 1) {
		printf("Stos jest pusty! \n\n");
		return;
	}

	(*sptr)--;

	printf("Usunieto: %s %s %s \n\n", stack[*sptr].imie, stack[*sptr].nazwisko, stack[*sptr].data_urodzenia);
}

int main(int argc, char* argv[]) {

	enum MY_INTERFACE mode;
	int ret = -1;
	int n = 0; //wskaznik stosu tablicy
	int* sptr = &n;
	node stack[N]; //tablica ze stosem

	printf("To jest implementacja stosu na tablicy rozmiaru 10 \n");

	while (1) {
		printf("------------------------------------------------------------ \n");
		printf("Wybierz funkcje: \n");
		printf("0 - empty, 1 - top, 2 - push, 3 - pop, 4 - exit: ");

		ret = scanf("%d", &mode);
		if (ret != 1) {
			printf("Blad wczytywania! \n");
			my_exit(2);
		}

		switch (mode)
		{
		case EMPTY:
			if (empty(sptr) == 1)
				printf("Stos jest pusty \n\n");
			else
				printf("Stos nie jest pusty \n\n");
			break;

		case TOP:
			top(stack, sptr);
			break;

		case POP:
			pop(stack, sptr);
			break;

		case PUSH:
			push(stack, sptr);
			break;

		case EXIT:
			my_exit(0);
			break;

		default:
			printf("Podana opcja jest niepoprawna! Podaj liczbe z zakresu 0-4 \n\n");
			break;
		}
	}

	return 0;
}