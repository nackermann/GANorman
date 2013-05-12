#include "algorithm.h"

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{
}

void Algorithm::run(std::string& sequence) 
{
	m_Population.createRandomFoldings(sequence);
}

void Algorithm::browsePopulation(std::ostream &outputStream) 
{
	m_Population.browse(outputStream);
}