#include<stdio.h>
#define MAXFACTORS 1024

typedef struct{
    int size;
    int factor[MAXFACTORS + 1];
    int exponent[MAXFACTORS + 1];
} fact;

void factors(int x, fact* factor){
    int j = 1, n = x, c = 0, k = 1;
    factor->factor[0] = 1;
    factor->exponent[0] = 1;

    for (int i = 2; i <= n; i++)
    {
       c = 0;
       while (n % i == 0)
       {
        c++;
        n = n/i;
       }
       if (c > 0)
       {
        factor->exponent[k] = c;
        factor->factor[k] = i;
        k++;
       } 
    }
    factor->size = k-1;
}

int GCD(int m, int n){
    fact mFact, nFact;
    int r, mi, ni, k, x = 1, j, i;

    factors(m, &mFact);
    factors(n, &nFact);

    int min;
    i = 1;
    j = 1;
    while (i <= mFact.size && j <= nFact.size)
    {
        if (mFact.factor[i] < nFact.factor[j])
        {
            i++;
        }
        else if (nFact.factor[j] < mFact.factor[i])
        {
            j++;
        }
        else{
            min = mFact.exponent[i] > nFact.exponent[j]? nFact.exponent[j]: mFact.exponent[i];
 
            x = x * mFact.factor[i] * min;
            i++;
            j++;
        }
    }
    return x;
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
