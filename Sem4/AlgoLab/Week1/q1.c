#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int val;
	struct Node * left;
	struct Node * right;
} node;

node * createNode (int key) {
	node * new = (node *) malloc (sizeof(node));
	new->val = key;
	new->left = NULL;
	new->right = NULL;
	return new;
}

void inOrder(node *tree){
	if(!tree){
		return;
	}
	inOrder(tree->left);
	printf("%d ", tree->val);
	inOrder(tree->right);
}

void postOrder(node *tree){
	if(!tree){
		return;
	}
	postOrder(tree->left);
	
	postOrder(tree->right);
	printf("%d", tree->val);
}


void preOrder(node *tree){
	if(!tree){
		return;
	}
	printf("%d", tree->val);
	preOrder(tree->left);
	
	preOrder(tree->right);
}


int checkBst(node *tree, int key){
	if(tree == NULL){
		
		printf("Value not found, inserting value\n");
		return 0;
	}
	else{
		if(tree->val == key){
			printf("Key Found\n");
			return 1;

		}
		else if(key > tree->val){
			checkBst(tree->right, key);
		}
		else{
			checkBst(tree->left, key);
		}
	}
}

void insert(node **tree, int key){
	node * iter = (node *) malloc(sizeof(node));
    node * prev = (node *) malloc(sizeof(node));
    node * root = (node *) malloc(sizeof(node));
    node * temp = (node *) malloc(sizeof(node));
    
    if (checkBst(*tree, key) == 1)
    {
    	return;
    }

    temp = createNode(key);
    prev = NULL;
    root = *tree;
    iter = root;
    while (iter != NULL) {
        prev = iter;
        if (iter->val > key)
            iter = iter->left;
        else
            iter = iter->right;
    }
    if (prev == NULL) 
        *tree = temp;
    else if (key < prev->val) 
        if (prev->left != NULL) {
            temp->left = prev->left;
            prev->left = temp;
        }
        else 
            prev->left = temp;
    else {
        if (prev->right != NULL) {
            temp->right = prev->right;
            prev->right = temp;
        }
        else 
            prev->right = temp;

    }
}

int main(){
	int key = 1;
	node * tree = (node *) malloc(sizeof(node));
	tree = NULL;
	while(key != 0){
		printf("Intsert the key: ");
		scanf("%d", &key);
		insert(&tree, key);
	}
	inOrder(tree);
	printf("\n\n");
	postOrder(tree);
	printf("\n\n");
	preOrder(tree);
}
