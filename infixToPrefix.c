#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20

char stack[MAX];
int top = -1;

void push(char symbol){
    top++;
    stack[top] = symbol;
}

char pop(){
    char a;
    a = stack[top];
    top--;
    return a;
}

void reverse(char a[20]){
    printf("Entered reverse\n");
    int i,j;
    char temp[20];
    for (i = strlen(a)-1, j=0; i+1!=0; i--,j++)
    {
        temp[j] = a[i];
    }
    temp[j] = '\0';
    strcpy(a, temp);
}

int precedence(char symbol){
    printf("Entered precedence\n");
    switch (symbol)
    {
    case '+':
        case '-':
            return 2;
            break;
    case '*':
        case '/':
            return 4;
            break;
    case '$':
        case '^':
            return 6;
            break;
    case '#':
        case '(':
            case ')':
                return 1;
                break;
    }
}

void infixtoprefix(char infix[20], char prefix[20]){
    printf("Entered itp\n");
    int i,j = 0;
    char symbol;
    stack[++top] = '#';
    reverse(infix);
    printf("Reverse done out\n");
    for (i = 0; i < strlen(infix); i++)
    {
        printf("forrrr\n");
        symbol = infix[i];
        if (isdigit(symbol))
        {
            printf("ifffffffffff num\n");
            prefix[j] = symbol;
            printf("%s\n", prefix);
            j++;
        }
        else{
            printf("else outer\n");
            if (symbol == ')')
            {
                printf("ifffffffffff wlse wala\n");
                push(symbol);
            }
            else if(symbol == '('){
                while (stack[top]!=')')
                {
                    prefix[j] = pop();
                    j++;
                    printf("%s\n", prefix);
                }
                pop();
            }
            else{
                printf("else inner outer\n");
                if (precedence(stack[top]) <= precedence(symbol)) {
                    push(symbol);
                }
                else {
                    while (precedence(stack[top]>=precedence(symbol)))
                    {
                        prefix[j] = pop();
                        printf("%s\n", prefix);
                        j++;
                    }
                    push(symbol);
                }
            }
        }
        
    }
    printf("for done\n");
    while(stack[top]!='#'){
        prefix[j] = pop();
        j++;
        printf("%s\n", prefix);
    }
    printf("while done\n");
}

int main(int argc, char const *argv[])
{
    char infix[20], prefix[20], temp;
    printf("Enter infix expression: ");
    scanf("%[^\n]s", infix);
    printf("Input Taken\n");
    infixtoprefix(infix, prefix);
    reverse(prefix);
    printf("%s\n", prefix);
    return 0;
}
