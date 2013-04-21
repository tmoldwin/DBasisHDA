<<<<<<< HEAD
/*
 * Author: Toviah Moldwin
 */
#ifndef H_IMPLICATION
#define H_IMPLICATION 


#include <string>
#include <vector>


class Implication {
private:
	std::vector<int> * leftHandSide;
	std::vector<int> * rightHandSide;
public:
	Implication(std::vector<int> * lhs, std::vector<int> * rhs);
	std::string toString();
	~Implication(){
		delete leftHandSide;
		delete rightHandSide;
	}
};

void testImplication();

#endif /*IMPLICATION_H_INCLUDED__  */
=======
//
//  Implication.h
//  
//
//  Created by Joshua A Blumenkopf on 4/21/13.
//
//

#ifndef _Implication_h
#define _Implication_h


#include<iostream>
#include<string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
class Implication
{
private:
	std::vector<int> * LeftHandSide;
	std::vector<int> * RightHandSide;
public:
	Implication(std::vector<int>* lhs, std::vector<int>* rhs);
	std::string toString();
};



#endif
>>>>>>> broke implication into header and main file, started testing table in main
