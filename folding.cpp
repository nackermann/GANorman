#include "folding.h"


Folding::Folding(std::string &sequence)
{
	for (unsigned int i = 0; i < sequence.size(); ++i)
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
		//outputStream << m_Elements.at(i).getDirection() << " ";
		if (m_Elements.at(i).getDirection()==Left)
		{
			outputStream << "Links ";
		}
		else if (m_Elements.at(i).getDirection()==Right)
		{
			outputStream << "Rechts ";
		}
		else
		{
			outputStream << "Geradeaus ";
		}

		if (m_Elements.at(i).isHydrophob())
		{
			outputStream << "Black - Hydrophob(1) ";
		}
		else
		{
			outputStream << "White - Hydrophil(0) ";
		}
		outputStream << std::endl;
	}
}