//
//  Table.cpp
//
//
//  Created by Joshua A Blumenkopf on 4/16/13.
//
//

#include "Table.h"

void Table::reduceTable() {
    //initializing map from old to new table
    for (int i = 0; i < matrix[0].size(); i++) {
        reducedToOriginal.push_back(i);
    }


    // following loop removes columns with all ones
    for (int i = 0; i < matrix[0].size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if ((matrix[j][i]) != '1') break;
            if (j == (matrix.size() - 1)) {
                for (int k = 0; k < matrix.size(); k++) {
                    matrix[k].erase(matrix[k].begin() + i);
                }
                equivalentColumns[reducedToOriginal[i]] = std::vector<int>(0, 0);
                for (int l = i; l < matrix[0].size(); l++) {
                    reducedToOriginal[l]++;
                }
                reducedToOriginal.pop_back();
                i--;
            }
        }
    }

    // following loop collapses indentical columns together, probably unnecessary as next loop will remove them anyway

    for (int i = 0; i < matrix[0].size() - 1; i++) {
        for (int j = i + 1; j < matrix[0].size(); j++) {
            if (compareColumns(i, j) == 0) {
                for (int k = 0; k < matrix.size(); k++) {
                    matrix[k].erase(matrix[k].begin() + j);
                }
                equivalentColumns[reducedToOriginal[j]] = std::vector<int>(1, reducedToOriginal[i]);
                for (int l = j; l < matrix[0].size(); l++) {
                    reducedToOriginal[l]++;
                }
                reducedToOriginal.pop_back();
                j--;
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
            if (matrix[j][i] != '1') {
                for (int k = 0; k < matrix[0].size(); k++) {
                    if (closure[k] == 1 && matrix[j][k] != '1')break;
                    if (k == matrix[0].size() - 1) a = true;
                }

            }
        }
        if (a == false) {
            for (int k = 0; k < matrix.size(); k++) {
                matrix[k].erase(matrix[k].begin() + i);
            }
            equivalentColumns[reducedToOriginal[i]] = std::vector<int>();
            for (int l = 0; l < closure.size(); l++) {
                if (closure[l] == 1) {
                    equivalentColumns[reducedToOriginal[i]].push_back(reducedToOriginal[l]);
                }
            }
            for (int l = i; l < matrix[0].size(); l++) {
                reducedToOriginal[l]++;
            }
            reducedToOriginal.pop_back();
            i--;
        }

    }
    for (int i = 0; i < reducedToOriginal.size(); i++) {
        std::cout << reducedToOriginal[i];
    }
    std::cout << '\n';
    for (std::map<int, std::vector<int> >::iterator it = equivalentColumns.begin(); it != equivalentColumns.end(); ++it) {
        std::cout << it->first << " => ";
        for (int i = 0; i < it->second.size(); i++) {
            std::cout << it->second[i];
        }
        std::cout << '\n';
    }
    // following loop removes rows with all ones
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if ((matrix[i][j]) != '1') break;
            if (j == (matrix[0].size() - 1)) {
                matrix.erase(matrix.begin() + i);
                i--;
            }

        }
    }
    // following loop collapses indentical rows together, probably unnecessary as next loop will remove them anyway

    for (int i = 0; i < matrix.size() - 1; i++) {
        for (int j = i + 1; j < matrix.size(); j++) {
            if (compareRows(i, j) == 0) {
                matrix.erase(matrix.begin() + j);
                j--;
            }
        }
    }

    // following loop removes rows whose closure i\row is not closed
    for (int i = 0; i < matrix.size(); i++) {
        std::vector<int> closure; //contains closure i\row in form of 1s
        for (int j = 0; j < matrix.size(); j++)//initialize closure\row to contain set\row
        {
            if (j != i) closure.push_back(1);
            else closure.push_back(0);
        }
        for (int j = 0; j < matrix[0].size(); j++)//removes from closure rows with zero where row i has 1
        {
            if (matrix[i][j] == '1') {
                for (int k = 0; k < matrix.size(); k++) {
                    if (matrix[k][j] != '1')closure[k] = 0;
                }
            }
        }
        //see if support of closure=support of row by seeing if it is not less
        bool a = false; //a false means no difference in support has been found
        for (int j = 0; j < matrix[0].size() && a == false; j++) {
            if (matrix[i][j] != '1') {
                for (int k = 0; k < matrix.size(); k++) {
                    if (closure[k] == 1 && matrix[k][j] != '1')break;
                    if (k == matrix.size() - 1) a = true;
                }

            }
        }
        if (a == false) {
            matrix.erase(matrix.begin() + i);
            i--;
        }

    }


};

int Table::compareColumns(int column1, int column2) {
    int a = 0;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][column1] == '1' && matrix[i][column2] != '1') {
            if (a == 0 || a == -1)a = -1;
            else {
                a = -2;
                break;
            }
        }
        if (matrix[i][column1] != '1' && matrix[i][column2] == '1') {
            if (a == 0 || a == 1)a = 1;
            else {
                a = -2;
                break;
            }
        }
    }

    return a;
};

int Table::compareRows(int row1, int row2) {
    int a = 0;
    for (int i = 0; i < matrix[0].size(); i++) {
        if (matrix[row1][i] == '1' && matrix[row2][i] != '1') {
            if (a == 0 || a == 1)a = 1;
            else {
                a = -2;
                break;
            }
        }
        if (matrix[row1][i] != '1' && matrix[row2][i] == '1') {
            if (a == 0 || a == -1)a = -1;
            else {
                a = -2;
                break;
            }
        }
    }

    return a;
};

void Table::createUpandDownArrows() {
    //up arrows
    //   int d=0;
    for (int i = 0; i < matrix[0].size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if (matrix[j][i] != '1') {
                for (int k = 0; k < matrix.size(); k++) {
                    if (matrix[k][i] != '1') {
                        //                     d++;
                        if (rowComparisonTable[j][k] == -1) {
                            break;

                        }
                    }

                    if (k == matrix.size() - 1)matrix[j][i] = 'u';
                }
            }
        }

    }

    //down arrows
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != '1') {
                for (int k = 0; k < matrix[0].size(); k++) {
                    if (matrix[i][k] != '1') {
                        //                       d++;
                        if (columnComparisonTable[j][k] == -1) {
                            break;

                        }

                    }

                    if (k == matrix[0].size() - 1) {
                        if (matrix[i][j] == 'u') matrix[i][j] = 'b';
                        else matrix[i][j] = 'd';
                    }
                }
            }
        }

    }

    //   std::cout<<d;

};

void Table::createColumnComparisonTable() {
    int numColumns = matrix[0].size();
    std::vector<int> row(numColumns);
    columnComparisonTable = std::vector<std::vector<int> >(numColumns, row);
    for (int i = 0; i < numColumns; i++) {
        for (int j = 0; j < numColumns; j++) {
            columnComparisonTable[i][j] = compareColumns(i, j);
        }
    }
}

void Table::createRowComparisonTable() {
    int numRows = matrix.size();
    std::vector<int> row(numRows);
    rowComparisonTable = std::vector<std::vector<int> >(numRows, row);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            rowComparisonTable[i][j] = compareRows(i, j);
        }
    }
}

std::vector<int> Table::getxD(int column) {
    std::vector<int> xD;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][column] == 'u' || matrix[i][column] == 'b') {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j != column && (matrix[i][j] == 'd' || matrix[i][j] == 'b')) {
                    if (xD.size() == 0) {
                        xD.push_back(j);
                    } else {
                        for (unsigned int k = 0; k < xD.size(); k++)// making sure not to add duplicates
                        {
                            if (xD[k] == j) {
                                break;
                            }
                            if (k == (xD.size() - 1)) {
                                xD.push_back(j);
                                break;
                            }

                        }
                    }
                }
            }
        }
    }
    return xD;

} //returns xD for a particular column

std::vector<int> Table::getMx(int column) {
    std::vector<int> Mx;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][column] == 'u' || matrix[i][column] == 'b')Mx.push_back(i);
        /* not needed  if (matrix[i][column]!=1) {
              for (unsigned int j=0; j<Mx.size(); j++) {
                  if (compareRows(i,Mx[j])==1) {
                      Mx.erase(Mx.begin()+j);
                      Mx.push_back(i);
                      break;
                  }
                  if (compareRows(i,Mx[j])==-1) {
                      break;
                  }
                  if (j==Mx.size()-1) {
                      Mx.push_back(i);
                  }
              }
          }*/
    }
    return Mx;

}//returns Mx for a particular column

/*ended up using different architecture
 std::vector<int> Table::getFamilies (std::vector<int> xD,std::vector<int> Mx){
    std::vector<std::vector<int> > families(Mx.size());
    for (int i=0; i<Mx.size(); i++) {
        for (int j=0; j<xD.size(); j++) {
            
        }
    }

}*/
//prints families to the screen. For debugging only

void printFamilies(std::vector<std::vector<int> > families) {
    int numRows = families.size();
    for (int i = 0; i < numRows; i++) {
        int numColumns = families[i].size();
        for (int j = 0; j < numColumns; j++) {
            printf("%3d", families[i][j]);
        }
        std::cout << "\n";
    }
}

std::vector< std::vector<int> > Table::getComplementedFamilies(int column) {
    std::vector<int> Mx = getMx(column);
    std::vector<int> xD = getxD(column);

    std::vector<std::vector<int> > families;
    std::vector<int> temporary;
    for (int i = 0; i < Mx.size(); i++) {
        temporary = xD;
        for (int j = 0; j < temporary.size(); j++) {
            if (matrix[Mx[i]][temporary[j]] == '1') {
                temporary.erase(temporary.begin() + j);
                j--;
            }
        }
        if (temporary.size() > 0)//only adding nonempty families
        {
            families.push_back(temporary);

        }
        for (unsigned int k = 0; k < temporary.size(); k++) {
            std::cout << column << " " << i << " " << Mx[i] << " " << temporary[k] << "\n";

        }
    }
    /* incorrect assumption  for (int i=0; i<matrix.size(); i++) {
          if (matrix[i][column]=='u'||matrix[i][column]=='b')
          {
              bool k=false;
              for (int j=0; j<matrix[0].size(); j++) {
                  if((matrix[i][j]=='d'||matrix[i][j]=='b')&&j!=column)
                  {
                      if (k==false) {
                          k=true;
                       
                          families.push_back(std::vector<int>(1,j));
                      }
                      else families[families.size()-1].push_back(j);
                      std::cout<<column<<" "<<families.size()-1<<" "<<i<<" "<<j<<"\n";
                  }
              }
          }
       }*/
    //printFamilies(families);
    return families;
}

//Writes the complemented families for a particular column to a table to a file, to be read by the HDA program)

void Table::writeComplementedFamilies(std::vector< std::vector<int> > families) {
    std::ofstream myfile;
    myfile.open("families.dat");
    int numFamilies = families.size();
    for (int i = 0; i < numFamilies; i++) {
        std::vector<int> family = families[i];
        int familySize = family.size();
        for (int j = 0; j < familySize; j++) {
            myfile << family[j] << " ";
        }
        if (i != numFamilies - 1) { //makes sure we don't add an extra newline
            myfile << "\n";
        }
    }
    myfile.close();
}

//reads the dual from the output file, turns it into a set of implications for that column

std::vector<Implication> Table::readDualToImplication(int column) {
    std::ifstream in_stream;
    std::vector<Implication> implications = std::vector<Implication>();
    in_stream.open("dual.dat");
    for (std::string line; std::getline(in_stream, line);) {
        std::vector<int> hittingSet = std::vector<int>();
        std::stringstream lineStream(line);
        int num;
        while (lineStream >> num) {
            hittingSet.push_back(num);
        }
        std::vector<int> rhs = std::vector<int>();
        rhs.push_back(column);
        Implication implication = Implication(hittingSet, rhs);
        implications.push_back(implication);
    }
    in_stream.close();

    return implications;
}

std::vector<Implication> Table::getNonBinaryBasis(int column) {
    std::vector<Implication> implications = std::vector<Implication>();
    // std::vector<int> xD=getxD(column);
    // getMx(column);
    std::vector< std::vector<int> > families = getComplementedFamilies(column);
    // std::vector<int> families=getFamilies(xD,getMx(column));
    // now we need to run hypergraph dualization
    //Note: the following code is temporary, while we don't have access to call the function directly
    writeComplementedFamilies(families);
    system(".\\shd 09 families.dat dual.dat");
    implications = readDualToImplication(column);
    //end of temporary
    return implications;
}

std::vector<Implication> Table::getFullNonBinaryBasis() {
    std::vector<Implication> allnonbinaryImplications;
    for (int i = 0; i < matrix[0].size(); i++) {
        std::vector<Implication> nonbinarybasisi = getNonBinaryBasis(i);
        allnonbinaryImplications.insert(allnonbinaryImplications.end(), nonbinarybasisi.begin(), nonbinarybasisi.end());
    }
    return allnonbinaryImplications;
}

//if column b->a, that means that b has fewer ones than a, or a < b.
std::vector<Implication> Table::getBinaryBasis(int column) {
    std::vector<Implication> implications = std::vector<Implication>();
    int numColumns = columnComparisonTable.size();
    for (int i = 0; i < numColumns; i++) {
        if (columnComparisonTable[column][i] == -1) {
            std::vector<int> rhs = std::vector<int>();
            rhs.push_back(column);
            std::vector<int> lhs = std::vector<int>();
            lhs.push_back(i);
            Implication implication = Implication(lhs, rhs);
            implications.push_back(implication);
        }
    }
    return implications;
}

std::vector<Implication> Table::getFullBinaryBasis() {
    std::vector<Implication> allImplications = std::vector<Implication>();
    int numColumns = columnComparisonTable[0].size();
    for (int i = 0; i < numColumns; i++) {
        std::vector<Implication> implications = getBinaryBasis(i);
        allImplications.insert(allImplications.end(), implications.begin(), implications.end());
    }
    return allImplications;
}

void printImplications(std::vector<Implication> implications) {
    for (int i = 0; i < implications.size(); i++) {
        std::cout << implications[i].toString() << "\n";
    }
}

