/** 
* @file Display.cpp
* @description Bu source file ekrana yazdirma islemini yerine getirir.
* @course A grubu 1. ogretim 
* @assignment Odev2
* @date 13.12.2022
* @author Durdali ATILGAN (durdaliatilgan@hotmail.com)
*/

#include "Display.hpp"


Display::Display(/* args */)
{
}
void Display::printNodes(OrganismList *organizma){
    
    if(!mutation)cout<<"                              ORGANIZMA"<<endl<<endl;
    else cout<<"                           "<<"ORGANIZMA(MUTASYONA UGRADI)"<<endl<<endl;
    OrganBST org;
    for(int i=1;i<=organizma->Count();i++){

        for(int j=1;j<=organizma->FindPreviousByPosition(i)->sysList->Count();j++){
            int leftHeigh= org.Height(organizma->FindPreviousByPosition(i)->sysList->FindPreviousByPosition(j)->orgNode->root->left) ;
            int rightHeight= org.Height(organizma->FindPreviousByPosition(i)->sysList->FindPreviousByPosition(j)->orgNode->root->right) ;
            
            if(leftHeigh==rightHeight-1)
                cout<<" ";
            else 
                cout<<"#";
        }
        cout<<endl;
        
    }
    
    this->mutation=true;

}
Display::~Display()
{
}