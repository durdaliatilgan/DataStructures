#include "Queue.hpp"

Queue::Queue(){
	front=back=NULL;
	length=0;
}
Node* Queue::previousMaxNode(){
	Node *prev = NULL;
	Node *tmp = front;
	int max=front->item;
	while(tmp->next != NULL){
		if(tmp->next->item > max){
			max = tmp->next->item;
			prev=tmp;
		}
		tmp = tmp->next;
	}
	return prev;
}
int Queue::count()const{
	return length;
}
bool Queue:: isEmpty()const{
	return length == 0;
}
void Queue:: enqueue(const int& item){
	Node *last = new Node(item);
	if(isEmpty()) front = back = last;
	else{
		back->next = last;
		back = back->next;
	}
	length++;
}
void Queue:: dequeue(){
	if(isEmpty()) throw "Queue is Empty";
	Node *tmp = front;
	front=front->next;
	delete tmp;
	length--;
}		
void Queue:: dequeueMax(){
	if(isEmpty()) throw "Queue is Empty";
	Node *prev = previousMaxNode();
	Node *tmp;
	if(prev == NULL) dequeue();
	else{
		if(prev->next == back) back=prev;
		tmp=prev->next;
		prev->next = prev->next->next;
		delete tmp;
		length--;
	}
}
void Queue:: clear(){
	while(!isEmpty())dequeue();
}
int& Queue:: peek()const{
	if(isEmpty()) throw "Queue is Empty";
	return front->item;
}
int& Queue:: peekMax(){
	if(isEmpty()) throw "Queue is Empty";
	Node *prev = previousMaxNode();
	if(prev == NULL) return peek();
	return prev->next->item;
}
Queue::~Queue(){
	clear();
}