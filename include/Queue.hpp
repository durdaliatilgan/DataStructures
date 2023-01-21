#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;


class Node{
	public:
		int item;
		Node *next;
		Node(int item,Node *next=NULL){
			this->item = item;
			this->next = next;
		}
};
class Queue{
	private:
		Node *front;
		Node *back;		
		int length;
		Node* previousMaxNode();
	public:
		Queue();
		int count()const;
		bool isEmpty()const;
		void enqueue(const int& item);
		void dequeue();
		void dequeueMax();
		void clear();
		int& peek()const;
		int& peekMax();
		~Queue();
};

#endif
