#include "Tissue.hpp"
TissueNode::TissueNode(Cell *cellNode,TissueNode *next,TissueNode *prev){
   
    this->cell=cellNode;
    this->next =next;
    this->prev=prev;
}
TissueNode* TissueList::FindPreviousByPosition(int index)throw(NoSuchElement){
    if(index < 0 || index > size) throw NoSuchElement("No Such Element");
    TissueNode *prv = head;
    int i=1;
    for(TissueNode *itr = head; itr->next != NULL && i != index; itr=itr->next,i++)
        prv = prv->next;
    return prv;
}
TissueList::TissueList(){
    head = NULL;
    size=0;
}
int TissueList::Count(){
    return size;
}
bool TissueList::isEmpty(){
    return size == 0;
}
void TissueList::add(Cell*& lineAddr){
    insert(size,lineAddr);
}
void TissueList::insert(int index,Cell*& lineAddr){
    if(index < 0 || index > size) throw "Index out of Range";
    if(index == 0){
        head = new TissueNode(lineAddr,head,NULL);
        if(head->next != NULL) head->next->prev = head;
    }
    else{
        TissueNode *prv = FindPreviousByPosition(index);
        prv->next = new TissueNode(lineAddr,prv->next,prv);
        if(prv->next->next != NULL)
            prv->next->next->prev = prv->next;
    }
    size++;
}
Cell*& TissueList::first()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return head->cell;
}
Cell*& TissueList::last()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return FindPreviousByPosition(size)->cell;
}
int TissueList::indexOf(Cell*& lineAddr)throw(NoSuchElement){
    int index=0;
    for(TissueNode *itr=head;itr!=NULL;itr=itr->next){
        if(itr->cell == lineAddr) return index;
        index++;
    }
    throw NoSuchElement("No Such Element");
}
Cell*& TissueList::remove(Cell*& lineAddr){
    int index = indexOf(lineAddr);
    removeAt(index);
}
void TissueList::removeAt(int index){
    if(index < 0 || index >= size) throw "Index out of Range";
    TissueNode *del;
    if(index == 0){
        del = head;
        head = head->next;
        if(head != NULL) head->prev = NULL;
    }
    else{
        TissueNode *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        if(del->next != NULL)
            del->next->prev = prv;
    }
    size--;
    delete del;
}
bool TissueList::find(Cell*& lineAddr){
    for(TissueNode *itr=head;itr!=NULL;itr=itr->next)
        if(itr->cell == lineAddr) return true;
    return false;
}
void TissueList::reverse(){
    for(TissueNode *itr=head;itr!=NULL;){
        TissueNode *tmp = itr->next;
        itr->next = itr->prev;
        itr->prev = tmp;
        if(tmp == NULL){ 
            head = itr;
            break;
        }
        itr=tmp;
    }			
}
Cell*& TissueList::elementAt(int index)throw(NoSuchElement){
    if(index < 0 || index >= size) throw NoSuchElement("No Such Element");
    if(index == 0) return head->cell;
    return FindPreviousByPosition(index)->next->cell;
}
void TissueList::clear(){
    while(!isEmpty())
        removeAt(0);
}
TissueList::~TissueList(){
    clear();
}
