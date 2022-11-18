#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}node;

void display(node *head){
    while(head){
        printf("%d -> ", head->data);
        head = head->next;
    }
}

node* insertAtEnd(node* head, int data){
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

node* insertAtFirst(node* head, int data){
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

node* deleteFirst(node* head){
    node* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

node* deleteLast(node* head){
    node* p = head;
    node* q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}


int main(int argc, char const *argv[])
{
    node* head = NULL;
    int c, val, flag = 1;

    printf("Operations:\n");
    printf("1. Insert at beginning\n2. Insert At End\n3. Delete from End\n4. Delete from Beginning\n5. Display\n6.Exit\n");
    while (flag!=0)
    {
        printf("Enter choice: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            head = insertAtFirst(head, val);
            break;
        case 2:
            printf("Enter Value: ");
            scanf("%d", &val);
            head = insertAtEnd(head, val);
            break;
        case 3:
            head = deleteLast(head);
            break;
        case 4:
            head = deleteFirst(head);
            break;
        case 5:
            display(head);
            printf("\n");
            break;
        case 6:
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
