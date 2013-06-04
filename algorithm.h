#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "population.h"

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	void run(std::string &sequence, unsigned int populationSize, unsigned int maxGeneration, float mutationRate, float crossoverRate, Selection *selection);
    
    Population& getPopulation(void);

	void browsePopulation(std::ostream &outputStream);

	void browseEvaluation(std::ostream &outputStream);

private:
	Population m_Population;
};

#endif