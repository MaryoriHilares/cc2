#include "LinkedList.h"
#include "LinkedList.cpp"
#include "node.h"
using namespace std;

int main(){
	LinkedList* lis= new LinkedList;
	int tam,i,num,x;
	cout<<"¿Cuantos numeros quieres ingresar a la lista? "; cin>>tam;
	i=1;
	while(i<=tam)
	{    cout<<"Ingrese numero: ";
	     cin>>num;
	     lis->insertList(num);
	     i++;
	}	
	cout<<"La lista ingresada es: "<<endl;	
	lis->printList();  //imprime la lista
	cout<<"Ingrese numero a eliminar: "<<endl;
	cin>>x;
	lis->removeLst(x);  //elimina el elemento 9 de la lista
	lis->printList(); //imprime la lista actualizada

	return 0;
}
