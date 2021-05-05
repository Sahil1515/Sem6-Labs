 %%cu
#include <stdio.h>
#include <stdlib.h>
#include<cuda.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


__global__ void sortKernel(int *A, int *B, int N)
{
    int id=blockDim.x*blockIdx.x+threadIdx.x;
 
    if(id>N)
     return ;
 
    int pos=0;
 
    for(int i=0;i<N;i++)
    {
        if(A[i]<A[id] || ( A[i]==A[id] &&i<id))
        {
            pos++;
        }       
    }
    B[pos]=A[id]; 
}

int main()
{
    int N=13;
    int size=sizeof(int)*N;

    int A[N];
    int B[N];
 
    for(int i=0;i<N;i++)
    {
        A[i]=N-i;
    }
 
    printf("Array before sorting:\n");

    for(int i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
 


    int *d_A, *d_B;

    cudaMalloc((void**)&d_A,size);
    cudaMalloc((void**)&d_B,size);

    //Only that mem which kernel needs to read
    cudaMemcpy(d_A,A,size,cudaMemcpyHostToDevice);
 
    sortKernel<<<ceil(N/5.0),5>>>(d_A,d_B,N);

    cudaMemcpy(B,d_B,size,cudaMemcpyDeviceToHost);

    printf("Array after sorting:\n");

    for(int i=0;i<N;i++)
    {
        printf("%d ",B[i]);
    }

    return 0;
}