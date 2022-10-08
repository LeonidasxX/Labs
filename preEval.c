#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
typedef struct stack
{
    int data[MAX];
    int top;
}stack;
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int evaluate(char x,int op1,int op2);
int evaluate(char x,int op1,int op2)
{
    if(x=='+')
        return(op1+op2);
    if(x=='-')
        return(op1-op2);
    if(x=='*')
        return(op1*op2);
    if(x=='/')
        return(op1/op2);
    if(x=='%')
        return(op1%op2);
}

void init(stack *s)
{
    s->top=-1;
}

int empty(stack *s)
{
    if(s->top==-1)
        return(1);
    return(0);
}

int full(stack *s)
{
    if(s->top==MAX-1)
    return(1);
    return(0);
}
void push(stack *s,int x)
{
    s->top=s->top+1;
    s->data[s->top]=x;
}

int pop(stack *s)
{
    int x;
    x=s->data[s->top];
    s->top=s->top-1;
    return(x);
}

char* reverse(char *a){
    char *b = (char*) malloc(sizeof(char));
    for (int i = 0; i < strlen(a); i++)
    {
        b[i] = a[strlen(a) - i - 1];
    }
    return b;
}


int main()
{
    stack s;
    char x;
    int op1,op2,val, i=0;
    char a[80];
    init(&s);
    printf("Enter the expression(eg: *54)\nsingle digit operand and operators only:");
    scanf("%[^\n]s", a);
    char *b = reverse(a);
    for (int i = 0; i < strlen(b); i++)
    {
        if(isdigit(b[i])){
            push(&s,b[i]-'0');
            /*x-‘0’ for removing the effect of ascii */
        }
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            val=evaluate(b[i],op1,op2);
            push(&s,val);
        }
    }
    val=pop(&s);
    printf("value of expression=%d",val);
    return 0;
}


