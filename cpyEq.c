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

node * copy(node * n) {
    if (n == NULL)
        return NULL;
    node * new = createNode(n->val);
    new->left = copy(n->left);
    new->right = copy(n->right);

    return new;
}

int eqCheck(node * node1, node * node2) {
    if(!node1 && !node2){
        return 1;
    }
    if (!node1 || !node2 || node1->val != node2->val){
        return 0;
    }
    return eqCheck(node1->left,node2->left) && eqCheck(node1->right,node2->right);
}


int main() {
    node * tree = (node *) malloc(sizeof(node));
    node * treeCopy = (node *) malloc(sizeof(node));
    createBT(&tree);
    printf("Inorder : ");
    inOrder(tree);
    treeCopy = copy(tree);
    printf("\nInorder of copy: ");
    inOrder(treeCopy);
    int check = eqCheck(tree,treeCopy);
    if (check)
        printf("Binary trees are equal");
    else
        printf("Binary trees are not equal");
    printf("\n");
}