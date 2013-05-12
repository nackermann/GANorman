#include <iostream>
#include <string>

#include "algorithm.h"


//#include "folding.h"
//#include "population.h"


int main()
{
	// benchmark sequences for the 2d HP model
	// 0 = hydrophil, "white"
	// 1 = hydrophob, "black"
	// source: Ron Unger, John Moult: Genetic Algorithms for Protein Folding Simulations,
	//         Journal of Molecular Biology, Vol. 231, No. 1, May 1993

	std::string SEQ20 = "10100110100101100101";
	std::string SEQ24 = "110010010010010010010011";
	std::string SEQ25 = "0010011000011000011000011";
	std::string SEQ36 = "000110011000001111111001100001100100";
	std::string SEQ48 = "001001100110000011111111110000001100110010011111";
	std::string SEQ50 = "11010101011110100010001000010001000101111010101011";

	
	Algorithm myAlgorithm;

	myAlgorithm.run(SEQ20);

	myAlgorithm.browsePopulation(std::cout);

	std::cin.get();
}