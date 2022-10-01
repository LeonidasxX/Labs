#include <stdio.h>
#define MAX 80

typedef struct{
    int stack[MAX];
    int top;
}stack;

int full(int top){
    if(top == MAX){
        return 1;
    }
    return 0;
}

void push(stack *s, int val){

    if(full(s->top)){
        printf("Stack Overflow...");
        return;
    }
    s->top++;
    s->stack[s->top] = val;
}

void display(stack *s){
    for (int i = s->top; i >= 0 ; i--)
    {
        printf("%d", s->stack[i]);
    }   
}


int main(int argc, char const *argv[])
{
    stack s;
    s.top = -1;

    int x;
    printf("Enter the number: ");
    scanf("%d", &x);
    
    while(x>0){
        push(&s, x%2);
        x /= 2;
    }
    printf("Binary Form...");
    display(&s);
    printf("\n");
    return 0;
}
