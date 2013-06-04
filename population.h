#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include <ostream>

#include "folding.h"

class Selection;

class Population
{
public:
	Population();
	~Population();

	void createRandomFolding(std::string& sequence);
    void killPopulation(void);
	void draw(int chainDistance,int maxRows);
	void evaluate(void);
	void selection(void);
	void crossover(float crossoverRate);
	void mutation(float mutationRate);

    
    Folding& getFolding(unsigned int index);
    unsigned long getNumberOfFoldings(void);
	float getEvaluation(void);
	Folding& getBestFolding(void);
    void setSelection(Selection *selection);
    std::vector<Folding>& getFoldings(void);
    unsigned int getAggregatedFoldingFitness(void);

	void browse(std::ostream &outputStream);

private:
	std::vector<Folding> m_Foldings;
	float m_Evaluation;
	unsigned int m_AggregatedFoldingFitness;
    Folding *m_BestFolding;
    Selection *m_Selection;
};


#endif