#ifndef FOLDING_H
#define FOLDING_H

#include <vector>
#include <ostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "element.h"

class Folding
{
public:
	Folding(std::string &sequence);
	~Folding();

	void browse(std::ostream &outputStream);
	int calculateFitness(void);
	void createMatrix(void);

private:
	std::vector<Element> m_Elements;
};

#endif