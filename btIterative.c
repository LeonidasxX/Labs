#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node * left;
    struct node * right;
} node ;

node * createNode(int x) {
    node * new = (node *) malloc(sizeof(node));
    new->val = x;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void inOrder(node *tree) {
    if (tree != NULL) {
        inOrder(tree->left);
        printf("%d ",tree->val);
        inOrder(tree->right);
    }
}

void postOrder(node *tree) {
    if (tree != NULL) {
        postOrder(tree->left);
        postOrder(tree->right);
        printf("%d ",tree->val);
    }
}

void preOrder(node *tree) {
    if (tree != NULL) {
        printf("%d ",tree->val);
        preOrder(tree->left);
        preOrder(tree->right);
    }
}
void createBT(node ** tree) {
    node * iter = (node *) malloc(sizeof(node));
    node * prev = (node *) malloc(sizeof(node));
    node * root = (node *) malloc(sizeof(node));
    iter = NULL;
    int x;
    int inp = 0;
    printf("Enter value of root ");
    scanf("%d",&x);
    iter = createNode(x);
    root = iter;
    *tree = iter;
    prev = iter;

    printf("\n1. Enter left, 2. Enter right, 3. Move up, -1. Exit");

    do {
        printf("\nEnter choice ");
        scanf("%d",&inp);
        if (inp == 1) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            node * temp = createNode(x);
            prev = iter;
            iter->left = temp;
            iter = iter->left;
            printf("Moved left");
        }
        else if (inp == 2) {
            printf("Enter value to insert ");
            scanf("%d",&x);
            node * temp = createNode(x);
            prev = iter;
            iter->right = temp;
            iter = iter->right;
            printf("Moved right");
        }
        else if (inp == 3) {
            if (iter == root) {
                printf("Already at root");
            }
            else {
                iter = prev;
                printf("Moved up");
            }
        }
        else 
            inp = -1;
    } while(inp != -1);
}

int main() {
    node * tree = (node *) malloc(sizeof(node));
    createBT(&tree);
    printf("Inorder : ");
    inOrder(tree);
    printf("\nPre-Order : ");
    preOrder(tree);
    printf("\nPost-Order : ");
    postOrder(tree);
    return 0;
}









