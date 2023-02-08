#include<stdio.h>

int GCD(int a, int b){
    int i, c;
    c = a >= b? b:a;
    for (int i = c; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            return i;
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    int a, b, ans;
    printf("Enter numbers: ");
    scanf("%d %d", &a, &b);
    ans = GCD(a,b);
    printf("GCD = %d", ans);
    return 0;
}
