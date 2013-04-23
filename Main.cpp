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

void testReadFile() {
    std::vector<std::vector<char> > * matrix = readTable("table1.txt");
    printMatrix(matrix);
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
}
