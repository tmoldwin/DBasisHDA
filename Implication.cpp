
#include<iostream>
#include<string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

class Implication
{ 
private:
	vector<int> LeftHandSide;
	vector<int> RightHandSide;
public:
	Implication(vector<int> lhs, vector<int> rhs);
	string toString();
};

Implication::Implication(vector<int> lhs, vector<int> rhs){
	LeftHandSide = lhs;
	RightHandSide = rhs;
}

string Implication::toString(){
	stringstream ss;
	for(unsigned int i = 0; i < LeftHandSide.size(); i++){
		ss << LeftHandSide[i] << " ";
	}
	ss << ("-> ");
	for(unsigned int i = 0; i <LeftHandSide.size(); i++){
		ss << RightHandSide[i] << " ";
	}
	return ss.str();
}

int main(){
	vector<int> v1 = vector<int>();
	vector<int> v2 = vector<int>();
	v1.push_back(2);
	v1.push_back(5);
	v1.push_back(3);
	v2.push_back(7);
	v2.push_back(8);
	v2.push_back(9);
	Implication i1 = Implication(v1,v2);
	cout << i1.toString();
	while(true);
};





