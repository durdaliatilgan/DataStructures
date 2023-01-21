#ifndef SISTEM
#define SISTEM

#include "NoSuchElement.hpp"
#include "BinarySearchTree.hpp"

using namespace std;
class SysNode{
	public:
		
		OrganBST *orgNode;
		SysNode *next;
		SysNode *prev;
		SysNode(OrganBST *orgNode,SysNode *next=NULL,SysNode *prev=NULL);
};
class SysList{
	private:
		SysNode *head;
		int size;
	public:
		SysList();
		int Count();
		bool isEmpty();
		void add(OrganBST*& data);
		void insert(int index,OrganBST*& orgNode);
		OrganBST*& first()throw(NoSuchElement);
		OrganBST*& last()throw(NoSuchElement);
		int indexOf(OrganBST*& orgNode)throw(NoSuchElement);
		SysNode* FindPreviousByPosition(int index)throw(NoSuchElement);
		OrganBST*& remove(OrganBST*& orgNode);
		void removeAt(int index);
		bool find(OrganBST*& orgNode);
		void reverse();
		OrganBST*& elementAt(int index)throw(NoSuchElement);
		void clear();
		friend ostream& operator<<(ostream& screen,SysList& rgt);
		void printReverseOrder();
		~SysList();
};
#endif