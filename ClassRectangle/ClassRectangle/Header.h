#pragma once

#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 

using namespace std;

 class Rect
 { 
    private:
    float x,y,a,b;
    public:
	Rect Rects(float x = 0, float y = 0, float a = 0, float b = 0);
	Rect Center();
	Rect Mult(int);
	float Square();
	float Perimetr();
	float Radious();
	void Input();
	void Output();
	bool Kvadrat();
	bool Ravenstvo(Rect);
	bool PodobieRects(Rect);
	bool PeresechenieRects(Rect);
};