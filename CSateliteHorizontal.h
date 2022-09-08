#pragma once
#include <iostream>
#include<time.h>
using namespace System;
using namespace std;
class CSateliteHor
{
public:
	CSateliteHor();
	~CSateliteHor();

	void moverHorizontal();
	void borrar();
	void dibujar();

private:
	int x, y, dx, dy;

};

CSateliteHor::CSateliteHor()
{
	
	x = rand() % 80;
	y = rand() % 40;
	dx = 1;
	dy = 0;
}

CSateliteHor::~CSateliteHor() {}

void CSateliteHor::moverHorizontal() {
	if (x + dx < 0 || x + dx>79) { dx *= -1; }
	x += dx;
}
void CSateliteHor::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void CSateliteHor::dibujar() {
	Console::SetCursorPosition(x, y); cout << "@";
}