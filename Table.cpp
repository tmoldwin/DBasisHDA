//
//  Table.cpp
//
//
//  Created by Joshua A Blumenkopf on 4/16/13.
//
//

 #include "Table.h"
void Table::reduceTable()
{
    // following loop removes columns with all ones
    for (int i = 0; i < matrix[0].size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if ((matrix[j][i] )!='1') break;
            if (j == (matrix.size() - 1)) {
                for (int k = 0; k < matrix.size(); k++) {
                    matrix[k].erase(matrix[k].begin() + i);
                    // insert statement mapping new columns to old
                }
            }
            
        }
    }
    // following loop collapses indentical columns together

    for (int i = 0; i < matrix[0].size() - 1; i++) {
        for (int j = i+1; j < matrix[0].size(); j++) {
            if (compareColumns(i, j) == 0) {
                for (int k = 0; k < matrix.size(); k++) {
                    matrix[k].erase(matrix[k].begin() + j);
                    // insert statement mapping new columns to old
                }
                
            }
        }
    }
    
    // following loop removes columns whose closure i\column is not closed
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<int> closure; //contains closure i\column in form of 1s
        for (int j = 0; j < matrix[0].size(); j++)//initialize closure\column to contain set\column
        {
            if (j != i) closure.push_back(1);
            else closure.push_back(0);
        }
        for (int j = 0; j < matrix.size(); j++)//removes from closure columns with zero where column i has 1
        {
            if (matrix[j][i] == '1') {
                for (int k = 0; k < matrix[0].size(); k++) {
                    if (matrix[j][k] != '1')closure[k] = 0;
                }
            }
        }
        //see if support of closure=support of column by seeing if it is not less
        bool a = false; //a false means no difference in support has been found
        for (int j = 0; j < matrix.size() && a == false; j++) {
            if (matrix[j][i] != '1' ) {
                for (int k = 0; k < matrix[0].size(); k++) {
                    if (closure[k] == 1 && matrix[j][k] != '1')break;
                    if (k == matrix[0].size() - 1) a = true;
                }
                
            }
        }
        if (a == false) {
            for (int k = 0; k < matrix.size(); k++) {
                matrix[k].erase(matrix[k].begin() + i);
                // insert statement mapping new columns to old
            }
            
        }
        
    }
    
    
};
int Table::compareColumns(int column1, int column2)
{
    int a = 0;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][column1]=='1' && matrix[i][column2]!='1') {
            if (a == 0 || a == -1)a = -1;
                else {
                    a = -2;
                    break;
                }
        }
        if (matrix[i][column1]!='1' && matrix[i][column2]=='1') {
            if (a == 0 || a == 1)a = 1;
                else {
                    a = -2;
                    break;
                }
        }
    }

    return a;
};

int Table::compareRows(int row1, int row2)
{
    int a = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[row1][i]=='1' && matrix[row2][i]!='1') {
            if (a == 0 || a == 1)a = 1;
            else {
                a = -2;
                break;
            }
        }
        if (matrix[row1][i]!='1' && matrix[row2][i]=='1') {
            if (a == 0 || a == -1)a = -1;
            else {
                a = -2;
                break;
            }
        }
    }
    
    return a;
};
void Table::createUpandDownArrows()
{
    //up arrows
    for (int i=0; i<matrix[0].size(); i++) {
        for (int j=0; j<matrix.size(); j++) {
            if (matrix[j][i]!='1') {
                for (int k=0; k<matrix.size(); k++) {
                    if (compareRows(j,k)==-1&& matrix[k][i]!='1')  break;
                    if(k==matrix.size()-1)matrix[j][i]='u';
                }
            }
        }
       
    }
    
    //down arrows
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            if (matrix[i][j]!='1') {
                for (int k=0; k<matrix[0].size(); k++) {
                    if (compareColumns(j,k)==1&& matrix[i][k]!='1')  {std::cout<< i<<j<<k<<"\n";break;}
                    if(k==matrix[0].size()-1){
                        if (matrix[i][j]=='u')  matrix[i][j]='b';
                         else   matrix[i][j]='d';
                    }
                }
            }
        }
        
    }

    
    
};
