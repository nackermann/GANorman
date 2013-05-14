#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <ostream>

#include "folding.h"

class Population
{
public:
	Population();
	~Population();

	void createRandomFolding(std::string& sequence);
    void killPopulation(void);
    
    Folding& getFolding(unsigned int index);

	void browse(std::ostream &outputStream);

private:
	std::vector<Folding> m_Foldings;
};


#endif