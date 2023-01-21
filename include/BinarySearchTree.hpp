#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include <cmath>
#include "Tissue.hpp"

class OrganNode{
	public:
	TissueNode *tissueNode;
	OrganNode *left;
	OrganNode *right;
	
	OrganNode(TissueNode *tissueN, OrganNode *lf=NULL, OrganNode *rg=NULL);
};
class OrganBST{
	public:	
		OrganBST();
		void SearchAndAdd(OrganNode *&subNode,TissueNode *tissueNode);
		bool SearchAndDelete(OrganNode *&subNode,TissueNode *tissueNode);
		bool DeleteNode(OrganNode *&subNode);
		void inorder(OrganNode *subNode);
		void preorder(OrganNode *subNode);
		TissueNode * postorder(OrganNode *subNode);
		
		void PrintLevel(OrganNode *subNode,int level);
		bool Search(OrganNode *subNode,TissueNode *tissueNode);
		int size;
		int Height(OrganNode *subNode);
		OrganNode *root;
		int counter;
		OrganNode *newArray[];
		bool isEmpty()const;
		void Add(TissueNode *tissueNode);
		void Delete(TissueNode *tissueNode);
		void inorder();
		void preorder();
		void postorder();
		void levelorder();
		int Height();
		bool Search(TissueNode *tissueNode);
		void Clear();
		~OrganBST();
};

#endif