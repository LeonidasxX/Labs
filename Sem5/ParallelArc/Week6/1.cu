#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

__global__ void CUDACount(char* A, char* W, unsigned int l_W, unsigned int* d_count) {
	int tid = threadIdx.x;
	for(int i=0; i<l_W; i++) 
		if(A[tid+i] != W[i]) 
			return;
	atomicAdd(d_count, 1);
}

int main() {
	char A[N], B[N];
	char* d_A, *d_W;
	unsigned int count=0, *d_count, result;
	
	printf("Enter a string: ");
	scanf(" %[^\n]s", A);
	
	printf("Enter the word to be searched: ");
	scanf(" %[^\n]s", B);
	
	cudaMalloc((void**) &d_A, strlen(A) * sizeof(char));
	cudaMalloc((void**) &d_W, strlen(B) * sizeof(char));
	cudaMalloc((void**) &d_count, sizeof(unsigned int));
	cudaMemcpy(d_A, A, strlen(A) * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(d_W, B, strlen(B) * sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(d_count, &count, sizeof(unsigned int), cudaMemcpyHostToDevice);
	
	CUDACount<<<1, strlen(A)-strlen(B)+1>>>(d_A, d_W, strlen(B), d_count);

	cudaMemcpy(&result, d_count, sizeof(unsigned int), cudaMemcpyDeviceToHost);
	
	printf("Total occurrences of %s: %u\n", B, result);
	
	cudaFree(d_A); cudaFree(d_W); cudaFree(d_count);

	return 0;
}