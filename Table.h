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
#include "SetOperations.h"
#ifndef ____Table__
#define ____Table__

class Table {
private:
    std::vector<std::vector<char> > matrix;
    std::vector<std::vector<int> > columnComparisonTable; /*an n*n matrix (n is the number of columns in the reduced
                                                           * table) whose rows and columns represent
                                                           *  the columns of the reduced table. columnComparisonTable[i][j] gives 
                                                           you the result of compareColumns(i,j). This technique is used so we don't have to 
                                                           perform a search through the table n^2 times each time we want to know which columns
                                                           are subsets of other columns*/
    std::vector<std::vector<int> > rowComparisonTable; /*
                                                        * Comparison table for rows, similar to columnComparisonTable
                                                        */
    std::vector<Implication> completeImplications;
    std::map<int, int> reducedToOriginal;
    std::map<int, std::vector<int> > equivalentColumns;

    int compareColumns(int column1, int column2); //more ones is smaller column; column numbering starts from 0
    int compareRows(int row1, int row2); // more ones is larger row; row numbering starts from 0
    void reduceTable();
    void createColumnComparisonTable();
    void createRowComparisonTable();
    void createUpandDownArrows();
public:

    Table(std::vector<std::vector<char> > inputtable) {
        matrix = inputtable;
        reduceTable();
        createRowComparisonTable();
        createColumnComparisonTable();
        createUpandDownArrows();

    };

    std::vector<Implication> FindSBasis() {
        completeImplications = getFullBinaryBasis();
        std::vector<Implication> nonbinary = getFullNonBinaryBasis();
        completeImplications.insert(completeImplications.end(), nonbinary.begin(), nonbinary.end());
        return completeImplications;
    };

    std::vector<Implication> getBinaryBasis(int column); //Gets the binary basis for a particular column

    std::vector<Implication> getFullBinaryBasis(); //Gets the binary basis for the entire table
    std::vector<int> getxD(int column); //returns xD for a particular column
    std::vector<int> getMx(int column); //returns Mx for a particular column
    std::vector<std::vector<int> >getComplementedFamilies(int column);

    std::vector<Implication> getNonBinaryBasis(int column); //Gets the nonbinary basis for a particular column

    std::vector<Implication> getFullNonBinaryBasis(); //Gets the nonbinary basis for the entire table

    std::vector<std::vector<char> > get_matrix() {
        return matrix;
    };

    std::vector<std::vector<int> > getColumnComparisonTable() {
        return columnComparisonTable;
    };
    
    std::vector<std::vector<int> > getRowComparisonTable() {
        return rowComparisonTable;
    };
};
void printImplications(std::vector<Implication> implications);
#endif /* defined(____Table__) */
