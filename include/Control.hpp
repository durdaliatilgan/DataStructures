#ifndef CONTROL
#define CONTROL
#include "Organism.hpp"
class Control
{
    private:
        /* data */
    public:
        Control(/* args */);
        int controlMutationStatusAndUpdate(OrganismList *orgLst);
        ~Control();
};
#endif