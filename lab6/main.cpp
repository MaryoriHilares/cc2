#include "ListaEnlazada.h"
#include "ListaEnlazada.cpp"
#include "nodeT.h"
using namespace std;

int main(){
	ListaEnlazada<int> lista;
	int num,pos;
    cout<<"Ingrese numero:";
	cin>>num;
	lista.insertarInicio(num);
	cout<<"Numero insertado al inicio"<<endl;
	lista.printList();
	cout<<"Ingrese numero: ";
	cin>>num;
	lista.insertarFinal(num);
	cout<<"Numero insertado al final"<<endl;
	lista.printList();  	
	cout<<"Ingrese numero: ";
	cin>>num;
	lista.insertarInicio(num);
	cout<<"Numero insertado al inicio"<<endl;
	lista.printList();
	cout<<"Ingrese numero: ";
	cin>>num;
	lista.insertarFinal(num);
	cout<<"Numero insertado al final"<<endl;
	lista.printList();
	cout<<"Ingrese Posicion y numero que desea insertar: ";
	cin>>pos;
	cin>>num;
	lista.insertarPos(num,pos);
	lista.printList();
	cout<<"La lista ingresada es: "<<endl;	
	lista.printList();  //imprime la lista
	cout<<"Eliminando elemento del inicio "<<endl;
    lista.popFront();
	lista.printList(); //imprime la lista actualizada
    cout<<"Eliminando elemento del final "<<endl;
	lista.popBack();
	lista.printList();
	cout<<"Ingrese numero que desea eliminar: ";
	cin>>num;
	lista.removeLst(num);
	lista.printList();
	return 0;
}
