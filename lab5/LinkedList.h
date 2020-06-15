#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"  
class LinkedList{
   	int size;
   	Node* head;
   	public:
   		LinkedList();
   		LinkedList(int tam, Node* cabeza);
   		~LinkedList();
   		void insertList(int elem_);
   		void removeLst(int elem_r);
		void printList();
   		
};


#endif
