#ifndef NODET_H
#define NODET_H
template<typename T>
class NodeT{
    T elem;       
    NodeT* next;
	public:
       NodeT();
       NodeT(T a);	
	   T getElem();
	   NodeT* getNext();
	   T setElem(T elem_);
	   NodeT* setNext(NodeT* next_);

};

#endif
