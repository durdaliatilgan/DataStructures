#include <iostream>
#include <cmath>
#include "BinarySearchTree.hpp"
using namespace std;
void OrganBST::SearchAndAdd(OrganNode *&subNode,TissueNode *tissue){
    if(subNode == NULL) subNode = new OrganNode(tissue);
    else if(tissue->cell->cellMainNumber <= subNode->tissueNode->cell->cellMainNumber)
        SearchAndAdd(subNode->left,tissue);
    else 
        SearchAndAdd(subNode->right,tissue);
}
bool OrganBST::SearchAndDelete(OrganNode *&subNode,TissueNode *tissueNode){
    if(subNode == NULL) return false;
    if(subNode->tissueNode->cell->cellMainNumber == tissueNode->cell->cellMainNumber) return SearchAndDelete(subNode->left,tissueNode);
    else if(tissueNode->cell->cellMainNumber < subNode->tissueNode->cell->cellMainNumber) return SearchAndDelete(subNode->left,tissueNode);
    else return SearchAndDelete(subNode->right,tissueNode);
}
bool OrganBST::DeleteNode(OrganNode *&subNode){
    OrganNode *DelNode = subNode;
    
    if(subNode->right == NULL) subNode = subNode->left;
    else if(subNode->left == NULL) subNode = subNode->right;
    else{
        DelNode = subNode->left;
        OrganNode *parent = subNode;
        while(DelNode->right != NULL){
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->tissueNode = DelNode->tissueNode;
        if(parent == subNode) subNode->left = DelNode->left;
        else parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}
void OrganBST::inorder(OrganNode *subNode){
    if(subNode != NULL){
        inorder(subNode->left);
        cout<<subNode->tissueNode<<" ";
        inorder(subNode->right);
    }
}
void OrganBST::preorder(OrganNode *subNode){
    if(subNode != NULL){
        cout<<subNode->tissueNode<<" ";
        preorder(subNode->left);
        preorder(subNode->right);
    }
}
TissueNode * OrganBST::postorder(OrganNode *subNode){
    
    if(subNode != NULL){
        postorder(subNode->left);
        postorder(subNode->right);
        
        return subNode->tissueNode;
    }

}

int OrganBST::Height(OrganNode *subNode){
    if(subNode == NULL) return -1;
    return 1+max(Height(subNode->left),Height(subNode->right));
}
void OrganBST::PrintLevel(OrganNode *subNode,int level){
    if(subNode == NULL) return;
    if(level == 0) cout<<subNode->tissueNode<<" ";
    else{
        PrintLevel(subNode->left,level-1);
        PrintLevel(subNode->right,level-1);
    }
}
bool OrganBST::Search(OrganNode *subNode,TissueNode *tissueNode){
    if(subNode == NULL) return false;
    if(subNode->tissueNode->cell->cellMainNumber == tissueNode->cell->cellMainNumber) return true;
    if(tissueNode->cell->cellMainNumber < subNode->tissueNode->cell->cellMainNumber) return Search(subNode->left,tissueNode);
    else return Search(subNode->right,tissueNode);
}
OrganBST::OrganBST(){
    root = NULL;
}
bool OrganBST::isEmpty()const{
    return root == NULL;
}
void OrganBST::Add(TissueNode *tissueNode){
    SearchAndAdd(root,tissueNode);
}
void OrganBST::Delete(TissueNode *tissueNode){
    if(SearchAndDelete(root,tissueNode) == false) throw "Item not found.";
}
void OrganBST::inorder(){
    inorder(root);
}
void OrganBST::preorder(){
    preorder(root);
}
void OrganBST::postorder(){
    postorder(root);
}
void OrganBST::levelorder(){
    int h = Height();
    for(int level=0;level<=h;level++)
        PrintLevel(root,level);    
}
int OrganBST::Height(){
    return Height(root);
}
bool OrganBST::Search(TissueNode *tissueNode){
    return Search(root,tissueNode);
}
void OrganBST::Clear(){
    while(!isEmpty()) DeleteNode(root);
}
OrganBST::~OrganBST(){
    Clear();
}
