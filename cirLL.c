#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char data;
    struct node* next;
}node;

node* create(node* head){
    node *new, *temp;
    int choice = 1;
    while(choice > 0){
        new = (node*) malloc (sizeof(node));
        printf("Enter data: ");
        scanf(" %c", &new->data);
        new->next = NULL;
        if (head == NULL)
        {
            head = temp = new;
        }
        else{
            temp->next = new;
            temp = new;
            temp->next = head;
        }
        printf("Enter choice: ");
        scanf("%d", &choice);
    }
    return head;
}

void display(node* head){
    node * temp;
    if (head == NULL)
    {
        printf("Empty list...\n");
    }
    else{
        temp = head;
        while (temp->next != head)
        {
            printf("%c -> ", temp->data);
            temp = temp->next;
        }
        printf("%c", temp->data);
        
    }
    
}

node *sorted(node *a, node *b){
    node *pa = a, *pb = b;
    node *head = NULL, *temp;
    while (pa != NULL && pb != NULL)
    {
        if (pa->data < pb->data)
        {
            if (!head)
            {
                head = temp = (node*) malloc (sizeof(node));
                temp->data = pa->data;
                temp->next = NULL;
                pa = pa->next;
                display(head);

            }
            else{
                temp->data = pa->data;
                temp->next = NULL;
                pa = pa->next;
                display(head);
            }  
        }
        else{
           if (!head)
            {
                head = temp = (node*) malloc (sizeof(node));
                temp->data = pb->data;
                temp->next = NULL;
                pb = pb->next;
                display(head);
            }
            else{
                temp->data = pb->data;
                temp->next = NULL;
                pb = pb->next;
                display(head);
            }   
        }
    }
    return head;
}

int main(int argc, char const *argv[])
{
    node *a = NULL, *b = NULL, *c = NULL;
    a = create(a);
    display(a);
    printf("\n");
    b = create(b);
    display(b);
    printf("\n");
    c = sorted(a, b);
    return 0;
}
