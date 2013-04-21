#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include "Implication.h"

Implication::Implication(std::vector<int> * lhs, std::vector<int> * rhs) {
	leftHandSide = lhs;
	rightHandSide = rhs;

}

std::string Implication::toString() {
	std::stringstream ss;
	for (unsigned int i = 0; i < leftHandSide->size(); i++) {
		ss << (*leftHandSide)[i] << " ";
	}
	ss << ("-> ");
	for (unsigned int i = 0; i < leftHandSide->size(); i++) {
		ss << (*rightHandSide)[i] << " ";
	}
	return ss.str();
}

void testImplication() {
	std::vector<int> * v1 = new std::vector<int>();
	std::vector<int> * v2 = new std::vector<int>();
	v1->push_back(2);
	v1->push_back(5);
	v1->push_back(3);
	v2->push_back(7);
	v2->push_back(8);
	v2->push_back(9);
	Implication i1 = Implication(v1, v2);
	std::cout << i1.toString();
}


