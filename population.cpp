#include "population.h"

Population::Population()
{
}

Population::~Population()
{
}

void Population::browse(std::ostream &outputStream) 
{
	for (unsigned int i=0;i<m_Foldings.size();++i)
	{
		m_Foldings.at(i).browse(outputStream);
		outputStream << std::endl << "-------------" << std::endl;
	}
}

void Population::createRandomFolding(std::string& sequence)
{
	Folding newFolding(sequence);

	m_Foldings.push_back(newFolding);
}

void Population::killPopulation(void)
{
    m_Foldings.clear();
}

void Population::draw(int chainDistance, int maxRows) 
{
	int x = 0;
	int y = 0;

	for (unsigned int i=0;i<m_Foldings.size();++i)
	{
		if (y>=maxRows)
		{
			++x;
			y = 0;
		}

		m_Foldings.at(i).draw(x*chainDistance,y*chainDistance);

		++y;
	}
}

Folding& Population::getFolding(unsigned int index)
{
    return m_Foldings.at(index);
}

unsigned long Population::getNumberOfFoldings(void)
{
    return m_Foldings.size();
}