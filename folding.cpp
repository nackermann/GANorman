#include "folding.h"

Folding::Folding()
{
	for (int i = 0; i < 5; ++i) // mal ein paar reinwerfen
	{
		Element newElement;
		newElement.setDirection(Right);
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