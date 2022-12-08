#ifndef PEG_H
#define PEG_H

#include <string>

using namespace std; 

enum PegStates{
    EMPTY = 0,
    OCCUPIED =1
}; 

class Peg{

public:
    int x,y; 
    char state; 

    // parameter constructor
    Peg(int x_loc, int y_loc,int style);



}; 

#endif 