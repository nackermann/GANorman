#include "population.h"

#include "selection.h"

Population::Population()
	: m_Evaluation(0.f),
	m_AggregatedFoldingFitness(0),
	m_BestFolding(NULL),
    m_Selection(NULL)
{
}

Population::~Population()
{
    delete m_Selection;
}

void Population::browse(std::ostream &outputStream) 
{
	for (unsigned int i=0;i<m_Foldings.size();++i)
	{
		m_Foldings.at(i).browse(outputStream);
		outputStream << std::endl << "-------------" << std::endl;
	}

	outputStream << "\n Evaluation: " << m_Evaluation;
}

void Population::createRandomFolding(std::string& sequence)
{
	Folding newFolding(sequence);

	m_Foldings.push_back(newFolding);
}

void Population::killPopulation(void)
{
    m_Foldings.clear();
}

void Population::draw(int chainDistance, int maxRows) 
{
	int x = 0;
	int y = 0;

	for (unsigned int i=0;i<m_Foldings.size();++i)
	{
		if (y>=maxRows)
		{
			++x;
			y = 0;
		}

		m_Foldings.at(i).draw(x*chainDistance,y*chainDistance);

		++y;
	}
}

void Population::evaluate(void)
{
	m_BestFolding = &m_Foldings.at(0);


	for (unsigned int i = 0; i < m_Foldings.size(); ++i)
	{
		m_Foldings.at(i).calculatePositionsAndDirections();
		m_Foldings.at(i).calculateFitnessAndOverlaps();

		if (m_BestFolding->getFitness() < m_Foldings.at(i).getFitness())
		{
			m_BestFolding = &m_Foldings.at(i);
		}

	}

	unsigned int aggregatedFoldingFitness = 0;

	for (unsigned int i=0;i<m_Foldings.size();++i)
	{
		aggregatedFoldingFitness += m_Foldings.at(i).getFitness();
	}

	m_AggregatedFoldingFitness = aggregatedFoldingFitness;
	m_Evaluation = static_cast<float>(aggregatedFoldingFitness)/static_cast<float>(m_Foldings.size());
}

Folding& Population::getFolding(unsigned int index)
{
    return m_Foldings.at(index);
}

unsigned long Population::getNumberOfFoldings(void)
{
    return m_Foldings.size();
}

float Population::getEvaluation(void) 
{
	return m_Evaluation;
}


void Population::selection(void) 
{
    m_Selection->select(*this);
}

void Population::crossover(float crossoverRate)
{

	for (unsigned int i=0; i < (unsigned int)(m_Foldings.size()*crossoverRate); ++i)
	{
		Folding &crossoverCandidate1 = m_Foldings.at(rand() % m_Foldings.size());
		Folding &crossoverCandidate2 = m_Foldings.at(rand() % m_Foldings.size());
	
		for (unsigned int i = (unsigned int)(rand() % crossoverCandidate1.getSize()); i < crossoverCandidate1.getSize(); ++i)
		{
			std::swap(crossoverCandidate1.getElement(i), crossoverCandidate2.getElement(i));	// std::swap langsam, ersetzen?
		}
	}

}

void Population::mutation(float mutationRate) 
{
	for (unsigned int i=0; i < (unsigned int)(m_Foldings.size()*mutationRate); ++i)
	{
		Folding &mutationCandidate = m_Foldings.at(rand() % m_Foldings.size());

		unsigned int elementToMutate = (unsigned int)(rand() % mutationCandidate.getSize());

		Direction &directionToMutate = mutationCandidate.getElement(elementToMutate).getDirection();

		Direction rDirection = static_cast<Direction>(rand()%3);

		while (rDirection == directionToMutate)
		{
			rDirection = static_cast<Direction>(rand()%3);
		}

		mutationCandidate.getElement(elementToMutate).setDirection(rDirection);

	}
	
}

Folding& Population::getBestFolding(void)
{
	return (*m_BestFolding);
}

void Population::setSelection(Selection *selection)
{
    m_Selection = selection;
}

std::vector<Folding>& Population::getFoldings(void)
{
    return m_Foldings;
}

unsigned int Population::getAggregatedFoldingFitness(void)
{
    return m_AggregatedFoldingFitness;
}