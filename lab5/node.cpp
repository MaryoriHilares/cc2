#include <iostream>
#include "node.h"
 
Node::Node()
{       elem=0;
       	next=NULL;	
}
Node::Node(int a)         
{       elem=a;
       	next=NULL;	
}
int Node::getElem(){  //permite que otras clases puedan acceder al elemento
	return elem;
}
Node* Node::getNext(){  //permite que otras clases puedan acceder al puntero siguiente
	return next;
}
int Node::setElem(int elem_){   //permite que otras clases puedan modificar al elemento
	elem=elem_;
}
Node* Node::setNext(Node* next_){  //permite que otras clases puedan modificar el puntero siguiente
	next=next_;
}

