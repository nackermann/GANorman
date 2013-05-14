#include "algorithm.h"

Algorithm::Algorithm()
{
	srand (static_cast<unsigned int>(time(NULL)));
}

Algorithm::~Algorithm()
{
}

void Algorithm::run(std::string& sequence, unsigned int populationSize) 
{
	for (unsigned int i = 0; i < populationSize; ++i)
	{
		m_Population.createRandomFolding(sequence);
	}
}

Population& Algorithm::getPopulation(void)
{
    return m_Population;
}

void Algorithm::browsePopulation(std::ostream &outputStream) 
{
	m_Population.browse(outputStream);
}