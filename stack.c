#include <stdio.h>
#define MAX 10

typedef struct{
    char stack[MAX];
    int top;
}stack;

int full(int top){
    if(top == MAX){
        return 1;
    }
    return 0;
}

int empty(int top){
    if(top == -1){
        return 1;
    }
    return 0;
}

void push(stack *s){
    char val;
    printf("\nEnter the value:");
    fflush(stdin);
    scanf(" %c", &val);
    if(full(s->top)){
        printf("Stack Overflow...");
        return;
    }
    s->top++;
    s->stack[s->top] = val;
}

void pop(stack *s){
    if(empty(s->top)){
        printf("Stack Underflow..");
        return;
    }
    printf("Poped value is: %c", s->stack[s->top]);
    s->top--;
}

void display(stack *s){
    for (int i = s->top; i >= 0 ; i--)
    {
        printf("%c\n", s->stack[i]);
    }   
}


int main(int argc, char const *argv[])
{
    stack s;
    s.top = -1;
    int x = 1;
    int c;
    
    while(x){
        printf("Enter the operation:\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d", &c);
        switch(c){
            case 1:
                push(&s);
                break;
            case 2:
                pop(&s);
                break;
            case 3:
                display(&s);
                break;
            case 4:
                printf("Exiting...");
                x = 0;
                break;
            default:
                printf("Invlaid Input");
                break;
        }
    }

    return 0;
}
