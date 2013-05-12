#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <ostream>

#include "population.h"

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	void run(std::string& sequence, unsigned int populationSize);

	void browsePopulation(std::ostream &outputStream);

private:
	Population m_Population;
};

#endif