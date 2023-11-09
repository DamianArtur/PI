#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define N 10
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
} node;

void my_exit(int exit_code) {

	printf("\n");
	printf("-------------------------------------------------------------- \n");
	printf("Wyjscie - Ctrl + Z Enter \n");
	int ch;
	while ((ch = getchar()) != EOF)
		;
	exit(exit_code);
}

int empty(int* qcnt) { //funkcja sprawdzająca czy kolejka jest pusta
	return (*qcnt == 0) ? 1 : 0;
}

void front(node queue[N], int* qcnt, int* qptr) { //funkcja wypisuje pierwszy element kolejki
	if (empty(qcnt) == 1) {
		printf("Kolejka jest pusta! \n\n");
		return;
	}
	printf("Odczytano: %s %s %s \n\n", queue[*qptr].imie, queue[*qptr].nazwisko, queue[*qptr].data_urodzenia);
}

void push(node queue[N], int* qcnt, int* qptr) { //funkcja dodaje element do kolejki

	if (*qcnt == N) {
		printf("Kolejka jest pelna! \n\n");
		my_exit(3);
	}

	int i = *qptr + *qcnt;
	if (i >= N) {
		i = i - N;
	}

	int ret = -1;
	printf("Podaj imie, nazwisko i date urodzenia w formacie dd.mm.rrrr: \n"); //wczytanie danych
	ret = scanf("%s %s %s", queue[i].imie, queue[i].nazwisko, queue[i].data_urodzenia);

	if (ret == 0) {
		printf("Blad wczytywania! \n");
		my_exit(2);
		return;
	}

	(*qcnt)++;
	printf("Zapisano \n\n");
}

void pop(node queue[N], int* qcnt, int* qptr) { //funkcja uwyjmuje element z kolejki
	if (empty(qcnt) == 1) {
		printf("Kolejka jest pusta! \n\n");
		return;
	}

	printf("Usunieto: %s %s %s \n\n", queue[*qptr].imie, queue[*qptr].nazwisko, queue[*qptr].data_urodzenia);

	(*qcnt)--;
	(*qptr)++;
	if (*qptr == N) {
		*qptr = 0;
	}
}

int main(int argc, char* argv[]) {

	enum MY_INTERFACE mode;
	int ret = -1;
	int ptr = 0; //wskaznik poczatku kolejki
	int cnt = 0; //wskaznik rozmiaru kolejki
	int* qptr = &ptr;
	int* qcnt = &cnt;
	node queue[N]; //tablica z kolejka

	printf("To jest implementacja kolejki na tablicy rozmiaru 10 \n");

	while (1) {
		printf("------------------------------------------------------------ \n");
		printf("Wybierz funkcje: \n");
		printf("0 - empty, 1 - front, 2 - push, 3 - pop, 4 - exit: ");

		ret = scanf("%d", &mode);
		if (ret != 1) {
			printf("Blad wczytywania! \n");
			my_exit(2);
		}

		switch (mode)
		{
		case EMPTY:
			if (empty(qcnt) == 1)
				printf("Kolejka jest pusta \n\n");
			else
				printf("Kolejka nie jest pusta \n\n");
			break;

		case FRONT:
			front(queue, qcnt, qptr);
			break;

		case POP:
			pop(queue, qcnt, qptr);
			break;

		case PUSH:
			push(queue, qcnt, qptr);
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