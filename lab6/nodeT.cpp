#include <iostream>
#include "nodeT.h"

template<typename T>
NodeT<T>::NodeT()
{       elem=NULL;
       	next=NULL;	
}

template<typename T>
NodeT<T>::NodeT(T a)         
{       elem=a;
       	next=NULL;	
}

template<typename T> 
T NodeT<T>::getElem(){  //permite que otras clases puedan acceder al elemento
	return elem;
}

template<typename T>
NodeT<T>* NodeT<T>::getNext(){  //permite que otras clases puedan acceder al puntero siguiente
	return next;
}

template<typename T>
T NodeT<T>::setElem(T elem_){   //permite que otras clases puedan modificar al elemento
	elem=elem_;
}

template<typename T> 
NodeT<T>* NodeT<T>::setNext(NodeT<T>* next_){  //permite que otras clases puedan modificar el puntero siguiente
	next=next_;
}

