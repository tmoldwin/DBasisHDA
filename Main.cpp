#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<char>> * readTable (string fileName){
    ifstream inFile;
    inFile.open(fileName, ios::in);

    if (! inFile) {
        cerr << "Unable to open file " << fileName << endl;
    }

    else{
        int numRows;
        int numColumns;
        inFile >> numRows;
        inFile >> numColumns;

        vector<vector<char>> * matrix = new vector<vector<char>>(numRows,numColumns);
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

int printMatrix(vector<vector<char>> * matrix){
    int numRows = matrix->size();
    int numColumns = (*matrix)[0].size();

    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numColumns;j++){
            cout << (*matrix)[i][j] << " ";
        }
        cout << "\n";
    }
    while(true);
}

int testReadFile(){
    vector<vector<char>> * matrix = readTable("table1.txt");
    printMatrix(matrix);
}
