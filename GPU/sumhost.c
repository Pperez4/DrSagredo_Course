//-------------------------------
// PROGRAMA BASICO EN C
//-------------------------------
// PAOLA PEREZ
//------------------------------------
// COMPILACION : nvcc -o sum sumhost.c
//------------------------------------

//BIBLIOTECAS DE ENTRADA Y SALIDA 
#include <stdio.h>
#include <stdlib.h>

//Predefiniciones 
#define N 512
#define Real float 

//-----------------------------
// Función de suma de arreglos  
// c = a + b
//-----------------------------
void host_add(Real *a, Real *b, Real *c)
{
    for(int idx=0; idx < N; idx++)
    c[idx] = a[idx] + b[idx];
}


//------------------------------
// Llenado de Arreglos 
//------------------------------
void fill_array(Real *data)
{
    for(int idx = 0; idx < N; idx++)
        data[idx] = (Real)idx;
}

//--------------------------------
// Salida de datos 
//--------------------------------
void print_output(Real *a, Real *b, Real *c)
{
    for(int idx = 0; idx < N; idx++)
            printf("\n %e + %e = %e", a[idx], b[idx], c[idx]);
    printf("\n");
}

//---------------------
//  main function 
//---------------------
int main()
{
    //Arreglos de enteros 
    Real *a, *b, *c;

    //Tamaño en memoria de los arreglos 
    int size = N * sizeof(Real);

    // Peticion y llenado de memoria para los arreglos
    a = (Real *)malloc(size); fill_array(a);
    b = (Real *)malloc(size); fill_array(b);
    c = (Real *)malloc(size);

    //Llamando function suma
    host_add(a,b,c);
    //Escritura del resultado en pantalla 
    print_output(a,b,c);
    //Liberacion de memoria
    free(a); free(b); free(c);

    //Exito del programa 
    return 0;

}

