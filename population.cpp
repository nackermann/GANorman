#include "population.h"

Population::Population()
	: m_Evaluation(0.f),
	m_AggregatedFoldingFitness(0)
{
}

Population::~Population()
{
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

void Population::evaluate(void)		// wird noch nirgends aufgerufen
{
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
	std::vector<Folding> selectedFoldings;

	for (unsigned int i = 0;i < m_Foldings.size();++i)
	{
		int r = rand() % m_AggregatedFoldingFitness;
		int sumFitness = 0;
	
		for (unsigned int j = 0; j < m_Foldings.size(); ++j)
		{
			sumFitness += m_Foldings.at(j).getFitness();
			if(sumFitness>r)
			{
				selectedFoldings.push_back(m_Foldings.at(j));
				break;
			}
		}
	}

	m_Foldings = selectedFoldings;
}

void Population::crossover(float crossoverRate) 
{

}

void Population::mutation(float mutationRate) 
{

}