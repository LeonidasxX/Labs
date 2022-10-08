#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char symbol){
    top++;
    stack[top] = symbol;
    printf("%d\n", stack[top]);
}

char pop(){
    char a;
    a = stack[top];
    top--;
    return a;
}

void prefixToPostfix(char prefix[20], char postfix[20]){
    printf("Entered function\n");
    int i,j = 0;
    char symbol;
    stack[++top] = '#';
    for (i = 0; i < strlen(prefix); i++)
    {
        printf("Entered for\n");
        symbol = prefix[i];
        printf("Symbol: %d\n", symbol);
        if (isdigit(symbol))
        {
            printf("appending j\n");
            postfix[j] = symbol;
            printf("postfix: %s\n", postfix);
            j++;
            printf("j: %d\n", j);
        }
        else{
            printf("pushing\n");
            push(symbol);
        }   
    }
    while(stack[top]!='#'){
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int main(int argc, char const *argv[])
{
    char postfix[20], prefix[20], temp;
    printf("Enter prefix expression: ");
    scanf("%[^\n]s", prefix);
    prefixToPostfix(prefix, postfix);
    printf("%s\n", postfix);
    return 0;
}
