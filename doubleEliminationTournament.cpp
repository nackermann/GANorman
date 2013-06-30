#include "doubleEliminationTournament.h"

#include "bracket.h"
#include <iostream>
#include <math.h>

DoubleEliminationTournament::DoubleEliminationTournament(int k, int winrate) : m_K(k), m_Winrate(winrate)
{
    
}

DoubleEliminationTournament::~DoubleEliminationTournament()
{
    
}

void DoubleEliminationTournament::select(Population &population)
{
	std::vector<Folding> selectedFoldings;
	std::vector<Folding> &foldings = population.getFoldings();

	unsigned int runden;
	if (std::pow(2,7) <= m_K)
	{
		runden = 7;
	}
	else if (std::pow(2,6) <= m_K)
	{
		runden = 6;
	}
	else if (std::pow(2,5) <= m_K)
	{
		runden = 5;
	}
	else if (std::pow(2,4) <= m_K)
	{
		runden = 4;
	}
	else if (std::pow(2,3) <= m_K)
	{
		runden = 3;
	}
	else if (std::pow(2,2) <= m_K)
	{
		runden = 2;
	}
	else if (std::pow(2,1) <= m_K)
	{
		runden = 1;
	}
	else
	{
		throw -1;
	}
		
	for (unsigned int i=0; i<foldings.size(); ++i)
	{
		std::vector<Folding> attendees;
		// Teilnehmer ziehen
		for (unsigned int j=0; j<m_K; ++j)
		{
			Folding& randomFolding = foldings.at(rand() % foldings.size());
			attendees.push_back(randomFolding);
		}
	
		for (unsigned int i=0; i<runden; ++i)
		{
			std::vector<Folding> newAttendees;
	
			for (unsigned int j=0; j<attendees.size(); j+=2)
			{
				Bracket myBracket;
				myBracket.setAttendees(attendees.at(j),attendees.at(j+1));
				myBracket.fight(m_Winrate);
	
				newAttendees.push_back(myBracket.getWinner());
			}
			attendees = newAttendees;
		}

		selectedFoldings.push_back(attendees.at(0)); // Der letzte ueberlebende wird selektiert
	}

	/*
	std::vector<Bracket*> myBrackets;
	std::vector<Folding> WinningBracket;
	std::vector<Folding> LosingBracket;

	for (unsigned int i=0; i<foldings.size(); ++i) 
	{
			
		// Das Tunier geht los

		// Teilnehmer ziehen, anfangs sind alle im Winning Bracket
		for (unsigned int j=0; j<m_K; ++j)
		{
			Folding& randomFolding = foldings.at(rand() % foldings.size());
			WinningBracket.push_back(randomFolding);
		}

		// Winning Bracket kaempfen lassen !

		for (unsigned int j=0; j<static_cast<unsigned int>(WinningBracket.size()/2); ++j)
		{
			Bracket *newBracket = new Bracket;

			newBracket->setAttendees(WinningBracket.at(j),WinningBracket.at(j+1));
			newBracket->fight(m_Winrate);

			myBrackets.push_back(newBracket);
		}



		for (unsigned int i=0; i<m_K; ++i)
		{
			// Teilnehmer
			Folding& randomFolding1 = foldings.at(rand() % foldings.size());
			Folding& randomFolding2 = foldings.at(rand() % foldings.size());

			Bracket *newBracket = new Bracket;

			newBracket->setAttendees(randomFolding1,randomFolding2);
			newBracket->fight(m_Winrate);

			myBrackets.push_back(newBracket);

		}

		// Losing Bracket
		for (unsigned int i=0; i<m_K; ++i)
		{

		}

		Bracket newBracket;
		newBracket.setAttendees();
		newBracket.fight(m_Winrate);


		myBrackets.push_back();
			


	}
	*/

	foldings = selectedFoldings;
}