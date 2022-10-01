#include <stdio.h>
#include <string.h>
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

void push(stack *s, char val){
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
    int check = 1;

    char c[10];
    printf("Enter the string: ");
    scanf(" %s", c);

    for (int i = 0; i < strlen(c); i++)
    {
        push(&s, c[i]);
    }

    for (int i = 0; i < strlen(c); i++)
    {
        if(s.stack[s.top] == c[i]){
            pop(&s);
            check = 1;
        }
        else{
            check = 0;
            break;
        }
    }

    if (check == 1)
    {
        printf("Palindrome...");
    }
    else{
        printf("Not Palindrome...");
    }

    return 0;
}
