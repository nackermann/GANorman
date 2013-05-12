#include "population.h"

Population::Population()
{
	for (int i = 0; i < 5; ++i) // mal ein paar reinwerfen
	{
		Folding newFolding;
		m_Foldings.push_back(newFolding);
	}
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