#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1024

__global__ void rowSq(unsigned int *a, unsigned int *c, int num_rows){
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if(row < num_rows){
        if(row == 0){
            for (int col = 0; col < num_rows; col++)
            {
                c[row * num_rows + col] = a[row*num_rows + col];
            }
        } else{
            for (int col = 0; col < num_rows; col++)
            {
                c[row * num_rows + col] = pow(a[row*num_rows + col], row+1);
            }
        }
        
    }
}

int main() {
    // int a[3][3], c[3][3];
    unsigned int *dA, *dC;
    unsigned int size;
    int num_rows;

    printf("Enter number of rows: ");
    scanf("%d", &num_rows);

    int a[num_rows][num_rows], c[num_rows][num_rows];

    printf("Enter mat A:\n");
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_rows; j++)
        {
            scanf("%d", &a[i][j]);
        }
        
    }

    size = num_rows*num_rows*sizeof(int);
    

    cudaMalloc((void**) &dA, size);
    cudaMalloc((void**) &dC, size);
    cudaMemcpy(dA, a, size, cudaMemcpyHostToDevice);


    rowSq<<<1, num_rows>>>(dA, dC, num_rows);

    cudaMemcpy(c, dC, size, cudaMemcpyDeviceToHost);
    
    printf("Resulatant Matrix:\n");
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_rows; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    cudaFree(dA);
    cudaFree(dC);
    return 0;
}

