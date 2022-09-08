#pragma once
#include <iostream>
using namespace System; 
using namespace std; 
class CSatelite
{
public:
	CSatelite(); 
	~CSatelite();

	void moverTodaPantalla();
	void borrar(); 
	void dibujar(); 

private:
	int x, y, dx, dy; 
};

CSatelite::CSatelite()
{
	
	x = rand() % 80; 
	y = rand() % 40; 
	dx = dy = 1; 
	
}

CSatelite::~CSatelite(){}

void CSatelite::moverTodaPantalla() {
	if (x + dx < 0 || x + dx>79) { dx *= -1; }
	if (y + dy < 0 || y + dy>39) { dy *= -1; }
	x += dx;     
	y += dy;
}
void CSatelite::borrar() {
	Console::SetCursorPosition(x, y); cout << " ";
}
void CSatelite::dibujar() {
	Console::SetCursorPosition(x, y); cout << "*";
}