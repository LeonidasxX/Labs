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

node *delete(node* head, int value){
    node *p = head, *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
        return head;
    }
}

node *del(node* head){
    node *prev = NULL, *temp = NULL;
    temp = head->next;
    prev = head;
    while (temp != NULL)
    {
        if (temp->data == prev->data)
        {
            prev = prev->next;
            head = delete(head, temp->data);
            temp = temp->next;
        }
        else{
            temp = temp->next;
            prev = prev->next;
        }
        
    }
    return head;
}

int main(int argc, char const *argv[])
{
    node *a = NULL, *b;
    int x, val;
    printf("Enter the number of elements in A in sorted order: ");
    scanf("%d", &x);
    printf("Enter set A:\n");
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &val);
        a = insert(a, val);
    }

    printf("Set A: ");
    display(a);
    printf("\n");

    b = del(a);
    printf("After removing duplicate elements: ");
    display(b);
    
    return 0;
}