#include "tournamentSelection.h"

#include "bracket.h"
#include <iostream>

TournamentSelection::TournamentSelection(int k, int winrate) : m_K(k), m_Winrate(winrate)
{
    
}

TournamentSelection::~TournamentSelection()
{
    
}

void TournamentSelection::select(Population &population)
{
    std::vector<Folding> selectedFoldings;
    
    std::vector<Folding> &foldings = population.getFoldings();
    
    if (m_K==2) {
        
        for (unsigned int i=0; i<foldings.size(); ++i) {
            
            Folding& randomFolding1 = foldings.at(rand() % foldings.size());
            
            Folding& randomFolding2 = foldings.at(rand() % foldings.size());
            
            Bracket myBracket;
            
            myBracket.setAttendees(randomFolding1, randomFolding2);
            
            myBracket.fight(80);
            
            try {
                selectedFoldings.push_back(myBracket.getWinner());
            } catch (int n) {
                std::cout << "FATAL ERROR: " << n << std::endl;
                std::cin.get();
            }
            
            
            /*
            
            if ( randomFolding1.getFitness() > randomFolding2.getFitness() )
            {
                if (((rand() % 100)+1) <= m_Winrate) {
                    selectedFoldings.push_back(randomFolding1);
                }
                else
                {
                    selectedFoldings.push_back(randomFolding2);
                }
            }
            else
            {
                if (((rand() % 100)+1) <= m_Winrate) {
                    selectedFoldings.push_back(randomFolding2);
                }
                else
                {
                    selectedFoldings.push_back(randomFolding1);
                }
            }
            */
        }
    }
    else
    {
        
        for (unsigned int i=0; i<foldings.size(); ++i) {
            
            Folding& bestFolding = foldings.at(rand() % foldings.size());
            
            for (unsigned int i=0; i<m_K-1; ++i) {
                Folding& randomFolding = foldings.at(rand() % foldings.size());
                if (randomFolding.getFitness() > bestFolding.getFitness()) {
                    bestFolding = randomFolding;
                }
                
            }
            
            selectedFoldings.push_back(bestFolding);
        }
        
    }
    
    foldings = selectedFoldings;
}