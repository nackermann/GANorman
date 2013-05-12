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

void Population::createRandomFoldings(std::string& sequence) // Noch übergeben wie viele
{
	Folding newFolding(sequence);

	m_Foldings.push_back(newFolding); // Nur eins erstmal gemacht !
}