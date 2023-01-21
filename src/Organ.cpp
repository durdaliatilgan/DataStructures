/** 
* @file Organ.cpp
* @description Bu source organ nesnelerini ve tissueları istenildigi 
* sekilde organlara ve sistemlere ekleme islemlerini icerir.
* @course A grubu 1. ogretim 
* @assignment Odev2
* @date 14.12.2022
* @author Durdali ATILGAN (durdaliatilgan@hotmail.com)
*/

#include "Organ.hpp"

using namespace std;


OrganNode::OrganNode(TissueNode *tissueN,OrganNode *lf,OrganNode *rg){
		tissueNode = tissueN;
		left = lf;
		right = rg;
}
Organ::Organ(TissueList *tissueList)
{
	this->tissueList=tissueList;
}
OrganismList * Organ::tissueAddToOrgan(){
	OrganismList *organismList=new OrganismList();
	int counter=tissueList->Count();
	int counterOfTissue =1;
	while (counter)
	{
		SysList *sysList=new SysList();
		for (int i = 0; i < 100; i++)
		{
			OrganBST *organBST=new OrganBST();
			for (int i = 1; i < 21; i++)
			{
				organBST->Add(tissueList->FindPreviousByPosition(counterOfTissue));
				counter-=1; counterOfTissue+=1;
			}
			sysList->add(organBST);
		}		
		organismList->add(sysList);
	}
	return organismList;
}
Organ::~Organ()
{}