#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* front = 0, *rear = 0;

void enqueue(int val){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (front == 0 && rear == 0)
    {
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    } 
}
void dequeue(){
    struct node* temp;
    temp = front;
    if (front == 0 && rear == 0)
    {
        printf("Empty...");
    }
    else{
        front = front->next;
        free(temp);
    } 
}

void display(){
    struct node* temp;
    if (front == 0 && rear == 0)
    {
        printf("Empty...\n");
    }
    else{
        temp = front;
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } 
    } 
}

int main(int argc, char const *argv[])
{
    int n, ch, val, check = 1;
    printf("Menu:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(check > 0){
        printf("Enter Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Value: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            printf("\n");
            break;
        case 4:
            printf("Exiting...");
            check = 0;
            break;
        default:
            printf("Invalid Input...");
            break;
        }
    }
    return 0;
}
