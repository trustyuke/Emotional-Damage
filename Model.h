#ifndef MODEL_H
#define MODEL_H

#include "Peg.h"
#include <iostream>

using namespace std; 

class Model{

public:
    int board_size; 
    int corner_size; 
    int peg_total; 
    int x_in, y_in; 
    int x_dest,y_dest; 
    int x_eaten,y_eaten; 
    Peg *peg_ptrs[70];
    // parameter constructor 
    Model(int style);

    // find three coordinate of peg 
    void Find3coord(int x,int y,char dir_in);

    // check if the move is valid 
    bool IsMoveValid();

    // update the move and check to see if game could be continued 
    void Update();
};

#endif 