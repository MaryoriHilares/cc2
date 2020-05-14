#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
  int k, selec, ptr;
  for (k = 1; k < n; k++)
  {
    selec = arr[k];
    ptr = k - 1;
    while (ptr >= 0 && arr[ptr] > selec)
    {
      arr[ptr + 1] = arr[ptr];
      ptr = ptr - 1;
    }
    arr[ptr + 1] = selec;
  }
}

int main()
{
  int n;
  cout << "Ingrese tamanio del arreglo: ";
  cin >> n;
  int arr[n], i;
  cout << "Ingrese valores del arreglo:\n";
  for (i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Su arreglo ingresado es: ";
  for (i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout<<endl;
  insertionSort(arr, n);

  cout << "Arreglo despues del InsertionSort es: ";
  for (i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}

