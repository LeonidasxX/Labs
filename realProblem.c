#include <stdio.h>
#define MAX 10

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

int empty(int top){
    if(top == -1){
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
        printf("%d\n", s->stack[i]);
    }   
}


int main(int argc, char const *argv[])
{
    stack s;
    s.top = -1;
    
    int n, k;
    int a[80];

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the number of elements to be removed: ");
    scanf("%d", &k);

    int count = 0;
    while(count<k){
        for (int i = 0; i < n; i++)
    {
        if (a[i]<a[i+1])
        {
            if(a[i] == s.stack[s.top]){
                push(&s, a[i-1]);
                count++;
                break;
            }
            else{
                push(&s, a[i]);
                count++;
                break;
            }   
        }
        
    }
    }

    
    printf("Displaying Stack...\n");
    display(&s);
    printf("Displaying Array...\n");

    for (int i = 0; i < n; i++)
    {
        if(a[i] == s.stack[s.top]){
            pop(&s);
        }
        else{
            printf("%d\n", a[i]);
        }
    }
    
    

    return 0;
}
