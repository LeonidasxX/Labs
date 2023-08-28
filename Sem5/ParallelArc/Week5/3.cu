#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

#define width 1024

#define mask_width 3

__global__ void convolution(float *N, float *M, float *P) {
  int id = blockIdx.x * blockDim.x + threadIdx.x;
  if (id < width) {
    float p = 0;
    for (int i = 0; i < mask_width; i++) {
      p += N[id + i - mask_width / 2] * M[i];
    }
    P[id] = p;
  }
}

int main() {
  float *h_N = (float *)malloc(width * sizeof(float));
  for (int i = 0; i < width; i++) {
    h_N[i] = i;
  }

  float *h_M = (float *)malloc(mask_width * sizeof(float));
  for (int i = 0; i < mask_width; i++) {
    h_M[i] = 1;
  }

  float *h_P = (float *)malloc(width * sizeof(float));

  float *d_N;
  cudaMalloc(&d_N, width * sizeof(float));
  float *d_M;
  cudaMalloc(&d_M, mask_width * sizeof(float));
  float *d_P;
  cudaMalloc(&d_P, width * sizeof(float));

  cudaMemcpy(d_N, h_N, width * sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_M, h_M, mask_width * sizeof(float), cudaMemcpyHostToDevice);

  convolution<<<width / 1024, 1024>>>(d_N, d_M, d_P);

  cudaMemcpy(h_P, d_P, width * sizeof(float), cudaMemcpyDeviceToHost);

  for (int i = 0; i < width; i++) {
    printf("%f\n", h_P[i]);
  }

  free(h_N);
  free(h_M);
  free(h_P);

  cudaFree(d_N);
  cudaFree(d_M);
  cudaFree(d_P);

  return 0;
}