#ifndef ORGANISM
#define ORGANISM
#include "System.hpp"

class OrganismNode{
	public:
    
		SysList *sysList;
		OrganismNode *next;
		OrganismNode *prev;
		
		OrganismNode(SysList *sysList,OrganismNode *next,OrganismNode *prev);
};

class OrganismList{
	private:
		OrganismNode *head;
		int size;
		
	public:
		OrganismList();
		int Count();
		bool isEmpty();
		void add(SysList*& data);
		void insert(int index,SysList*& orgNode);
		SysList*& first()throw(NoSuchElement);
		SysList*& last()throw(NoSuchElement);
		int indexOf(SysList*& orgNode)throw(NoSuchElement);
		OrganismNode* FindPreviousByPosition(int index)throw(NoSuchElement);
		SysList*& remove(SysList*& orgNode);void CalculateAvarage();
		void removeAt(int index);
		bool find(SysList*& orgNode);
		void reverse();
		SysList*& elementAt(int index)throw(NoSuchElement);
		void clear();
		friend ostream& operator<<(ostream& screen,OrganismList& rgt);
		void printReverseOrder();
		~OrganismList();

};


#endif