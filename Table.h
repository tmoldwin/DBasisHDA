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
    std::vector<std::vector<int> > columnComparisonTable;
    std::vector<Implication> implications;
    std::map<int, int> reducedToOriginal;
    std::map<int, std::vector<int> > equivalentColumns;
    
    int compareColumns(int column1, int column2);//more ones is smaller column; column numbering starts from 0
    int compareRows(int row1, int row2);// more ones is larger row; row numbering starts from 0
    void reduceTable();
    void createColumnComparisonTable();
    void createUpandDownArrows();
public:
    
    Table(std::vector<std::vector<char> > inputtable) {
        matrix = inputtable;
        reduceTable();
        createColumnComparisonTable();
        createUpandDownArrows();
    };
    
    std::vector<Implication> getBinaryBasis(int column); //Gets the binary basis for a particular column
    
    std::vector<Implication> getFullBinaryBasis();    //Gets the binary basis for the entire table
    
    std::vector<std::vector<char> > get_matrix() {
        return matrix;
    };
    
    std::vector<std::vector<int> > get_ComparisonTable() {
        return columnComparisonTable;
    };
};
void printImplications(std::vector<Implication> implications);
#endif /* defined(____Table__) */
