#include "Peg.h"

Peg::Peg(int x_loc, int y_loc,int style){
    x = x_loc;
    y = y_loc; 
    int x_empty,y_empty; 
    switch(style){
        case 1:{
            x_empty = 3;
            y_empty = 4;
            break;  
        }
        case 2:{
            x_empty = 4;
            y_empty = 4;
            break;  
        }
        case 3:{
            x_empty = 3;
            y_empty = 3;
            break;  
        }
        case 4:{
            x_empty = 4;
            y_empty = 4;
            break;  
        }
    }
    if (x == x_empty && y == y_empty){
        state = EMPTY;
    }
    else {
        state = OCCUPIED; 
    }
    
}