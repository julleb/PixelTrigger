#include "funcs.h"


POINT pointer;
HDC hdc;

int colors[3];
int new_colors[3];


//init function, for the hdc.
void init() {
	hdc = GetDC(NULL);
    if(hdc == NULL){
		exit(1);
	}

	get_pixels(colors);
}

//get the pixels where the mouse is pointing
void get_pixels(int *colors) {

	COLORREF pixel_colors;
	if(!GetCursorPos(&pointer)) return;
		
	pixel_colors = GetPixel(hdc, pointer.x, pointer.y);
    
	if(pixel_colors != CLR_INVALID) {
		colors[RED] = GetRValue(pixel_colors);
		colors[GREEN] = GetGValue(pixel_colors);
		colors[BLUE] = GetBValue(pixel_colors);
	}
}

//compare if 2 pixel arrays are equal or not
bool pixels_are_equal(int *oldcolor, int *newcolor) {
	for(int i = 0; i < 3; i++) {
		if(oldcolor[i] != newcolor[i]) return false;

	}
	return true;
}


void run() {

	init();

	while(1) {
		Sleep(2);

		get_pixels(colors);
		
		while(GetAsyncKeyState(0x05)&-0x8000) {
			get_pixels(new_colors);
			
			if(!pixels_are_equal(colors, new_colors)) {
				std::cout<<"skjut!"<<std::endl;
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			}
		}
		
	}

}
