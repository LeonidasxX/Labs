#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

#define N 5

__global__ void vecAdd(float *a, float *b, float *c) {
  int id = blockIdx.x * blockDim.x + threadIdx.x;
  if (id < N) {
    c[id] = a[id] + b[id];
  }
}

int main() {
  float *h_a = (float *)malloc(N * sizeof(float));
  float *h_b = (float *)malloc(N * sizeof(float));
  float *h_c = (float *)malloc(N * sizeof(float));

  printf("Enter vector A and B: ");
  for (int i = 0; i < N; i++) {
    scanf("%f", &h_a[i]);
    scanf("%f", &h_b[i]);
  }

  float *d_a, *d_b, *d_c;
  cudaMalloc(&d_a, N * sizeof(float));
  cudaMalloc(&d_b, N * sizeof(float));
  cudaMalloc(&d_c, N * sizeof(float));

  cudaMemcpy(d_a, h_a, N * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, h_b, N * sizeof(float), cudaMemcpyHostToDevice);

  int numBlocks = N / 256;
  if (N % 256 != 0) {
    numBlocks++;
  }

  vecAdd<<<numBlocks, 256>>>(d_a, d_b, d_c);

  cudaMemcpy(h_c, d_c, N * sizeof(float), cudaMemcpyDeviceToHost);

  for (int i = 0; i < N; i++) {
    printf("%f\n", h_c[i]);
  }

  free(h_a);
  free(h_b);
  free(h_c);

  cudaFree(d_a);
  cudaFree(d_b);
  cudaFree(d_c);

  return 0;
}