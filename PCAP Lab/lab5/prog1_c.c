 %%cu
#include <stdio.h>
#include <stdlib.h>
#include<cuda.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void blockSizeN(int * A, int * B, int *C, int N)
{
    int id=blockIdx.x*blockDim.x+threadIdx.x;
 
    if(id<N)
      C[id]=A[id]+B[id];
}

int main()
{
    // if N is increased the value is not computed
 
    int N=1000;
    int size=sizeof(int)*N;
  
    int * d_A, * d_B, * d_C;
 
    int A[N];
    int B[N];
    int C[N];
 
    for(int i=0;i<N;i++)
    {
        A[i]=B[i]=i;
    }
   
 
    cudaMalloc((void**)&d_A,size);
    cudaMalloc((void**)&d_B,size);
    cudaMalloc((void**)&d_C,size);
 
    cudaMemcpy(d_A,A,size,cudaMemcpyHostToDevice);
    cudaMemcpy(d_B,B,size,cudaMemcpyHostToDevice);
 
    blockSizeN<<<ceil(N/256.0),256>>>(d_A,d_B,d_C,N);

    cudaMemcpy(C,d_C,size,cudaMemcpyDeviceToHost);

    printf("Resultant array after adding A and B arrays:\n");

    for(int i=0;i<N;i++)
    {
        printf("%d ",C[i]);
    }
 
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

 return 0;
 
}