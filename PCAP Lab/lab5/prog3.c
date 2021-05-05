 %%cu
#include <stdio.h>
#include <stdlib.h>
#include<cuda.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


__global__ void oddEven(int *A, int N)
{
    int id=blockDim.x*blockIdx.x+threadIdx.x;
    if(id>N)
      return ;
 
   if(id%2==1 &&id+1<N)
   {
       if(A[id]>A[id+1])
       {
           int temp=A[id];
           A[id]=A[id+1];
           A[id+1]=temp;
       }
   }
}

__global__ void evenOdd(int *A, int N)
{
    int id=blockDim.x*blockIdx.x+threadIdx.x;
 
     if(id>N)
      return ;
 
   if(id%2==0 &&id+1<N)
   {
       if(A[id]>A[id+1])
      {
          int temp=A[id];
          A[id]=A[id+1];
          A[id+1]=temp;
      }
   }
}

int main()
{
    int N=51;
    int size=sizeof(int)*N;

    int A[N];
 
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
 


    int *d_A;

    cudaMalloc((void**)&d_A,size);

    cudaMemcpy(d_A,A,size,cudaMemcpyHostToDevice);
 
    for(int i=0;i<=ceil(N/2);i++)
    {
        evenOdd<<<ceil(N/7.0),7>>>(d_A,N);
        oddEven<<<ceil(N/7.0),7>>>(d_A,N);
    }
    
    cudaMemcpy(A,d_A,size,cudaMemcpyDeviceToHost);

    printf("Array after sorting:\n");

    for(int i=0;i<N;i++)
    {
        printf("%d ",A[i]);
    }

    return 0;
}