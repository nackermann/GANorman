#ifndef DOUBLEELIMINATIONTOURNAMENT_H
#define DOUBLEELIMINATIONTOURNAMENT_H

#include "selection.h"
#include "bracket.h"

class DoubleEliminationTournament : public Selection {
public:
    DoubleEliminationTournament(int k, int winrate);
    virtual ~DoubleEliminationTournament();
    virtual void select(Population &population);
    
public:
    int m_K;
    int m_Winrate;
};



#endif
