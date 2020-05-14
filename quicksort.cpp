#include <bits/stdc++.h> 
using namespace std;  
  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* Esta función toma el último elemento como pivote, situa
el elemento pivote en su posición correcta en orden
matriz y coloca todos los más pequeños (más pequeños que el pivote)
a la izquierda del pivote y todos los elementos mayores a la derecha
de pivote */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];   
    int i = (low - 1); // Indice del elemento mas pequeño 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // Si el elemento actual es más pequeño que el pivote 
        if (arr[j] < pivot)  
        {  
            i++; // incrementa el indice del elemento mas pequeño 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);    
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
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
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int tam=6;  
    quickSort(arr, 0, tam - 1);  
    cout << "Arreglo ordenado: \n";  
    mostrarArreglo(arr, tam);  
    return 0;  
} 
