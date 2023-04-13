#include<stdio.h>
#include<math.h>

int opcount = 0;

int max(int a, int b) { return (a > b) ? a : b; }

void warshal(int a[10][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                opcount++;
                a[i][j] = max(a[i][j], a[i][k] && a[k][j]);
}

int main(int argc, char const *argv[])
{
    int a[10][10] = {0};
    int n, e, u, v, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &e);
    for (int i = 1; i <= e; ++i)
    {
        printf("\n Enter u and v of edge %d:", i);
        scanf("%d %d", &u, &v);
        a[u][v] = 1;
    }

    printf("\nInitial Matrix: \n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n ; ++j)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    warshal(a,n);
    printf("\nTransitive Closure: \n");
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n ; ++j)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("Opcount: %d", opcount);
    return 0;
}
