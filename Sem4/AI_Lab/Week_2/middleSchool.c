#include<stdio.h>

int GCD(int a, int b){
    int i, c, ans = 1, m=0, n=0;
    c = a>=b?b:a;
    for (int i = 2; i <= c; i++)
    {
        n = 0;
        m = 0;
        if (a % i == 0)
        {
            m = 1;
            a = a/i;
        }
        if (b % i == 0)
        {
            n = 1;
            b = b/i;
        }
        if (n == 1 && m == 1)
        {
            ans = ans * i;
        }
        if (n==1 || m==1)
        {
            i--;
        }
    }
    return(ans);
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
