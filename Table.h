//
//  Table.h
//
//
//  Created by Joshua A Blumenkopf on 4/16/13.
//
//
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include<iostream>
#include <cstdlib>
#include "Implication.h"
#ifndef ____Table__
#define ____Table__

class Table {
private:
    std::vector<std::vector<char> > matrix;
    std::vector<Implication> implications;
    std::map<int, int> reducedToOriginal;
    std::map<int, std::vector<int> > equivalentColumns;
    
    int compareColumns(int column1, int column2);//more ones is smaller column; numbering starts from 0
    
    void reduceTable();
public:
    
    Table(std::vector<std::vector<char> > inputtable) {
        matrix = inputtable;
        reduceTable();
    };
    
    std::vector<std::vector<char> > get_matrix() {
        return matrix;
    };
};

#endif /* defined(____Table__) */
