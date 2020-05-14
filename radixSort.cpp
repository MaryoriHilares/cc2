#include<iostream> 
using namespace std; 
  

int obtenerMaximo(int arr[], int tam) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < tam; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
  
 
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; // arreglo de salida
    int i, cont[10] = {0}; 
  
    // Guarda el numero de ocurrencias en cont[] 
    for (i = 0; i < n; i++) 
        cont[ (arr[i]/exp)%10 ]++; 
  
    // Cambia cont[i] por lo que cont[i] ahora contiene la actual 
    //  posicion de estos digitos en output[] 
    for (i = 1; i < 10; i++) 
        cont[i] += cont[i - 1]; 
  
    // construye la matriz de salida 
    for (i = n - 1; i >= 0; i--) 
    { 
        output[cont[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        cont[ (arr[i]/exp)%10 ]--; 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  

void radixsort(int arr[], int n) 
{   // Encuentra ek maximo numero para saber el numero de digitos 
    int m = obtenerMaximo(arr, n); 
  
  //  Hace un conteo por cada dígito. Teniendo en cuenta que 
  //en lugar de pasar el número de dígito, se pasa exp.
  //exp es 10 ^ i donde i es el número de dígito actual. 
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp); 
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
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; 
    int tam=8; 
    radixsort(arr, tam); 
    mostrarArreglo(arr, tam); 
    return 0; 
} 
