#include "bracket.h"
#include "Folding.h"

Bracket::Bracket() : m_HasFought(false), m_Attendee1(NULL,false), m_Attendee2(NULL,false)
{
    
}

Bracket::~Bracket()
{
    
}

void Bracket::setAttendees(Folding &attendee1, Folding &attendee2)
{
    m_Attendee1.first = &attendee1;
    m_Attendee2.first = &attendee2;
}

void Bracket::fight(int winrate)
{
    if ( m_Attendee1.first->getFitness() > m_Attendee2.first->getFitness() )
    {
        if (((rand() % 100)+1) <= winrate) {
            m_Attendee1.second = true;
        }
        else
        {
            m_Attendee2.second = true;
        }
    }
    else
    {
        if (((rand() % 100)+1) <= winrate) {
            m_Attendee2.second = true;
        }
        else
        {
            m_Attendee1.second = true;
        }
    }
    
    m_HasFought = true;
}

Folding& Bracket::getWinner(void)
{
    
    if (m_Attendee1.second == true) {
        return *m_Attendee1.first;
    }
    else if (m_Attendee2.second == true)
    {
        return *m_Attendee2.first;
    }
    else
    {
        throw -1;
    }
}