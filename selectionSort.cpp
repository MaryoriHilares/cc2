#include <iostream> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int tam)  
{  
    int i, j, min;   
    for (i = 0; i < tam-1; i++)  
    {  
        // Encuentra el elemento mínimo en el arreglo desordenado 
        min = i;  
        for (j = i+1; j < tam; j++)  
        if (arr[j] < arr[min])  
            min = j;  
  
        //Intercambia el elemento mínimo encontrado con el primer elemento 
        swap(&arr[min], &arr[i]);  
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
    int arr[] = {64, 25, 12, 22, 11,16,0,9,3};  
    int tam=9;  
    selectionSort(arr, tam);  
    cout << "Arreglo ordenado: \n";  
    mostrarArreglo(arr, tam);  
    return 0;  
}  
