#ifndef FOLDING_H
#define FOLDING_H

#include <vector>
#include <ostream>

#include "element.h"

class Folding
{
public:
	Folding();
	~Folding();

	void browse(std::ostream &outputStream);

private:
	std::vector<Element> m_Elements;
};

#endif