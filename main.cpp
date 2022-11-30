#include <iostream>
#include "Peg.h"
#include "Model.h"

using namespace std; 

int main(){
    int style; 
    int x_in,y_in;
    char dir_in; 
    bool valid; 
    cout << "Welcome to PegSolitaire Game !" << endl;
    do{
        cout << "Enter the style of board French(1), Germany(2), English(3),Diamond(4) :" << endl;
        cin >> style;
        // error checking for style 
        if(style != 1 && style != 2 && style != 3 && style != 4){
            cout << "Invalid selection of board" << endl; 
        }
    }while(style != 1 && style != 2 && style != 3 && style != 4);

    Model Game(style);
    
    // Start playing 
    do{
        cout << "Please give the x and y coord of peg you want to move:" << endl;
        cin >> x_in >> y_in; 
        cout << "Please give the direction you want to move up(u),down(d),left(l),right(r): " <<endl;
        cin >> dir_in;

        // Update Coordinate of 3 pegs 
        Game.Find3coord(x_in,y_in,dir_in);

        // check if move is valid

        if(Game.IsMoveValid()){
            Game.Update(); 
        }
        else {
            cout << "Invalid move." << endl; 
            valid = false;
        }
    }while(valid != false);
}


      