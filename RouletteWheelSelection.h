#ifndef ROULETTEWHEELSELECTION_H
#define ROULETTEWHEELSELECTION_H

#include "selection.h"

class RouletteWheelSelection : public Selection {
public:
    RouletteWheelSelection();
    virtual ~RouletteWheelSelection();
    virtual void select(Population &population);
};

#endif
