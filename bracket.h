#ifndef BRACKET_H
#define BRACKET_H

#include <utility>

class Folding;

class Bracket {
public:
    Bracket();
    ~Bracket();
    void setAttendees(Folding &attendee1, Folding &attendee2);
    void fight(int winrate);
    Folding& getWinner(void);
    Folding& getLoser(void);
    
private:
    std::pair<Folding*,bool> m_Attendee1;
    std::pair<Folding*,bool> m_Attendee2;
    
    bool m_HasFought;
    
};

#endif
