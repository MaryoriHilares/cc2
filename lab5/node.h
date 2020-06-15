#ifndef NODE_H
#define NODE_H

class Node{
    int elem;       
    Node* next;	
	public:
       Node();
       Node(int a);	
	   int getElem();
	   Node* getNext();
	   int setElem(int elem_);
	   Node* setNext(Node* next_);

};

#endif
