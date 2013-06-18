#include "RouletteWheelSelection.h"

RouletteWheelSelection::RouletteWheelSelection()
{
    
}

RouletteWheelSelection::~RouletteWheelSelection()
{
    
}

void RouletteWheelSelection::select(Population &population)
{
    
    std::vector<Folding> &foldings = population.getFoldings();
    
    if (population.getAggregatedFoldingFitness()==0)
    {
        return;
    }

    std::vector<Folding> selectedFoldings;

    for (unsigned int i = 0;i < foldings.size();++i)
    {
        int r = rand() % population.getAggregatedFoldingFitness();
        int sumFitness = 0;

        for (unsigned int j = 0; j < foldings.size(); ++j)
        {
            sumFitness += foldings.at(j).getFitness();
            if(sumFitness>r)
            {
                selectedFoldings.push_back(foldings.at(j));
                break;
            }
        }
    }

    foldings = selectedFoldings;
}