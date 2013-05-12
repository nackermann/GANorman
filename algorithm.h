#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <ostream>

#include "population.h"

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	void run(std::string& sequence);

	void browsePopulation(std::ostream &outputStream);

private:
	Population m_Population;
};

#endif