#include<stdio.h>
#include<stdlib.h>
int arr[80];
int size;
int top1, top2;

void twoStacks(int n){
    printf("Initializing multi\n");
    size = n;
    arr[n];
    top1 = -1;
    top2 = size;
    printf("Hogaya\n");
}

void push1(int x){
    printf("Entered push1\n");
    if (top1 < top2 -1)
    {
        printf("Entered if\n");
        top1++;
        printf("top1 = %d\n", top1);
        arr[top1] = x;
        printf("top1 val = %d\n", arr[top1]);
    }
    else{
        printf("Stack Overflow\n");
    }
    printf("Exiting push1\n");
}

void push2(int x){
    printf("Entered push2\n");
    if (top1 < top2 -1)
    {
        top2--;
        arr[top2] = x;
    }
    else{
        printf("Stack Overflow\n");
    }
    printf("Exiting push1\n");
}

int pop1(){
    printf("Entered pop1\n");
    if (top1 >= 0)
    {
        int x = arr[top1];
        top1--;
        printf("poped1\n");
        return x;
    }
    else{
        printf("Stack Underflow\n");
    }   
}

int pop2(){
    if (top2 < size)
    {
        int x = arr[top2];
        top1++;
        printf("poped2\n");
        return x;
    }
    else{
        printf("Stack Underflow\n");
    }   
}

int main(int argc, char const *argv[])
{
    twoStacks(80);
    push1(5);
    push2(10);
    push2(20);
    push1(15);
    printf("Poped from Stack 1: %d\n", pop1());
    printf("Poped from Stack 2: %d\n", pop2());
    return 0;
}
