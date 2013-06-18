#ifndef TOURNAMENTSELECTION_H
#define TOURNAMENTSELECTION_H

#include "selection.h"

class TournamentSelection : public Selection {
public:
    TournamentSelection(int k, int winrate);
    virtual ~TournamentSelection();
    virtual void select(Population &population);
private:
    int m_K;
    int m_Winrate;
};

#endif
