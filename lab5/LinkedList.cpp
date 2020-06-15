#include <iostream>
#include "LinkedList.h"
#include "node.h"
using namespace std;

LinkedList::LinkedList(){	
    size=0;
	head=NULL;
}
LinkedList::LinkedList(int tam, Node* cabeza){
	size=tam;
	head=cabeza;
}
LinkedList::~LinkedList(){        //nuestro destructor, elimina la cabeza de la lista
	delete head;	
}
void LinkedList::insertList(int elem_){
	Node *new_node= new Node(elem_);  
	Node *temp=head;
	
    if (head==NULL) {              //si nuestra lista esta vacia crea un nuevo nodo con el elemento
        head = new_node;
    } 
	else if (head->getElem() > elem_) {   //si el nuevo elemento es menor que el elemento de nuestra cabeza
            new_node->setNext(head);      //insertara el valor en la cabeza  
            head = new_node;
        } 
	else {
		while(temp -> getNext() != NULL && temp->getNext() ->getElem()< elem_)   //busca el lugar adecuado para insertar el
		    temp=temp->getNext();                                                //elemento en orden correspondiente 
            if (temp->getNext() != NULL)
                    new_node->setNext(temp->getNext());
            temp->setNext(new_node);
        }
    size++;
}
void LinkedList::removeLst(int elem_r){
	Node *temp=head;
	Node *temp2;
	if (temp==NULL){
		cout<<"Lista vacia"<<endl;  //si nuestra lista esta vacia no habra que elemento eliminar
	}
	else if (temp->getElem()==elem_r){  // Prueba si nuestro elemento de la cabeza es igual al elemento que queremos remover
		head=temp->getNext();              //si es asi procede a eliminarlo
		delete temp;
		size--;                    //una vez eliminado nuestro elemento se recude el tamaño de la lista
	}
	else{
			while (temp->getNext() != NULL){  //recorre la lista en busca del elemento a eliminar
				temp2=temp;
                temp=temp->getNext();			
			    if(temp->getElem()==elem_r){
                    temp2->setNext(temp->getNext());
                    delete temp;
                    size--;              //una vez eliminado nuestro elemento se recude el tamaño de la lista
					break;
                }
			}
    }
}	
void LinkedList::printList(){
	Node *recorre= head;
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
