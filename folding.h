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

	int getFitness(void);
    Element& getElement(unsigned int index);
    unsigned long getSize(void);
    int getOverlaps(void);

	void browse(std::ostream &outputStream);
	void calculatePositionsAndDirections(void);
	void calculateFitnessAndOverlaps(void);
	void draw(int offsetX, int offsetY);

private:
	std::vector<Element> m_Elements;
	unsigned int m_Fitness; // Fitness soll nie negativ werden
	unsigned int m_Overlaps;
};

#endif