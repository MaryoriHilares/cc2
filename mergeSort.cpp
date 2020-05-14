#include<stdlib.h> 
#include<stdio.h>
#include<iostream>
using namespace std;  
// Mezcla dos subarreglos de arr[]. 
// EL primer sub arreglo es arr[l..m] 
// El segundo subarreglo es arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* crea arreglos temporales */
    int L[n1], R[n2]; 
    /* Copia datos a arreglos temporales L[] y R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    
    /* Fusiona los arreglos temporales de regreso en arr[l..r]*/
    i = 0; // Indice inicial del primer sub arreglo 
    j = 0; // Indice inicial del segundo sub arreglo
    k = l; // Indice inicial del sub arreglo a mezclar
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else{ 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
		} 
  
    // Copia los elementos restantes de L[],si hubiera alguno 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copia los elementos restantes de R[],si hubiera alguno 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
// l es para el índice izquierdo y r es el índice derecho del subarreglo que va a ser ordenado
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
void mostrarArreglo(int arr[], int tam)  
{  
    int i;  
    for (i=0; i < tam; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 
  
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int tam = 6; 
  
    cout<<"El arreglo a ordenar es: \n"; 
    mostrarArreglo(arr, tam); 
  
    mergeSort(arr, 0, tam - 1); 
  
    cout<<"\n Arreglo ordenado es \n"; 
    mostrarArreglo(arr, tam); 
    return 0; 
} 

