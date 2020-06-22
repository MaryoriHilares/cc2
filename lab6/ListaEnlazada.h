#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "nodeT.h"

using namespace std;

template <typename T>

class ListaEnlazada{
   	int size;
   	NodeT<T>* head;
   	NodeT<T>* cola;
   	public:
   		ListaEnlazada();
   		ListaEnlazada(const ListaEnlazada<T> &v);
   		~ListaEnlazada();
   		void insertarInicio(T elem_); // inserta elemento al inicio de la lista
   		void insertarFinal(T elem_); // inserta elemento al final de la lista
		void insertarPos(T elem_, int pos);  //inserta un elemento en cualquier posicion  
   		void popFront();   //elimina primer elemento
   		void popBack();    //elimina el ultimo elemento  
   		void removeLst(T elem_r);  //elimina el elemento en cualquier posicion
		void printList();  //imprime la lista
		NodeT<T>* Begin();
		NodeT<T>* End();
   		
};

/*
//-------------------
template<typename T>

class Iterador{
  NodeT<T>* ptrN; 
  public:
     void operator = (NodeT<T>* Nodo);
     void operator ++();
     int operator *();
     void operator --();
     bool operator == (NodeT<T>* Nodo);
     bool operator != (NodeT<T>* Nodo);

};
*/

#endif
