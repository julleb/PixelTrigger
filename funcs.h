#ifndef FUNCS_H
#define FUNCS_H



#include <iostream>
#include <Windows.h>
#include <stdio.h>

#include <iostream>

using namespace std;

#define RED 0
#define GREEN 1
#define BLUE 2

void get_pixels(int *colors);
bool pixels_are_equal(int *oldcolor, int *newcolor);
void run();
#endif
