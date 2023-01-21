#ifndef DISPLAY
#define DISPLAY

#include "BinarySearchTree.hpp"
#include "Organ.hpp"
#include "System.hpp"
#include "Tissue.hpp"
#include  "Organism.hpp"

class Display
{
    private:
        bool mutation;
    public:
        Display(/* args */);
        void printNodes(OrganismList *Organism);
        ~Display();
};





#endif