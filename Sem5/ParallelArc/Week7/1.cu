#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

__global__ void addA(int *a, int *b, int *c, int wb, int wa){
    int ridA = threadIdx.x;
    int sum, k;
    if(ridA < wa){
        for(int colIdB = 0; colIdB < wb; colIdB++){
        c[ridA * wa + colIdB] = a[ridA * wa + colIdB] + b[ridA * wa + colIdB];
        }
    }
    
}

__global__ void addB(int *a, int *b, int *c, int wa, int wb){
    int ridB = threadIdx.x;
    int cidB = threadIdx.x;
    if(ridB < wb){
        for (int ridA = 0; ridA < wa; ridA++)
        {
            c[ridA*wa + cidB] = a[ridA*wa + cidB] + b[ridA*wa + cidB];
        }
                
    }
}

__global__ void addC(int *a, int *b, int *c, int wa){
    int ridA = threadIdx.y;
    int cidB = threadIdx.x;
    int wb = blockDim.x;    
    int sum = 0;
    for (int i = 0; i < wa; i++)
    {
        c[ridA*wb+i] = a[ridA*wa+i] + b[i*wb+cidB];
    }
}

int main() {
    int a[3][3], b[3][3], c[3][3];
    int *dA, *dB, *dC;
    unsigned int size, len;

    printf("Enter mat A:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
        
    }
    printf("Enter mat B:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
        
    }

    size = 3*3*sizeof(int);
    

    cudaMalloc((void**) &dA, size);
    cudaMalloc((void**) &dB, size);
    cudaMalloc((void**) &dC, size);
    cudaMemcpy(dA, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dB, b, size, cudaMemcpyHostToDevice);

    dim3 dimBlock(3,3,1);

    // addA<<<1, 3>>>(dA, dB, dC, 3, 3);
    // addB<<<1, 3>>>(dA, dB, dC, 3, 3);
    addC<<<1, dimBlock>>>(dA, dB, dC, 3);

    cudaMemcpy(c, dC, size, cudaMemcpyDeviceToHost);
    
    printf("Resulatant Matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);
    return 0;
}

