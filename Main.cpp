#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include<iostream>
#include <cstdlib>
#include "Table.h"

std::vector<std::vector<char> > * readTable (std::string fileName){
    std::ifstream inFile;
    inFile.open(fileName.c_str());

    if (! inFile) {
        std::cerr << "Unable to open file " << fileName;
    }

    else{
        int numRows;
        int numColumns;
        inFile >> numRows;
        inFile >> numColumns;

		std::vector<char> row(numColumns);
        std::vector<std::vector<char> > * matrix = new std::vector<std::vector<char> >(numRows,row);
        for(int i=0; i<numRows; i++){
            for(int j=0; j<numColumns; j++){
                inFile >> (*matrix)[i][j];
            }
        }

        inFile.close();
        return matrix;
    }

    return 0;
};

int printMatrix(std::vector<std::vector<char> > * matrix){
    int numRows = matrix->size();
    int numColumns = (*matrix)[0].size();

    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numColumns;j++){
            std::cout << (*matrix)[i][j] << " ";
        }
        std::cout << "\n";
    }
    while(true);
}

void testReadFile(){
    std::vector<std::vector<char> > * matrix = readTable("table1.txt");
    printMatrix(matrix);
}

int main(int argc, char **argv){
    testReadFile();
}
