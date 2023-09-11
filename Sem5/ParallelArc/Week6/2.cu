#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

__global__ void CUDACopy(char* d_a, char* d_b, int len_a, int len_b) {
	int tid = threadIdx.x;
	int diff = len_a - tid;
	int start = len_b - (diff * (diff + 1)) / 2;
	for(int i=0; i<len_a-tid; i++)
		d_b[start+i] = d_a[i];
}


int main() {
	char a[N], b[N];
	char* d_a, *d_b;
	unsigned int size, len;
	
	printf("Enter a string: ");
	scanf(" %[^\n]s", a);
	
	len = strlen(a);
	len = (len * (len + 1)) / 2;
	size = len * sizeof(char);
	
	cudaMalloc((void**) &d_a, strlen(a) * sizeof(char));
	cudaMalloc((void**) &d_b, size);
	cudaMemcpy(d_a, a, strlen(a) * sizeof(char), cudaMemcpyHostToDevice);
	
	CUDACopy<<<1, strlen(a)>>>(d_a, d_b, strlen(a), len);

	cudaMemcpy(b, d_b, size, cudaMemcpyDeviceToHost);
	b[len] = '\0';
	
	printf("Output String: %s\n", b);
	
	cudaFree(d_a); cudaFree(d_b);

	return 0;
}