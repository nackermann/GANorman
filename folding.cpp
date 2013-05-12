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

int Folding::calculateFitness(void) 
{
	return 1; // bla
}

void Folding::createMatrix(void) 
{
	for (unsigned int i = 0; i < m_Elements.size(); ++i)
	{
		Vector2i position;
		ViewingDirection viewingDirection = m_Elements.at(i).getViewingDirection();
		Direction direction = m_Elements.at(i).getDirection();

		if (i==0)
		{
			if (direction == Straight)
			{
				m_Elements.at(i+1).setViewingDirection(East);
				position.x += 1;

			}
			else if (direction == Right)
			{
				m_Elements.at(i+1).setViewingDirection(South);
				position.y += -1;
			}
			else if (direction == Left)
			{
				m_Elements.at(i+1).setViewingDirection(North);
				position.y += 1;
			}
			m_Elements.at(i+1).setPosition(position);
			return;
		}

		
		if (viewingDirection == East && direction == Straight)
		{
			position.x = m_Elements.at(i).getPosition().x + 1;
			position.y = m_Elements.at(i).getPosition().y ;
			m_Elements.at(i+1).setViewingDirection(East);

		}
		else if (viewingDirection == East && direction == Right)
		{
			position.x = m_Elements.at(i).getPosition().x ;
			position.y = m_Elements.at(i).getPosition().y - 1;
			m_Elements.at(i+1).setViewingDirection(South);
		}
		else if (viewingDirection == East && direction == Left)
		{
			position.x = m_Elements.at(i).getPosition().x ;
			position.y = m_Elements.at(i).getPosition().y + 1;
			m_Elements.at(i+1).setViewingDirection(North);
		}
		else if (viewingDirection == North && direction == Straight)
		{
			position.x = m_Elements.at(i).getPosition().x;
			position.y = m_Elements.at(i).getPosition().y + 1;
			m_Elements.at(i+1).setViewingDirection(North);
		}
		else if (viewingDirection == North && direction == Right)
		{
			position.x = m_Elements.at(i).getPosition().x + 1;
			position.y = m_Elements.at(i).getPosition().y;
			m_Elements.at(i+1).setViewingDirection(East);
		}
		else if (viewingDirection == North && direction == Left)
		{
			position.x = m_Elements.at(i).getPosition().x - 1;
			position.y = m_Elements.at(i).getPosition().y;
			m_Elements.at(i+1).setViewingDirection(West);
		}
		else if (viewingDirection == South && direction == Straight)
		{
			position.x = m_Elements.at(i).getPosition().x;
			position.y = m_Elements.at(i).getPosition().y - 1;
			m_Elements.at(i+1).setViewingDirection(South);
		}
		else if (viewingDirection == South && direction == Right)
		{
			position.x = m_Elements.at(i).getPosition().x + 1;
			position.y = m_Elements.at(i).getPosition().y;
			m_Elements.at(i+1).setViewingDirection(East);
		}
		else if (viewingDirection == South && direction == Left)
		{
			position.x = m_Elements.at(i).getPosition().x - 1;
			position.y = m_Elements.at(i).getPosition().y;
			m_Elements.at(i+1).setViewingDirection(West);
		}
		else if (viewingDirection == West && direction == Straight)
		{
			position.x = m_Elements.at(i).getPosition().x - 1;
			position.y = m_Elements.at(i).getPosition().y;
			m_Elements.at(i+1).setViewingDirection(West);
		}
		else if (viewingDirection == West && direction == Right)
		{
			position.x = m_Elements.at(i).getPosition().x;
			position.y = m_Elements.at(i).getPosition().y + 1;
			m_Elements.at(i+1).setViewingDirection(North);
		}
		else if (viewingDirection == West && direction == Left)
		{
			position.x = m_Elements.at(i).getPosition().x;
			position.y = m_Elements.at(i).getPosition().y - 1;
			m_Elements.at(i+1).setViewingDirection(South);
		}

		m_Elements.at(i+1).setPosition(position);
	}
}