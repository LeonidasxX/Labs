#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define visited 2

int n;
int adj[MAX][MAX];
int state[MAX];

int stack[MAX];
int top = -1;

int isEmpty( )
{
  if(top == -1)
        return 1;
  else
        return 0;
}

int pop()
{
        int v;
        if(top == -1)
        {
            printf("\nStack Underflow\n");
            exit(1);
        }
        else
        {
            v = stack[top];
            top=top-1;
            return v;
        }
}

void push(int v)
{
        if(top == (MAX-1))
        {
            printf("\nStack Overflow\n");
            return;
        }
        top = top+1;
        stack[top] = v;

}

void dfs(int v){
    int i;
    push(v);
    while(!isEmpty()){
        v = pop();
        if (state[v]==initial)
        {
            printf("%d",v);
            state[v]=visited;
        }
        for (int i = n-1; i >= 0; i--)
        {
            if (adj[v][i]==1 && state[i]==initial)
            {
                push(i);
            } 
        } 
    }
}

void traversal(){
    for (int i = 0; i < n; i++)
    {
        state[i] = initial;
    }
    int v;
    printf("\nEnter starting node: ");
    scanf("%d", &v);
    dfs(v);
    printf("\n");
}



void create(){
    int i, max_edges, origin, destin;

        printf("\nEnter number of nodes : ");
        scanf("%d", &n);
        max_edges= n*(n-1);

        for(i=1;i<=max_edges;i++)
        {
            printf("\nEnter edge %d( -1 -1 to quit ) : ",i);
            scanf("%d %d",&origin,&destin);

            if( (origin == -1) && (destin == -1) )
                break;

            if( origin >= n || destin >= n || origin<0 || destin<0)
            {
                printf("\nInvalid edge!\n");
                i--;
            }
            else
            {
                adj[origin][destin] = 1;
            }
        }
}



int main(int argc, char const *argv[])
{
    create();
    traversal();
    return 0;
}
