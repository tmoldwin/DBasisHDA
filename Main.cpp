#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<iostream>
#include <cstdlib>
#include "Table.h"
#include "Implication.h"
#include "SetOperations.h"

//Reads the table from a file, outputs a vector<vector<char>>
std::vector<std::vector<char> > * readTable(std::string fileName) {
    std::ifstream inFile;
    inFile.open(fileName.c_str());
    
    if (!inFile) {
        std::cerr << "Unable to open file " << fileName;
    }
    else {
        int numRows;
        int numColumns;
        inFile >> numRows;
        inFile >> numColumns;
        
        std::vector<char> row(numColumns);
        std::vector<std::vector<char> > * matrix =
        new std::vector<std::vector<char> >(numRows, row);
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                inFile >> (*matrix)[i][j];
            }
        }
        inFile.close();
        return matrix;
    }
    
    return 0;
}
;

//Prints the matrix, for testing purposes only
void printMatrix(std::vector<std::vector<char> > * matrix) {
    int numRows = matrix->size();
    int numColumns = (*matrix)[0].size();
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            std::cout << (*matrix)[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void printMatrix(std::vector<std::vector<int> > * matrix) {
    int numRows = matrix->size();
    int numColumns = (*matrix)[0].size();
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            printf("%3d",(*matrix)[i][j] );
        }
        std::cout << "\n";
    }
}

void testReadFile() {
    std::vector<std::vector<char> > * matrix = readTable("table1.txt");
    printMatrix(matrix);
    delete matrix;
}

void testComparisonTable(){
    std::vector<std::vector<char> > * m = readTable("tablereducetest3.txt");
    std::vector<std::vector<char> >  matrix = *m;
    Table test1(matrix);
    std::vector<std::vector<int> >  comparisonTable = test1.get_ComparisonTable();
    printMatrix(&comparisonTable);
    delete m;
}

void testReduceTable(){
   std::vector<std::vector<char> > * m = readTable("tableupdowntest.txt");
    std::vector<std::vector<char> >  matrix = *m;
    Table test(matrix);
    std::vector<std::vector<char> >  matrix3=test.get_matrix();
    printMatrix(&matrix3);
    delete m;
}

void testGetBinaryBasis(){
    std::vector<std::vector<char> > * m = readTable("tablereducetest3.txt");
    std::vector<std::vector<char> >  matrix = *m;
    Table test(matrix);
    std::vector<Implication> implications = test.getFullBinaryBasis();
    printImplications(implications);
    delete m;
}
void testGetFullNonBinaryBasis()
{
    std::vector<std::vector<char> > * m = readTable("tableupdowntest.txt");
    std::vector<std::vector<char> >  matrix = *m;
    Table test(matrix);
    test.getFullNonBinaryBasis();
    delete m;
}

int main(int argc, char **argv) {
    std::cout << "\nTesting readFile()\n";
    testReadFile();
    std::cout << "\nTesting Implication\n";
    testImplication();
    std::cout << "\nTesting Complement\n";
    testComplement();
    std::cout << "\nTesting Intersection\n";
    testIntersection();
    std::cout << "\nTesting Reduction\n";
    testReduceTable();
    std::cout << "\nTesting ComparisonTable\n";
    testComparisonTable();
    std::cout << "\nTesting GetBinaryBasis\n";
    testGetBinaryBasis();
    std::cout << "\nTesting GetNonBinaryBasis\n";
    testReduceTable();
    testGetFullNonBinaryBasis();
}
