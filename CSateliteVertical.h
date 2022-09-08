#pragma once
#include <iostream>
using namespace System;
using namespace std;
class CSateliteVer
{
public:
	CSateliteVer();
	~CSateliteVer();
	
	void moverVertical();
	void borrar();
	void dibujar();

private:
	int x, y, dx, dy;

};

CSateliteVer::CSateliteVer()
{
	x = rand() % 80;
	y = rand() % 40;
	dx = 0; 
	dy = 1; 
}

CSateliteVer::~CSateliteVer() {}


void CSateliteVer::moverVertical() {  
	if (y + dy < 0 || y + dy>39){ dy *= -1; }
	y += dy;
}
void CSateliteVer::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void CSateliteVer::dibujar() {
	Console::SetCursorPosition(x, y); cout <<"+";
}