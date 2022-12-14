#include "Model.h"
#include <Windows.h>
#include <cmath>

Model::Model(int style){
    // initialize
    STYLE=style;
    switch(style){
        case 1:{
            board_size = 7;
            corner_size = 2;
            break;
        }
        case 2:{
            board_size = 9;
            corner_size = 3; 
            break;
        }
        case 3:{
            board_size = 7;
            corner_size = 2;
            break;
        }

    }

    if (style == 2 || style == 3){
        peg_total = board_size*board_size-4*corner_size*corner_size; 
        int peg_count = 0; 
        // initialize peg in x = 2-4,y = 0-6
        for(int x = corner_size; x < board_size-corner_size; x++){
            for (int y = 0; y<board_size;y++){
                peg_ptrs[peg_count] = new Peg(x,y,style);
                peg_count++;
            }
        }

        // initialize peg in x = 0-1,y = 2-4
        for(int x = 0; x < corner_size; x++){
            for (int y = corner_size; y < board_size-corner_size; y++){
                peg_ptrs[peg_count] = new Peg(x,y,style);
                peg_count++;
            }
        }

        // initialize peg in x = 5-6,y = 2-4
        for(int x = board_size-corner_size; x < board_size; x++){
            for (int y = corner_size; y < board_size-corner_size; y++){
                peg_ptrs[peg_count] = new Peg(x,y,style);
                peg_count++;
            }
            
        }
        // cout << peg_count << endl; 
    }

    if (style == 1){
        peg_total = board_size*board_size-4*3;
        int peg_count = 0; 
        // initialize center 5*5
        for(int x = 1; x < board_size-1; x++){
            for(int y = 1; y < board_size-1;y++){
                peg_ptrs[peg_count] = new Peg(x,y,style);
                peg_count++;
            }  
        }
        for(int y = corner_size; y < board_size-corner_size; y++){
            peg_ptrs[peg_count] = new Peg(0,y,style);
            peg_count++;
            peg_ptrs[peg_count] = new Peg(board_size-1,y,style);
            peg_count++;

        }
        for(int x = corner_size; x < board_size-corner_size; x++){
            peg_ptrs[peg_count] = new Peg(x,0,style);
            peg_count++;
            peg_ptrs[peg_count] = new Peg(x,board_size-1,style);
            peg_count++;
        }
        // cout << peg_count << endl;
    }

    
    // cout << peg_total << endl; 
}



// find three coordinate of peg 
void Model::Find3coord(int x,int y,char dir_in){
    x_in = x-1; 
    y_in = y-1;
    switch(dir_in){
        case 'u':{
            x_dest = x_in;
            y_dest = y_in + 2;
            x_eaten = x_in;
            y_eaten = y_in + 1;
            break;
        }
        case 'd':{
            x_dest = x_in;
            y_dest = y_in - 2;
            x_eaten = x_in;
            y_eaten = y_in - 1;
            break;
        }
        case 'l':{
            x_dest = x_in - 2;
            y_dest = y_in;
            x_eaten = x_in - 1;
            y_eaten = y_in;
            break;
        }
        case 'r':{
            x_dest = x_in + 2;
            y_dest = y_in;
            x_eaten = x_in + 1;
            y_eaten = y_in;
            break;
        }
    }
}

bool Model::IsMoveValid(){
    int valid_count = 0; 
    // cout << x_in << " " << y_in << endl; 
    // cout << x_eaten << " " << y_eaten << endl;
    // cout << x_dest << " " << y_dest << endl;
    //cout << peg_total << endl; 
    for (int i = 0;i < peg_total;i++){
        if (peg_ptrs[i] -> x == x_in && peg_ptrs[i] -> y == y_in){
            if ((peg_ptrs[i] -> state == OCCUPIED)|| (peg_ptrs[i]->state == SELECTED)){
                valid_count++;
                // cout << "case 1" << endl; 
            }   
        }
        if (peg_ptrs[i] -> x == x_dest && peg_ptrs[i] -> y == y_dest){
            if (peg_ptrs[i] -> state == EMPTY){
                valid_count++;
                // cout << "case 2" << endl; 
            }   
        }
        if (peg_ptrs[i] -> x == x_eaten && peg_ptrs[i] -> y == y_eaten){
            if (peg_ptrs[i] -> state == OCCUPIED){
                valid_count++;
                // cout << "case 3" << endl; 
            }   
        }
    }
    // cout << "valid count: " << valid_count << endl;
    if (valid_count == 3){
        return true;
    }
    else {
        return false; 
    }

}

// update the move 
void Model::Update(){
    for (int i = 0;i < peg_total;i++){
        if (peg_ptrs[i] -> x == x_in && peg_ptrs[i] -> y == y_in){
            peg_ptrs[i] -> state = EMPTY;
        }
        if (peg_ptrs[i] -> x == x_dest && peg_ptrs[i] -> y == y_dest){
            peg_ptrs[i] -> state = OCCUPIED;
        }
        if (peg_ptrs[i] -> x == x_eaten && peg_ptrs[i] -> y == y_eaten){
            peg_ptrs[i] -> state = EMPTY;
        }
    }
}

// display the board in UNIX
/*void Model::displayBoard()
{
	for (int y_pos = board_size; y_pos >=0 ; y_pos--)
	{
		for (int x_pos = 0; x_pos < board_size; x_pos++)
		{
            bool exist=false;

            for(int i=0; i<peg_total;i++)
            {
                if(peg_ptrs[i]->x==x_pos&&peg_ptrs[i]->y==y_pos)
                {
                    if(peg_ptrs[i]->state==EMPTY)
                    {
                        cout << "X";
                    }
                    else if(peg_ptrs[i]->state==OCCUPIED)
                    {
                        cout << "O";
                    }
                    cout << " ";
                    exist=true;
                }

            }

            if(exist==false)
            {
                cout << "  ";
            }
		}
		cout << endl;
	}
}
*/

void Model::refreshPage(int WIN_W,int WIN_H,int PEGW,int PEGH,IMAGE &imgBG,IMAGE* imgPEG)
{

    switch (STYLE)
    {
    case(1):
    {
        loadimage(&imgBG, L"res/board1.png");
        putimage(0, 0, &imgBG);
        BeginBatchDraw();
        int y_init = 130;
        for (int y_pos = board_size; y_pos >= 0; y_pos--)
        {
            int x_init = 180;
            for (int x_pos = 0; x_pos < board_size; x_pos++)
            {
                for (int i = 0; i < peg_total; i++)
                {
                    if (peg_ptrs[i]->x == x_pos && peg_ptrs[i]->y == y_pos)
                    {
                        if (peg_ptrs[i]->state == EMPTY)
                        {
                            putimage(x_init, y_init, &imgPEG[1]);
                        }
                        else if (peg_ptrs[i]->state == OCCUPIED)
                        {
                            putimage(x_init, y_init, &imgPEG[0]);
                        }
                        else if (peg_ptrs[i]->state == SELECTED)
                        {
                            putimage(x_init, y_init, &imgPEG[2]);
                        }
                    }
                }
                x_init += PEGW;

            }
            y_init += PEGH;
        }
        EndBatchDraw();
        break;
    }
    case(2):
    {
        loadimage(&imgBG, L"res/board2.png");
        putimage(0, 0, &imgBG);
        BeginBatchDraw();
        int y_init = 80;
        for (int y_pos = board_size; y_pos >= 0; y_pos--)
        {
            int x_init = 130;
            for (int x_pos = 0; x_pos < board_size; x_pos++)
            {
                for (int i = 0; i < peg_total; i++)
                {
                    if (peg_ptrs[i]->x == x_pos && peg_ptrs[i]->y == y_pos)
                    {
                        if (peg_ptrs[i]->state == EMPTY)
                        {
                            putimage(x_init, y_init, &imgPEG[1]);
                        }
                        else if (peg_ptrs[i]->state == OCCUPIED)
                        {
                            putimage(x_init, y_init, &imgPEG[0]);
                        }
                        else if (peg_ptrs[i]->state == SELECTED)
                        {
                            putimage(x_init, y_init, &imgPEG[2]);
                        }
                    }
                }
                x_init += PEGW;

            }
            y_init += PEGH;
        }
        EndBatchDraw();
        break;
    }

    case(3):
    {
        loadimage(&imgBG, L"res/board3.png");
        BeginBatchDraw();
        putimage(0, 0, &imgBG);
        int y_init = 130;
        for (int y_pos = board_size; y_pos >= 0; y_pos--)
        {
            int x_init = 180;
            for (int x_pos = 0; x_pos < board_size; x_pos++)
            {
                for (int i = 0; i < peg_total; i++)
                {
                    if (peg_ptrs[i]->x == x_pos && peg_ptrs[i]->y == y_pos)
                    {
                        if (peg_ptrs[i]->state == EMPTY)
                        {
                            putimage(x_init, y_init, &imgPEG[1]);
                        }
                        else if (peg_ptrs[i]->state == OCCUPIED)
                        {
                            putimage(x_init, y_init, &imgPEG[0]);
                        }
                        else if(peg_ptrs[i]->state == SELECTED)
                        {
                            putimage(x_init, y_init, &imgPEG[2]);
                        }
                    }
                }
                x_init += PEGW;

            }
            y_init += PEGH;
        }

        EndBatchDraw();
        break;
    }

    }
}
#include <graphics.h>

////bool Model::Load3coord() {
////    ExMessage message;
////    
////    int count = 0;
////    if (count == 0) {
////        MOUSEMSG msg = GetMouseMsg();
////        if ((msg.uMsg == WM_LBUTTONDOWN) && (peekmessage(&message))){
////            x_in = (msg.x-175)/50;
////            y_in = (msg.y - 175) / 50;
////            cout << x_in << " " << y_in << endl;
////            count += 1;
////        }
////    }
////    else if (count == 1) {
////        MOUSEMSG msg = GetMouseMsg();
////        if ((msg.uMsg == WM_LBUTTONDOWN) && (peekmessage(&message))) {
////            x_dest = (msg.x - 175) / 50;
////            y_dest = (msg.y - 175) / 50;
////            cout << x_in << " " << y_in << endl;
////            count += 1;
////        }
////    }
////    x_eaten = x_in + (x_dest - x_in) / 2;
////    y_eaten = y_in + (y_dest - y_in) / 2;
////    if (count == 2) {
//        return true;
//    }
//    else {
//        return false;
//    }
//}

//bool Model::Load3coord() {
//    ExMessage message;
//
//    int count = 0;
//    if (count == 0) {
//        MOUSEMSG msg = GetMouseMsg();
//        while ((msg.uMsg == WM_LBUTTONDOWN) && (peekmessage(&message))) {
//            x_in = (msg.x - 175) / 50;
//            y_in = (msg.y - 175) / 50;
//            cout << x_in << " " << y_in << endl;
//            count += 1;
//        }
//    }
//    else if (count == 1) {
//            MOUSEMSG msg2 = GetMouseMsg();
//            if ((msg2.uMsg == WM_LBUTTONDOWN) && (peekmessage(&message))) {
//                x_dest = (msg2.x - 175) / 50;
//                y_dest = (msg2.y - 175) / 50;
//                cout << x_in << " " << y_in << endl;
//                count += 1;
//            }
//    }
//        x_eaten = x_in + (x_dest - x_in) / 2;
//        y_eaten = y_in + (y_dest - y_in) / 2;
//        if (count == 2) {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }

bool  Model::Loadinput() {
    //ExMessage message;
    MOUSEMSG msg = GetMouseMsg();
    if ((msg.uMsg == WM_LBUTTONDOWN)) {

        int x, y;
        if(STYLE==2)
        {
            x = (msg.x - 125) / 50;
            y = 8 - (msg.y - 125) / 50;

        }
        else
        {
            x = (msg.x - 175) / 50;
            y = 6 - (msg.y - 175) / 50;
        }

        bool determine = false;
        for (int i = 0; i < peg_total; i++)
        {
            
            if (peg_ptrs[i]->x == x && peg_ptrs[i]->y == y)
            {
                if (peg_ptrs[i]->state!=EMPTY)
                {
                    x_in = x;
                    y_in = y;
                    determine = true;
                    cout << "first click " << x_in << " " << y_in << endl;
                }
            }
        }
        if (determine == false)
        {
            cout << "Invalid first click, try again" << endl;
            return false;
        }

       
        for (int y_pos = board_size; y_pos >= 0; y_pos--)
        {
            for (int x_pos = 0; x_pos < board_size; x_pos++)
            {
                for (int i = 0; i < peg_total; i++)
                {
                    if (peg_ptrs[i]->x == x_in && peg_ptrs[i]->y == y_in)
                    {
                        if (peg_ptrs[i]->state == OCCUPIED)
                        {
                            peg_ptrs[i]->state = SELECTED;
                        }
                    }
                }
            }
        }

        return true;
    }
    else {
        return false;
    }
}

bool  Model::Loaddest() {
    //ExMessage message;
    MOUSEMSG msg = GetMouseMsg();
    if ((msg.uMsg == WM_LBUTTONDOWN)) {

        if (STYLE == 2)
        {
            x_dest = (msg.x - 125) / 50;
            y_dest = 8 - (msg.y - 125) / 50;
        }
        else
        {
            x_dest = (msg.x - 175) / 50;
            y_dest = 6 - (msg.y - 175) / 50;
        }

        cout << "second click " << x_dest << " " << y_dest << endl;
        if ((abs(x_dest - x_in) == 2 && abs(y_dest - y_in) == 0) || (abs(x_dest - x_in) == 0 && abs(y_dest - y_in) == 2)) {
            return true;
        }
        else {
            cout << "invlaid second click" << endl;

            return false;
        }
    }
    else {
        return false;
    }
}

void  Model::loadeaten() {
    x_eaten = x_in + (x_dest - x_in) / 2;
    y_eaten = y_in + (y_dest - y_in) / 2;
}

// check to see if game could be continued (if not, print # of peg left)
bool Model::IsGameOver(){
     // check to see if game could be continued
    int move_valid = 0; 
    int peg_remaining = 0; 
    char move[] = {'u','d','l','r'}; 
    for (int i =0; i < peg_total; i++){
        // check IsMoveValid on 4 directions for each peg
        for (int j = 0; j < 4; j ++ ){
            Find3coord(peg_ptrs[i] -> x,peg_ptrs[i] -> y,move[j]);
            if(IsMoveValid()){
                move_valid++; 
            }
        }

        // count # of peg remained 
        if (peg_ptrs[i] -> state == OCCUPIED){
            peg_remaining ++;
        }
    }
    if (move_valid == 0){
        cout << "There are " << peg_remaining << " pegs remained!" << endl; 
        return true; 
    }
    else {
        return false;       
    }

}
    
   
    


          

