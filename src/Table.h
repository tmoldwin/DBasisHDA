//
//  Table.h
//
//
//  Created by Joshua A Blumenkopf on 4/16/13.
//
//
#define _FILE2_LOAD_FROM_MEMORY_
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cstdlib>
//#include "shd31/shd.c"
#include "Implication.h"



#ifndef ____Table__
#define ____Table__

class Table {
private:
    int diffsbasisdbasis;
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
    std::vector<int> reducedToOriginal;
    std::map<int, std::vector<int> > equivalentColumns;
    std::vector<std::vector<int> > blacklistedHittingSets;//lhss with too small supports
    int minSup;//user parameter for minimal support for lhs of implications
    std::vector<int> implicationSupport;//gives the magnitude of the support for the ith implication
    int compareColumns(int column1, int column2); //more ones is smaller column; column numbering starts from 0;Returns 1 if column1 is greater, -1 if column2  is greater, 0 if equal, -2 if incomparable
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
        minSup=1;
        diffsbasisdbasis=0;
    };
    void setminSup(int min){minSup=min;};

    std::vector<Implication> FindSBasis() {
        completeImplications = getFullBinaryBasis();
        std::vector<Implication> nonbinary = getFullNonBinaryBasis();
        completeImplications.insert(completeImplications.end(), nonbinary.begin(), nonbinary.end());
        return completeImplications;
    };
    
    std::vector<Implication> FindDBasis() {
        completeImplications = getFullBinaryBasis();
        std::vector<Implication> nonbinary = getDFullNonBinaryBasis();
        completeImplications.insert(completeImplications.end(), nonbinary.begin(), nonbinary.end());
        return completeImplications;
    };

    std::vector<Implication> getBinaryBasis(int column); //Gets the binary basis for a particular column

    std::vector<Implication> getFullBinaryBasis(); //Gets the binary basis for the entire table

    std::vector<int> getxD(int column); //returns xD for a particular column

    std::vector<int> getMx(int column); //returns Mx for a particular column

    std::vector<std::vector<int> >getComplementedFamilies(int column);
    
    char* runShd(std::vector< std::vector<int> > families);
    
    std::vector<Implication> getImplicationsFromDual(char* buffer, int column);
    
    void writeComplementedFamilies(std::vector< std::vector<int> > families);

    std::vector<Implication> readDualToImplication(int column);

    std::vector<Implication> getNonBinaryBasis(int column); //Gets the nonbinary basis for a particular column

    std::vector<Implication> getFullNonBinaryBasis(); //Gets the nonbinary basis for the entire table
    
    std::vector<Implication> getDNonBinaryBasis(int column); //Gets the << reduced D nonbinary basis for a particular column
    
    std::vector<Implication> getDFullNonBinaryBasis(); //Gets the << reduced D nonbinary basis for the entire table
    
    Implication mapImplication (Implication implication);
    //ToDo
   
    void writeOutput(std::string outputFileName);


    std::vector<std::vector<char> > get_matrix() {
        return matrix;
    };

    std::vector<std::vector<int> > getColumnComparisonTable() {
        return columnComparisonTable;
    };

    std::vector<std::vector<int> > getRowComparisonTable() {
        return rowComparisonTable;
    };
    void prettyprintImplications(std::vector<Implication> implications);//returns implications starting from 1 using the original table

};
void printImplications(std::vector<Implication> implications);//returns implications starting from 0 using reduced table

#endif /* defined(____Table__) */
