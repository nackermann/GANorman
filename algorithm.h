#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "population.h"

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	void run(void);

private:
	Population m_Population;
};

#endif