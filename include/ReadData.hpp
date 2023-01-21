#ifndef READDATA
#define READDATA
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Radix.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"

using namespace std;
class ReadData
{
    private:
        string line;
        fstream textfile;
        string fileName;        
    public:
        ReadData(string fileName);
        TissueList *tissuelist;
        OrganismList *orgList;
        Organ *organ;
        int ReadLines();
        ~ReadData();
};
#endif