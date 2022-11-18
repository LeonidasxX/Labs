#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    char data;
    struct node* next;
}node;

void display(node *head){
    while(head){
        printf("%c -> ", head->data);
        head = head->next;
    }
}

node* insertAtEnd(node* head, char data){
    node* ptr = (node*) malloc (sizeof(node));
    ptr->data = data;
    ptr->next = NULL;
    if (!head)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    else{
        node* temp = head;
        while (temp->next!=NULL)
        {
            temp = temp->next;            
        }
        temp->next = ptr;
        ptr->prev = temp;
        return head;
    }
}

node* insertAtFirst(node* head, char data){
    node* ptr = (node*) malloc (sizeof(node));
    ptr->data = data;
    ptr->prev = NULL;
    if (!head)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    else{
        ptr->next = head;
        head->prev = ptr;
        return ptr;
    }
}

node* reverse(node* head){
    node* temp = head;
    node* new = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp->prev != NULL)
    {
        new = insertAtEnd(new, temp->data);
        temp = temp->prev;
    }
    new = insertAtEnd(new, temp->data);
    return new;
}


int main(int argc, char const *argv[])
{
    node* head = NULL;
    int c, flag = 1;
    char val;

    printf("Operations:\n");
    printf("1. Insert at beginning\n2. Insert At End\n3. Reverse\n4. Display\n5.Exit\n");
    while (flag!=0)
    {
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter Value: ");
            scanf(" %c", &val);
            head = insertAtFirst(head, val);
            break;
        case 2:
            printf("Enter Value: ");
            scanf(" %c", &val);
            head = insertAtEnd(head, val);
            break;
        case 3:
            head = reverse(head);
            break;
        case 4:
            display(head);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            flag = 0;
            break;
        default:
            printf("Invalid Input...\n");
            break;
        }
    }
    
    return 0;
}
