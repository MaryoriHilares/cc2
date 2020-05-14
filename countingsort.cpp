#include <iostream>
using namespace std;
int obtenerMaximo(int arr[], int tam) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < tam; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 

void countingSort(int arr[],int tam,int RANGO){
    int cont[RANGO]={0};
    int i;
    int out[tam];
    
    
    for(i=0;i<tam;i++)
    ++cont[arr[i]];
    
    for(i=1;i<RANGO;i++)
    cont[i]+=cont[i-1];
    
   
    
    for(i=tam-1;i>=0;i--){
        out[cont[arr[i]]-1]=arr[i];
        --cont[arr[i]];
    }
    
    for(i=0;i<tam;i++)
    arr[i]=out[i];
    
    
    
}
void mostrarArray(int arr[],int tam){
    cout<<"Arreglo : ";
    for(int i=0;i<tam;i++)
    cout<<arr[i]<<' ';
    cout<<endl;
}

int main() {
	int arr[]={1, 4, 1, 2, 7, 5, 2,15,8,188};
	int tam=10;
	int RANGE=obtenerMaximo(arr,tam)+1;
	
	mostrarArray(arr,tam);
	
	countingSort(arr,tam,RANGE);
	
    mostrarArray(arr,tam);
	
	return 0;
}
