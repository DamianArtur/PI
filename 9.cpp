#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

typedef struct node {
    int key;
    struct node *next[];
} node;

typedef struct skiplist {
    int level;
    struct node *head;
} skiplist;

static int rand_level(int h) {
    int level = 1;
    
    while (rand() < RAND_MAX / 2 && level < h){
    	level++;
	}
	
    return level;
}

skiplist* init_skiplist(skiplist *list, int h) {
    node *head = (node*)malloc(sizeof(struct node) + (h + 1) * sizeof(node));
    
    list->head = head;
    
    head->key = INT_MAX;
    for (int i = 0; i <= h; i++) {
        head->next[i] = list->head;
    }

    list->level = 1;

    return list;
}

void delete_skiplist(skiplist *list) {
	node *x = list->head;
	
    while (x && x->next[1] != list->head) {
        x = x->next[1];
    }
	
    node *current_node = list->head->next[1];
    
    while(current_node != list->head) {
        node *next_node = current_node->next[1];
        free(current_node);
        current_node = next_node;
    }
    
    free(current_node);
    free(list);
}

void add(skiplist *list, int value, int h) {
	int level;
	int key = value;
	
	node *update[h + 1];
    node *x = list->head;
    
    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->key < key) {
        	x = x->next[i];
		}
        update[i] = x;
    }
    
    x = x->next[1];

    if (key == x->key) {
        return;
    } else {
        level = rand_level(h);
        if (level > list->level) {
            for (int i = list->level + 1; i <= level; i++) {
                update[i] = list->head;
            }
            list->level = level;
        }

        x = (node*)malloc(sizeof(node) + (level + 1) * sizeof(node*));
        x->key = key;
        for (int i = 1; i <= level; i++) {
            x->next[i] = update[i]->next[i];
            update[i]->next[i] = x;
        }
    }
}

void find(skiplist *list, int key) {
    node *x = list->head;
    
    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->key < key) {
        	x = x->next[i];
		} 
    }
    
    if (x->next[1]->key == key) {
    	printf("Y\n");
    } else {
    	printf("N\n");
    }
}

void remov(skiplist *list, int key, int h) {
    node *update[h + 1];
    node *x = list->head;
    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->key < key) {
            x = x->next[i];
		}
        update[i] = x;
    }
    x = x->next[1];
    if (x->key == key) {
        for (int i = 1; i <= list->level; i++) {
            if (update[i]->next[i] != x) {
            	break;
			}
            update[i]->next[i] = x->next[i];
        }
        
        if (x) {
        	free(x);
    	}

        while (list->level > 1 && list->head->next[list->level] == list->head) {
        	list->level--;
		}
    }
}

int main() {
	int z = 0;
	scanf("%d", &z);
	
	for(int i = 0; i < z; i++) {
		int h = 0;
		int a = 0;
		int r = 0;
		int f = 0;
		scanf("%d", &h);
		scanf("%d", &a);
		scanf("%d", &r);
		scanf("%d", &f);
			
	    skiplist *list;
	    list = (skiplist*)malloc(sizeof(skiplist));
	    init_skiplist(list, h);
		
		for(int i = 0; i < a; i++) {
			int number = 0;
			scanf("%d", &number);
			add(list, number, h);
		}
		
		for(int i = 0; i < r; i++) {
			int number = 0;
			scanf("%d", &number);
    		remov(list, number, h);
		}
		
		for(int i = 0; i < f; i++) {
			int number = 0;
			scanf("%d", &number);
			find(list, number);
		}
		
    	delete_skiplist(list);
	}
	
	return 0;
}
