#ifndef ORGAN_O
#define ORGAN_O
#include <iostream>
#include "Tissue.hpp"
#include "Organism.hpp"

using namespace std;

class Organ
{
private:
	/* data */
public:
	TissueList *tissueList;
	Organ(TissueList *tissueList);
	OrganismList * tissueAddToOrgan();
	~Organ();
};


#endif