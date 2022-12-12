#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include "Model.h"
#include "Peg.h"
#include <conio.h>


#define WIN_W  700
#define WIN_H  700
#define PEG_H  50
#define PEG_W  50
#define RIM  5

IMAGE imgBG;
IMAGE imgPEG[3];

using namespace std;


int main() {
    int style;
    int x_in, y_in;
    char dir_in;
    bool valid,inputvalid,destvalid;
    int  x_eaten, y_eaten;

    cout << "Welcome to PegSolitaire Game !" << endl;
    do {
        cout << "Enter the style of board French(1), Germany(2), English(3) :" << endl;
        cin >> style;
        // error checking for style 
        if (style != 1 && style != 2 && style != 3 ) {
            cout << "Invalid selection of board" << endl;
        }
    } while (style != 1 && style != 2 && style != 3 );

    Model Game(style);
    loadimage(&imgPEG[0], L"res/peg2.png");
    loadimage(&imgPEG[1], L"res/empty.png");
    loadimage(&imgPEG[2], L"res/peg_selected.png");
    initgraph(WIN_W, WIN_H,EW_SHOWCONSOLE);
    
   

    // Start playing 
    do {
        
        Game.refreshPage(WIN_W, WIN_H, PEG_W, PEG_H, imgBG, imgPEG);
        
   
        do {
            inputvalid = Game.Loadinput();
        } while (inputvalid == false);

        Game.refreshPage(WIN_W, WIN_H, PEG_W, PEG_H, imgBG, imgPEG);

        do {
            destvalid = Game.Loaddest();
        } while (destvalid == false);



        Game.loadeaten();
        


        // check if move is valid
        
        if (Game.IsMoveValid()) {
            Game.Update();
            valid = Game.IsGameOver();
            if (valid == true)
            {
                Game.refreshPage(WIN_W, WIN_H, PEG_W, PEG_H, imgBG, imgPEG);
                cout << "Game Over! Closing in few seconds..." << endl;
                Sleep(10000);
                exit(0);
            }
        }
        else {
            cout << "Invalid move." << endl;
            for (int y_pos = Game.board_size; y_pos >= 0; y_pos--)
            {
                for (int x_pos = 0; x_pos < Game.board_size; x_pos++)
                {
                    for (int i = 0; i < Game.peg_total; i++)
                    {
                        if (Game.peg_ptrs[i]->x == Game.x_in && Game.peg_ptrs[i]->y == Game.y_in)
                        {
                            if (Game.peg_ptrs[i]->state == SELECTED)
                            {
                                Game.peg_ptrs[i]->state = OCCUPIED;
                            }
                        }
                    }
                }
            }
            valid = false;
        }
    } while ((valid == false));
}


