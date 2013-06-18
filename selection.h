#ifndef SELECTION_H
#define SELECTION_H

#include "population.h"

class Selection {
public:
    Selection();
    virtual ~Selection();
    virtual void select(Population &population);
};


#endif
