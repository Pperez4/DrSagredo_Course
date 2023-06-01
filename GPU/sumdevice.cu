//------------------------
// Programa en CUDA      -
//------------------------

//----------------
//CPU -> Device
//GPU -> Host
//---------------



//Bibliotecas de entrada y salida 
#include <stdio.h>
#include <stdlib.h>

//Predefiniciones 
#define N 512 

__global__  void device_add(int *a, int *b, int *c, int tpb){

        int idx = blockIdx.x*tpb + threadIdx.x;
        int aa = a[idx];
        int bb = b[idx];
    c   [idx] = aa + bb;
}

//------------------------------
// Llenado de Arreglos 
//------------------------------
void fill_array(int *data)
{
    for(int idx = 0; idx < N; idx++)
        data[idx] = idx;
}

//--------------------------------
// Salida de datos 
//--------------------------------
void print_output(int *a, int *b, int *c)
{
    for(int idx = 0; idx < N; idx++)
            printf("\n %d + %d = %d", a[idx], b[idx], c[idx]);
    printf("\n");
}
//---------------------
//  main function 
//---------------------
int main(void) {
    //Arreglos de enteros 
    int *a, *b, *c;
    int *a_device, *b_device, *c_device;
    //Tamaño en memoria de los arreglos 
    int size = N * sizeof(int);
    int threads_per_block = 8;
    int nblocks = N/threads_per_block;

    a = (int *)malloc(size); fill_array(a);
    b = (int *)malloc(size); fill_array(b);
    c = (int *)malloc(size);

    cudaMalloc((void **)&a_device, size);
    cudaMalloc((void **)&b_device, size);
    cudaMalloc((void **)&c_device, size);
    
    cudaMemcpy(a_device, a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(b_device, b, size, cudaMemcpyHostToDevice);
    device_add<<<nblocks, threads_per_block >>>(a_device, b_device,c_device, threads_per_block);

    cudaMemcpy(c, c_device, size, cudaMemcpyDeviceToHost);
    print_output(a,b,c);
    free(a);free(b);free(c);
    cudaFree(a_device);cudaFree(b_device);cudaFree(c_device);
    return 0;

}