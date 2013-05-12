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
    } else {
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

//this is for printing the matrix of row/column comparisons

void printMatrix(std::vector<std::vector<int> > * matrix) {
    int numRows = matrix->size();
    int numColumns = (*matrix)[0].size();
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            printf("%3d", (*matrix)[i][j]);
        }
        std::cout << "\n";
    }
}

void testReadFile() {
    std::vector<std::vector<char> > * matrix = readTable("table1.txt");
    printMatrix(matrix);
    delete matrix;
}

void testColumnComparisonTable() {
    std::vector<std::vector<char> > * m = readTable("tablereducetest3.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test1(matrix);
    std::vector<std::vector<int> > comparisonTable = test1.getColumnComparisonTable();
    printMatrix(&comparisonTable);
    delete m;
}

void testRowComparisonTable() {
    std::vector<std::vector<char> > * m = readTable("tablereducetest3.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test1(matrix);
    std::vector<std::vector<int> > comparisonTable = test1.getRowComparisonTable();
    printMatrix(&comparisonTable);
    delete m;
}

void testReduceTable() {
    std::vector<std::vector<char> > * m = readTable("tablereducetest2.txt");
    printMatrix(m);

    std::vector<std::vector<char> > matrix = *m;
    Table test(matrix);
    std::vector<std::vector<char> > matrix3 = test.get_matrix();
    printMatrix(&matrix3);
    delete m;
}

void testGetBinaryBasis() {
    std::vector<std::vector<char> > * m = readTable("tablereducetest3.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test(matrix);
    std::vector<Implication> implications = test.getFullBinaryBasis();
    printImplications(implications);
    delete m;
}

void testGetNonBinaryBasis() {
    std::vector<std::vector<char> > * m = readTable("table1.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test(matrix);
    /*
    for (int i; i < matrix.size(); i++){
        std::cout << "nonbinary basis for" << i;
        std::vector<Implication> implications = test.getNonBinaryBasis(i);
        printImplications(implications);
    }
     */
    std::cout << "nonbinary basis for column" << 1 << "\n";
    std::vector<Implication> implications = test.getNonBinaryBasis(1);
    printImplications(implications);
    delete m;
}

void testGetFullNonBinaryBasis() {
    std::vector<std::vector<char> > * m = readTable("tablereducetest.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test(matrix);
    test.getFullNonBinaryBasis();
    delete m;
}

void testWriteComplementedFamilies() {
    std::vector<std::vector<char> > * m = readTable("table1.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test(matrix);
    /*
    for (int i = 0; i < matrix.size(); i++) {
        std::cout << "families for column" << i << "\n";
        test.writeComplementedFamilies(test.getComplementedFamilies(i));
    }
     */
    std::cout << "families for column" << 1 << "\n";
    test.writeComplementedFamilies(test.getComplementedFamilies(1));
    delete m;
}

void testGetFullSBasis() {
    std::vector<std::vector<char> > * m = readTable("table1.txt");
    std::vector<std::vector<char> > matrix = *m;
    Table test(matrix);
    std::vector<Implication> implications = test.FindSBasis();
    printImplications(implications);
    delete m;
}

int main(int argc, char **argv) {
    std::cout << "\nTesting readFile()\n";
    testReadFile();
    std::cout << "\nTesting Implication\n";
    testImplication();
    std::cout << "\nTesting Reduction\n";
    testReduceTable();
    std::cout << "\nTesting ColumnComparisonTable\n";
    testColumnComparisonTable();
    std::cout << "\nTesting RowComparisonTable\n";
    testRowComparisonTable();
    std::cout << "\nTesting GetBinaryBasis\n";
    testGetBinaryBasis();
    std::cout << "\nTesting reduceTable\n";
    testReduceTable();
    std::cout << "\nTesting WriteFamilies\n";
    testWriteComplementedFamilies();
    //std::cout << "\nTesting getNonBinaryBasis\n";
    //testGetNonBinaryBasis();
    //std::cout << "\nTesting GetFullNonBinaryBasis\n";
    //testGetFullNonBinaryBasis();
    //std::cout << "\nTesting GetSBasis\n";
    //testGetFullSBasis();          
}
