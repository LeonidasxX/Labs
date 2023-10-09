#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 1024

__global__ void oneS(unsigned int *a, unsigned int *c, int num_rows, int num_cols){
    int row = blockIdx.x * blockDim.x + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    
    if(row < num_rows && col < num_cols){
        if(row == 0 || row == num_rows - 1 || col == 0 || col == num_cols-1){
            c[row * num_rows + col] = a[row*num_rows + col];
        } else{
            int n = a[row*num_rows + col];
            if(n > 7){
                int temp[4];
                for (int i = 0; n > 0; i++)
                {
                    temp[i] = n % 2;
                    n = n/2;
                }
                
                for(int i=0; i<4; i++){
                    if(temp[i] == 0) temp[i] = 1;
                    else if(temp[i] == 1) temp[i] = 0;
                }
                int t = 0;
                for(int i=0; i<4; i++){
                    t += temp[i] * pow(10,i);
                }
                c[row * num_rows + col] = t;
            } else{
                int temp[3];
                for (int i = 0; n > 0; i++)
                {
                    temp[i] = n % 2;
                    n = n/2;
                }
                
                for(int i=0; i<3; i++){
                    if(temp[i] == 0) temp[i] = 1;
                    else if(temp[i] == 1) temp[i] = 0;
                }
                int t = 0;
                for(int i=0; i<3; i++){
                    t += temp[i] * pow(10,i);
                }
                c[row * num_rows + col] = t;
            }
            
        }
    }
}

int main() {
    unsigned int *dA, *dC;
    unsigned int size;
    int num_rows;
    int num_cols;

    printf("Enter number of rows: ");
    scanf("%d", &num_rows);
    printf("Enter number of cols: ");
    scanf("%d", &num_cols);

    int a[num_rows][num_cols], c[num_rows][num_cols];

    printf("Enter mat A:\n");
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            scanf("%d", &a[i][j]);
        }
        
    }

    size = num_rows*num_cols*sizeof(int);
    

    cudaMalloc((void**) &dA, size);
    cudaMalloc((void**) &dC, size);
    cudaMemcpy(dA, a, size, cudaMemcpyHostToDevice);

    dim3 dimBlock(num_rows,num_cols,1);

    oneS<<<1, (num_rows, dimBlock)>>>(dA, dC, num_rows, num_cols);

    cudaMemcpy(c, dC, size, cudaMemcpyDeviceToHost);
    
    printf("Resulatant Matrix:\n");
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    cudaFree(dA);
    cudaFree(dC);
    return 0;
}

