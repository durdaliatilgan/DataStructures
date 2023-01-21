#include "Organism.hpp"

using namespace std;

OrganismNode::OrganismNode(SysList *orgList,OrganismNode *next,OrganismNode *prev)
{
    this->sysList=orgList;
    this->next=next;
    this->prev=prev;
}
OrganismNode* OrganismList::FindPreviousByPosition(int index)throw(NoSuchElement){
    if(index < 0 || index > size) throw NoSuchElement("No Such Element");
    OrganismNode *prv = head;
    int i=1;
    for(OrganismNode *itr = head; itr->next != NULL && i != index; itr=itr->next,i++){
        prv = prv->next;
    }
    return prv;
}
OrganismList::OrganismList(){
    head = NULL;
    size=0;
}
int OrganismList::Count(){
    return size;
}
bool OrganismList::isEmpty(){
    return size == 0;
}
void OrganismList::add(SysList*& lineAddr){
    insert(size,lineAddr);
}
void OrganismList::insert(int index,SysList*& lineAddr){
    if(index < 0 || index > size) throw "Index out of Range";
    if(index == 0){
        head = new OrganismNode(lineAddr,head,NULL);
        if(head->next != NULL) head->next->prev = head;
    }
    else{
        OrganismNode *prv = FindPreviousByPosition(index);
        prv->next = new OrganismNode(lineAddr,prv->next,prv);
        if(prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
SysList*& OrganismList::first()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return head->sysList;
}
SysList*& OrganismList::last()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return FindPreviousByPosition(size)->sysList;
}
int OrganismList::indexOf(SysList*& lineAddr)throw(NoSuchElement){
    int index=0;
    for(OrganismNode *itr=head;itr!=NULL;itr=itr->next){
        if(itr->sysList == lineAddr) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}
SysList*& OrganismList::remove(SysList*& lineAddr){
    int index = indexOf(lineAddr);
    removeAt(index);
}
void OrganismList::removeAt(int index){
    if(index < 0 || index >= size) throw "Index out of Range";
    OrganismNode *del;
    if(index == 0){
        del = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
    }
    else{
        OrganismNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if(del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
bool OrganismList::find(SysList*& lineAddr){
    for(OrganismNode *itr=head;itr!=NULL;itr=itr->next){
        if(itr->sysList == lineAddr) return true;
    }
    return false;
}
void OrganismList::reverse(){
    for(OrganismNode *itr=head;itr!=NULL;){
        OrganismNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if(tmp == NULL){ 
            head = itr;
            break;
        }
        itr=tmp;
    }			
}
SysList*& OrganismList::elementAt(int index)throw(NoSuchElement){
    if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
    if(index == 0) return head->sysList;
    return FindPreviousByPosition(index)->next->sysList;
}
void OrganismList::clear(){
    while(!isEmpty())
        removeAt(0);
}
OrganismList::~OrganismList(){
    clear();
}