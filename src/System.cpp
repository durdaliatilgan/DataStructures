#include "System.hpp"

using namespace std;

SysNode::SysNode(OrganBST *orgNode,SysNode *next,SysNode *prev){
    this->orgNode=orgNode;
    this->next =next;
    this->prev=prev;
}
SysNode* SysList::FindPreviousByPosition(int index)throw(NoSuchElement){
    if(index < 0 || index > size) throw NoSuchElement("No Such Element");
    SysNode *prv = head;
    int i=1;
    for(SysNode *itr = head; itr->next != NULL && i != index; itr=itr->next,i++){
        prv = prv->next;
    }
    return prv;
}
SysList::SysList(){
    head = NULL;
    size=0;
}
int SysList::Count(){
    return size;
}
bool SysList::isEmpty(){
    return size == 0;
}
void SysList::add(OrganBST*& lineAddr){
    insert(size,lineAddr);
}
void SysList::insert(int index,OrganBST*& lineAddr){
    if(index < 0 || index > size) throw "Index out of Range";
    if(index == 0){
        head = new SysNode(lineAddr,head,NULL);
        if(head->next != NULL) head->next->prev = head;
    }
    else{
        SysNode *prv = FindPreviousByPosition(index);
        prv->next = new SysNode(lineAddr,prv->next,prv);
        if(prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
OrganBST*& SysList::first()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return head->orgNode;
}
OrganBST*& SysList::last()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return FindPreviousByPosition(size)->orgNode;
}
int SysList::indexOf(OrganBST*& lineAddr)throw(NoSuchElement){
    int index=0;
    for(SysNode *itr=head;itr!=NULL;itr=itr->next){
        if(itr->orgNode == lineAddr) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}
OrganBST*& SysList::remove(OrganBST*& lineAddr){
    int index = indexOf(lineAddr);
    removeAt(index);
}
void SysList::removeAt(int index){
    if(index < 0 || index >= size) throw "Index out of Range";
    SysNode *del;
    if(index == 0){
        del = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
    }
    else{
        SysNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if(del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
bool SysList::find(OrganBST*& lineAddr){
    for(SysNode *itr=head;itr!=NULL;itr=itr->next){
        if(itr->orgNode == lineAddr) return true;
    }
    return false;
}
void SysList::reverse(){
    for(SysNode *itr=head;itr!=NULL;){
        SysNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if(tmp == NULL){ 
            head = itr;
            break;
        }
        itr=tmp;
    }			
}
OrganBST*& SysList::elementAt(int index)throw(NoSuchElement){
    if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
    if(index == 0) return head->orgNode;
    return FindPreviousByPosition(index)->next->orgNode;
}
void SysList::clear(){
    while(!isEmpty())
        removeAt(0);
}

SysList::~SysList(){
    clear();
}
