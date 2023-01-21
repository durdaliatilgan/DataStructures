#include <stdlib.h>
#include <string.h>
#include "ReadData.hpp"

using namespace std;

ReadData::ReadData(string fileName)
{
    this->fileName=fileName;
    this->textfile.open(fileName,ios::in);
    
}
int ReadData::ReadLines(){

    if (! this->textfile){
        cout << "File cant open!" << endl;
        return  1;
    }
    this->tissuelist=new TissueList();
    string satirlar;
    OrganBST tmpOrganBST;
    SysList *sys=new SysList();
    OrganismList *organism= new OrganismList();
    while (getline(this->textfile, satirlar))
    {
        stringstream ss(satirlar);
        int buffArray[1000];
        int data;
        int index=0;
        while (ss >> data)
        {
            buffArray[index]=data;
            index++;
        }
        Radix *radix = new Radix(buffArray,index);
	    int *sorted = radix->Sort();
        delete radix;
        Cell *cells= new Cell(sorted[index/2],sorted,index);
        
        tissuelist->add(cells);
    }
    this->organ = new Organ(this->tissuelist);
    this->orgList= organ->tissueAddToOrgan();
}
ReadData::~ReadData()
{
    if (this->textfile.is_open())
        this->textfile.close();
    organ->tissueList->clear();
    orgList->clear();
    
}