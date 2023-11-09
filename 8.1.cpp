#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char surname[32];
    char number[32];
    struct Node *next;
} Node;

int Hash(char *a, int n) {
	int i = 0;
	int sum = 0;
	while(a[i] != '\0') {
		sum += a[i];
		i++;
	}
	return sum % n;
}

void print(char *a) {
	int i = 0;
	while(a[i] != '\0') {
		printf("%c", a[i]);
		i++;
	}
	printf("\n");
}

void add(Node **tab, int n, char *surname, char *number) {
	int hash = Hash(surname, n);
	Node *p = tab[hash];
	
	Node *N = (Node*)malloc(sizeof(Node));
	for(int i = 0; i < 32; i++) {
		N->surname[i] = surname[i];
		N->number[i] = number[i];
	}
	
	N->next = p->next;
	p->next = N;
}


void remov(Node **tab, int n, char *surname) {
	int hash = Hash(surname, n);
	Node *p = tab[hash]->next;
	Node *q = tab[hash];

	while(strcmp(p->surname, surname) != 0) {
		p = p->next;
		q = q->next;
	}
	
	q->next = q->next->next;
	free(p);	
}

void get(Node **tab, int n, char *surname) {
	int hash = Hash(surname, n);
	Node *p = tab[hash];
	
	if(p->next == NULL) {
		printf("\n");
		return;
	}
	
	while(p != NULL && strcmp(p->surname, surname) != 0) {
		p = p->next;
	}
	
	if(p == NULL) {
		printf("\n");
		return;
	} else {
		print(p->number);
	}
}
 
int main() {
	int z = 0;
	scanf("%d", &z);
	
	for(int i = 0; i < z; i++) {
		int n = 0;
		int k = 0;
		scanf("%d", &n);
		scanf("%d", &k);
		
		Node **tab = (Node**)malloc(n * sizeof(Node*));
		for(int i = 0; i < n; i++) {
			tab[i] = (Node*)malloc(sizeof(Node));
			tab[i]->next = NULL;
		}
		
		for(int j = 0; j < k; j++) {
			char type;
			char surname[32];
			char number[32];
			
			scanf(" %c", &type);
			
			if(type == 'a') {
				scanf("%s", &surname);
				scanf("%s", &number);
				add(tab, n, surname, number);
			}
			if(type == 'r') {
				scanf("%s", &surname);
				remov(tab, n, surname);
			}
			if(type == 'g') {
				scanf("%s", &surname);
				get(tab, n, surname);
			}
		}
	}
}
