#include "folding.h"


Folding::Folding(std::string &sequence)
{
	srand (time(NULL));

	for (unsigned int i = 0; i < sequence.size(); ++i) // mal ein paar reinwerfen
	{
		Element newElement;
		newElement.setDirection(static_cast<Direction>(rand()%3));
		if (sequence.at(i)=='1')
		{
			newElement.setHydrophob(true);
		}
		m_Elements.push_back(newElement);
	}

}

Folding::~Folding()
{
}

void Folding::browse(std::ostream &outputStream) 
{
	for (unsigned int i=0;i<m_Elements.size();++i)
	{
		outputStream << m_Elements.at(i).getDirection() << std::endl;
	}
}