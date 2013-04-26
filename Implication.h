/*
 * Author: Toviah Moldwin
 */
#ifndef H_IMPLICATION
#define H_IMPLICATION 


#include <string>
#include <vector>


class Implication {
private:
	std::vector<int>  leftHandSide;
	std::vector<int>  rightHandSide;
public:
	Implication(std::vector<int>  lhs, std::vector<int>  rhs);
	std::string toString();
};

void testImplication();

#endif /*IMPLICATION_H_INCLUDED__  */
