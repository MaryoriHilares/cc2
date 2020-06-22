#include <iostream>
#include "ListaEnlazada.h"
#include "nodeT.h"
#include "nodeT.cpp"
using namespace std;

template<typename T>
ListaEnlazada<T>::ListaEnlazada(){	
    size=0;
	head=NULL;
	cola=NULL;
}

template<typename T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T> &v){
	this ->size = v.size;
    this ->head = v.head;
	this ->cola = v.cola;	
}

template<typename T>
ListaEnlazada<T>::~ListaEnlazada(){        //nuestro destructor, elimina la cabeza de la lista
	NodeT<T> *headAct=head;
	cola=NULL;
	while (head != NULL){
        headAct= head->getNext();
        delete head;
        head=headAct;}	
}

template<typename T>
void ListaEnlazada<T>::insertarInicio(T elem_){
   	NodeT<T> *new_node= new NodeT<T>(elem_);  
	NodeT<T> *temp=head;  
    if (head==NULL) {              //si nuestra lista esta vacia crea un nuevo nodo con el elemento
        head = new_node;
        cola = new_node;
        size++;
    } 
    else{
        while(temp->getNext()!=NULL)
         	temp=temp->getNext();  //ubico a temp en el ultimo elemento de la lista
        cola=temp;                 // actualizo cola para que apunte al ultimo elemento
        new_node->setNext(head); // el siguente nodo que apunta la cola sera a la cabeza
	    head = new_node;           // actualizo nuestra nueva cabeza
	    size++;
	}
}

template<typename T>
void ListaEnlazada<T>::insertarPos(T elem_,int pos){  
    if (head==NULL&& pos==0) {              //si nuestra lista esta vacia y la pocicion que queremos insertar es 0 crea un nuevo nodo con el elemento
       	NodeT<T> *new_node= new NodeT<T>(elem_);  
        head = new_node;
        cola = new_node;
        size++;
    } 
    else if(pos<=size){  // nos aseguramos que la posicion no sea mayor que la cantidad de elementos de la lista
       	NodeT<T> *new_node= new NodeT<T>(elem_);  
    	NodeT<T> *temp=head;  
    	int c=0;
        while(c<pos-1){
         	temp=temp->getNext();  //ubico a temp una posicion antes de la requerida
            c++;
		}
        new_node->setNext(temp->getNext()); 
        temp->setNext(new_node);
	    size++;
	}
	else 
	  cout<<"No se puede insertar elemento en la posicion solicitada"<<endl;	
}


template<typename T>
void ListaEnlazada<T>::insertarFinal(T elem_){
   	NodeT<T> *new_node= new NodeT<T>(elem_);  
	NodeT<T> *temp=head;  
    if (head==NULL) {              //si nuestra lista esta vacia crea un nuevo nodo con el elemento
        head = new_node;
        cola = new_node;
        size++;
    } 
    else{
        while(temp->getNext()!=NULL)
         	temp=temp->getNext();  //ubico a temp en el ultimo elemento de la lista
        temp->setNext(new_node); //el final de la cola apuntara a nuestro nuevo nodo
		cola=new_node;  // actualizamos el final de nuestra cola
	    size++;
	}
}

template<typename T>
void ListaEnlazada<T>::popFront(){  
	NodeT<T> *temp=head;  
    if (temp==NULL) {              //si nuestra lista esta vacia
        cout<<"Lista vacia"<<endl; //no habra ningun elemento que eliminar
    } 
    else{
        head=head->getNext();
        delete temp;
        size--;
	}
}

template<typename T>
void ListaEnlazada<T>::popBack(){  
	NodeT<T> *temp=head;  
    if (head==NULL) {              //si nuestra lista esta vacia crea un nuevo nodo con el elemento
        cout<<"Lista vacia"<<endl;
    } 
    else{
        while(temp->getNext()->getNext()!=NULL)
         	temp=temp->getNext();  //ubico a temp en el penultimo elemento de la lista
	    delete cola; //eliminamos el ultimo elemento
        temp->setNext(NULL);
	    cola=temp;  // cola apuntara al ultimo elemento
	    size--;
	}
}


template<typename T>
void ListaEnlazada <T>::removeLst(T elem_r){
	NodeT<T> *temp=head;
	bool seEncuentra=false;
	if (temp==NULL){
		cout<<"Lista vacia"<<endl;  //si nuestra lista esta vacia no habra que elemento eliminar
	}
	else if (temp->getElem()==elem_r){  // Prueba si nuestro elemento de la cabeza es igual al elemento que queremos remover
		head=temp->getNext();              //si es asi procede a eliminarlo
		delete temp;
		size--;                        //una vez eliminado nuestro elemento se recude el tamaño de la lista
		seEncuentra = true;        //actualiza el estado del elemento (Esto lo usaremos lineas despues)
	}
	else{
			while (temp->getNext() != NULL){  //se asegura de que al recorrer la lista nuestro temp solo se mantenga dentro de la lista 
				NodeT<T> *temp2=temp;
                temp=temp->getNext();			//recorre los elementos de la lista 
			    if(temp->getElem()==elem_r){
                    temp2->setNext(temp->getNext());  // eliminar el elem_r ubicado en temp
                    delete temp;
                    size--;              //una vez eliminado nuestro elemento se recude el tamaño de la lista
                    seEncuentra = true;        //actualiza el estado del elemento (Esto lo usaremos lineas despues)
					break;
                }
			}
    }
    if (seEncuentra==false)
          cout<<"El elemento no se encuentra en la lista"<<endl;
    else 
      cout<<"El elemento fue removido de la lista"<<endl;
}	

template<typename T>
void ListaEnlazada <T> ::printList(){
	NodeT<T> *recorre= head;
	if(head==NULL){
		cout<<"Lista vacia"<<endl;
	}
	else{
		while(recorre!=NULL){
			cout<<recorre->getElem()<<" ";   //recorre la lista e imprime sus elementos
			recorre=recorre->getNext();
		}
		cout<<endl;
	}
}

template<typename T>
NodeT<T>* ListaEnlazada <T> ::Begin(){
	return head->getNext;
	
}
template<typename T>
NodeT<T>* ListaEnlazada <T> ::End(){
    return cola;	
}

//------------------------------
/*
template<typename T>
void Iterador<T> :: operator = (NodeT<T> *Nodo) {
    ptrN=Nodo;
}

template<typename T>
void Iterador<T> ::operator ++() {
    ptrN=ptrN->getNext();
}

template<typename T>
T Iterador<T> ::operator *() {
    return ptrN->getElem;
}

template<typename T>
void Iterador<T> ::operator --() {
	NodeT<T>* temp=temp->Begin;
	while(temp->getNext() != ptrN)
       	temp=temp->getNext();
    ptrN=temp;
}

template<typename T>
bool Iterador<T> ::operator == (NodeT<T> *Nodo) {
    return ptrN == Nodo;
}

template<typename T>

bool Iterador<T> ::operator != (NodeT<T> *Nodo){
    return ptrN != Nodo;
}*/
