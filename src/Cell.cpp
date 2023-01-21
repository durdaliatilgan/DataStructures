#include "Cell.hpp"
Cell::Cell(int cellMainNumber,int *cellArray,int totalSize)
{
    this->cellArray=new int[totalSize];
    this->cellArray=cellArray;
    this->cellMainNumber=cellMainNumber;
    this->size=totalSize;
}

Cell::~Cell()
{
    delete [] cellArray;
}

