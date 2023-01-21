#ifndef TISSUE
#define TISSUE
#include <iostream>
#include "NoSuchElement.hpp"
#include "Cell.hpp"

class TissueNode{
	public:
    
		Cell *cell;
		TissueNode *next;
		TissueNode *prev;
		
		TissueNode(Cell *cell,TissueNode *next,TissueNode *prev);
};

class TissueList{
	private:
		TissueNode *head;
		int size;
		
	public:
		TissueList();
		int Count();
		bool isEmpty();
		void add(Cell*& data);
		void insert(int index,Cell*& orgNode);
		Cell*& first()throw(NoSuchElement);
		Cell*& last()throw(NoSuchElement);
		int indexOf(Cell*& orgNode)throw(NoSuchElement);
		TissueNode* FindPreviousByPosition(int index)throw(NoSuchElement);
		Cell*& remove(Cell*& orgNode);
		void removeAt(int index);
		bool find(Cell*& orgNode);
		void reverse();
		Cell*& elementAt(int index)throw(NoSuchElement);
		void clear();
		void printReverseOrder();
		~TissueList();

};

#endif





