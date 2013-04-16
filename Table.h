//
//  Table.h
//  
//
//  Created by Joshua A Blumenkopf on 4/16/13.
//
//

#ifndef ____Table__
#define ____Table__
class Table
{
    vector<vector<char> > matrix;
    vector<Implication> implications;
    map <integer, integer> reducedToOriginal;
    map<integer, vector<integer> equivalentColumns;
public:
    Table(vector<vector<char> >){}
void advance();    
    get_matrix(){return matrix;}
};
#include <iostream>

#endif /* defined(____Table__) */
