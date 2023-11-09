#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    char *surname;
    struct node *left;
    struct node *right;
};

struct node* newNode(int number, char *surname) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    tmp->number = number;
    tmp->surname = surname;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
};

void print(struct node* node) {
    if(node == NULL) {
        printf("NO\n");
    } else {
    	printf("%s\n", node->surname);
    }
}

struct node* minimum(struct node* node) {
    struct node *tmp = node;
    
    while(tmp && tmp->left != NULL) {
        tmp = tmp->left;
    }
    
    return tmp;
}

struct node* add(struct node *root, int number, char *surname) {
    if(root == NULL) {
        return newNode(number, surname);
    }
    
    if(number < root->number) {
        root->left = add(root->left, number, surname);
    } else {
        root->right = add(root->right, number, surname);
    }
    
    return root;
}

struct node* remov(struct node *root, int number) {
    if(root == NULL) {
        return root;
    }
    
    if(number < root->number) {
        root->left = remov(root->left, number);
    } else if(number > root->number) {
        root->right = remov(root->right, number);
    } else {
        if(root->left == NULL) {
            struct node *tmp = root->right;
            free(root);
            return tmp;
        } else if(root->right == NULL) {
            struct node *tmp = root->left;
            free(root);
            return tmp;
        }
        
        struct node *tmp = minimum(root->right);
        root->number = tmp->number;
        root->right = remov(root->right, tmp->number);
    }
    
    return root;
}

struct node* find(struct node *root, int number) {
    if(root == NULL || root->number == number) {
        return root;
    }
    
    if(root->number < number) {
        return find(root->right, number);
    }
    
    return find(root->left, number);
}

int main() {
	int a = 0;
	int r = 0;
	int f = 0;
	scanf("%d", &a);
	scanf("%d", &r);
	scanf("%d", &f);
	
	struct node *tree = NULL;
	
	for(int i = 0; i < a; i++) {
		int number = 0;
		char *surname = (char*)malloc(32 * sizeof(char));
		scanf("%d", &number);
		scanf("%s", surname);
		tree = add(tree, number, surname);
	}
	
	for(int i = 0; i < r; i++) {
		int number = 0;
		scanf("%d", &number);
		tree = remov(tree, number);
	}
	
	for(int i = 0; i < f; i++) {
		int number = 0;
		scanf("%d", &number);
		print(find(tree, number));
	}
	
	return 0;
}
