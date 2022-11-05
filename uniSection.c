#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* insert(node* head, int data){
    node *ptr = (node*) malloc (sizeof(node)), *temp = head;
    ptr->data = data;
    if (temp == NULL)
    {
        ptr->next = NULL;
        return ptr;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = NULL;
        return head;
    }
}

void display(node* head){
    while(head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("Dis done\n");
}

void Union(node* a, node* b){
    node * ptr = (node*) malloc (sizeof(node));
    node *temp = ptr;
    temp->data = a->data;
    temp->next = NULL;
    while (a->next != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        a = a->next;
        temp->next = (node*) malloc (sizeof(node));
        temp = temp->next;
        temp->data = a->data;
        temp->next = NULL;
    }
    temp->next = (node*) malloc (sizeof(node));
    temp = temp->next;
    temp->data = b->data;
    temp->next = NULL;
    while (b->next != NULL)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        b = b->next;
        temp->next = (node*) malloc (sizeof(node));
        temp = temp->next;
        temp->data = b->data;
        temp->next = NULL;
    }
    display(ptr);
    return;
}

void Inter(node *a, node *b){
    node * temp = NULL, *ptr = NULL, *bp = b;
    while (a != NULL)
    {   
        while (bp != NULL)
        {
            if (a->data == bp->data)
            {
                if (!ptr)
                {
                    ptr = temp = (node*) malloc (sizeof(node));
                    temp->data = a->data;
                    temp->next = NULL;
                    break;
                }
                else{
                    temp->next = (node*) malloc (sizeof(node));
                    temp = temp->next;
                    temp->data = a->data;
                    temp->next = NULL;
                    break;
                }
            }
            else{
                bp = bp->next;
            }   
        }
        bp = b;
        a = a->next;
        
    }
    display(ptr);
}

int main(int argc, char const *argv[])
{
    node *a = NULL, *b = NULL;
    int x, y, val;
    printf("Enter the number of elements in A: ");
    scanf("%d", &x);
    printf("Enter set A:\n");
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &val);
        a = insert(a, val);
    }
    
    printf("Enter the number of elements in B: ");
    scanf("%d", &y);
    printf("Enter set B:\n");
    for (int i = 0; i < y; i++)
    {
        scanf("%d", &val);
        b = insert(b, val);
    }

    printf("Set A: ");
    display(a);
    printf("\n");
    printf("Set B: ");
    display(b);
    printf("\n");

    printf("Union: ");
    Union(a, b);
    printf("Intersection: ");
    Inter(a, b);
    return 0;
}
