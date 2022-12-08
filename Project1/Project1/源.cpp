#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <iostream>
#include "Model.h"
#include "Peg.h"

#include <conio.h>
#pragma comment( lib, "MSIMG32.LIB")

#define WIN_W  700
#define WIN_H  700
#define PEG_H  50
#define PEG_W  50
#define RIM  5

IMAGE imgBG;
IMAGE imgPEG[3];

using namespace std;

void transparentimage3(IMAGE* dstimg, int x, int y, IMAGE* srcimg) //make png transparent
{
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}



int main() {
    int style;
    int x_in, y_in;
    char dir_in;
    bool valid,inputvalid,destvalid;
    int  x_eaten, y_eaten;

    cout << "Welcome to PegSolitaire Game !" << endl;
    do {
        cout << "Enter the style of board French(1), Germany(2), English(3),Diamond(4) :" << endl;
        cin >> style;
        // error checking for style 
        if (style != 1 && style != 2 && style != 3 && style != 4) {
            cout << "Invalid selection of board" << endl;
        }
    } while (style != 1 && style != 2 && style != 3 && style != 4);

    Model Game(style);
    loadimage(&imgPEG[0], L"res/peg2.png");
    loadimage(&imgPEG[1], L"res/empty.png");
    initgraph(WIN_W, WIN_H,EW_SHOWCONSOLE);
    
   

    // Start playing 
    do {
        
        Game.refreshPage(WIN_W, WIN_H, PEG_W, PEG_H, imgBG, imgPEG);
        
   
        do {
            inputvalid = Game.Loadinput();
        } while (inputvalid == false);
        do {
            destvalid = Game.Loaddest();
        } while (destvalid == false);



        Game.loadeaten();
        


        // check if move is valid
        
        if (Game.IsMoveValid()) {
            Game.Update();
            valid = Game.IsGameOver();
        }
        else {
            cout << "Invalid move." << endl;
            valid = false;
        }
    } while ((valid == false));
}


