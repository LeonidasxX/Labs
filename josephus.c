#include<stdio.h>

int jos(int n, int k){
    if (n==1)
    {
        return 0;
    }
    return (jos(n-1,k)+k)%n;
}
int main(int argc, char const *argv[])
{
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    
    printf("Enter the number of people to skip: ");
    scanf("%d", &k);

    int win;
    win = jos(n,k);
    printf("%d\n", win);
    
    return 0;
}
