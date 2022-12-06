# include <stdio.h>
# include <graphics.h>
# include <conio.h>
# include <mmsystem.h>
# pragma comment(lib,"winmm.lib")

IMAGE Peg; 
IMAGE empty;

const float BLOCK_SIZE = 67.4; // peg size

void init() {
	initgraph(700, 700);
	loadimage(0, "res/board1.png");
	loadimage(&Peg,"res/empty_eaten.png",BLOCK_SIZE, BLOCK_SIZE,true);
	loadimage(&empty,"res/peg.png", BLOCK_SIZE, BLOCK_SIZE, true);
}


const
void manGo() {

}

void checkvalid() {

}

void updateboard() {

}

void checkendgame() {

}

int main(void) {
	init();
	
	while (1) {
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_LBUTTONDOWN) { // iF LEFT COLICK
			manGo();
			if (true) {
				
				updateboard();
				checkendgame();
			}
		}

	}
	return 0;
}

