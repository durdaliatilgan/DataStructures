#include "Control.hpp"

Control::Control()
{}
int Control::controlMutationStatusAndUpdate(OrganismList *orgLst){

    for(int i=1;i<=orgLst->Count();i++){

        for(int j=1;j<=orgLst->FindPreviousByPosition(i)->sysList->Count();j++){
            
            OrganBST *orgnBst= orgLst->FindPreviousByPosition(i)->sysList->FindPreviousByPosition(j)->orgNode;
            if(orgnBst->root->tissueNode->cell->cellMainNumber %50 ==0) {
                OrganBST *tmpOrgBST= new OrganBST();
                for(int k=0;k<orgnBst->root->tissueNode->cell->size;k++){
                    if(orgnBst->root->tissueNode->cell->cellArray[k] %2==0)
                        orgnBst->root->tissueNode->cell->cellArray[k]=orgnBst->root->tissueNode->cell->cellArray[k]/2;
                    
                }
                tmpOrgBST->Add(orgnBst->postorder(orgLst->FindPreviousByPosition(i)->sysList->FindPreviousByPosition(j)->orgNode->root));
                orgLst->FindPreviousByPosition(i)->sysList->FindPreviousByPosition(j)->orgNode->Clear();
                orgLst->FindPreviousByPosition(i)->sysList->FindPreviousByPosition(j)->orgNode = tmpOrgBST;
            }
        }
    }
}
Control::~Control()
{}
