#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

#define N 10

__global__ void vecAdd(float *a, float *c) {
  int id = blockIdx.x * blockDim.x + threadIdx.x;
  if (id < N) {
    c[id] = sinf(id);
  }
}

int main() {
  float *h_a = (float *)malloc(N * sizeof(float));
  float *h_b = (float *)malloc(N * sizeof(float));
  float *h_c = (float *)malloc(N * sizeof(float));

  printf("Enter radian array: ");
  for (int i = 0; i < N; i++) {
    scanf("%f", &h_a[i]);
  }

  float *d_a, *d_b, *d_c;
  cudaMalloc(&d_a, N * sizeof(float));
  cudaMalloc(&d_b, N * sizeof(float));
  cudaMalloc(&d_c, N * sizeof(float));

  cudaMemcpy(d_a, h_a, N * sizeof(float), cudaMemcpyHostToDevice);

  vecAdd<<<N, N>>>(d_a, d_c);

  cudaMemcpy(h_c, d_c, N * sizeof(float), cudaMemcpyDeviceToHost);

  printf("After Sin we get: \n");
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