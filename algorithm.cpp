#include "algorithm.h"

#include <iostream>
#include <fstream>

Algorithm::Algorithm()
{
	srand (static_cast<unsigned int>(time(NULL)));
}

Algorithm::~Algorithm()
{
}

void Algorithm::run(std::string &sequence, unsigned int populationSize, unsigned int maxGeneration, float mutationRate, float crossoverRate, Selection *selection)
{
    m_Population.setSelection(selection);
    
    
	for (unsigned int i = 0; i < populationSize; ++i)	// Faltungen erzeugen, je nachdem wie groß die Population werden soll
	{
		m_Population.createRandomFolding(sequence);
	}

	m_Population.evaluate();

	unsigned int generation = 0;
    
    std::ofstream logfile("average.txt");

	while (generation < maxGeneration)
	{
		++generation;
		m_Population.selection();
		m_Population.crossover(crossoverRate);
		m_Population.mutation(mutationRate);
		m_Population.evaluate();
        std::cout << generation << "\t";
		browseEvaluation(std::cout);
        logfile << generation << "\t";
        browseEvaluation(logfile);
	}
    
    logfile.close();
}

Population& Algorithm::getPopulation(void)
{
    return m_Population;
}

void Algorithm::browsePopulation(std::ostream &outputStream) 
{
	m_Population.browse(outputStream);
}

void Algorithm::browseEvaluation(std::ostream &outputStream) 
{
	outputStream << m_Population.getEvaluation() << "\t" << m_Population.getBestFolding().getFitness() << std::endl;
}