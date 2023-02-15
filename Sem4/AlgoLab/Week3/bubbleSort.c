#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n=10, temp;
    

    int arr[n];
    int opcount = 0;

    for (int i = n-1; i >= 0; i--)
    {
        arr[n-i-1] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (arr[j+1] < arr[j])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            opcount++; 
        }
        
    }
    
    printf("%d", opcount);
    return 0;
}
