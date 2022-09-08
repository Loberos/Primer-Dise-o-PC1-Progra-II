#pragma once
#include "pch.h"

#include "ArrObjetos.h"
#include "ArrObjetos2.h"
#include "ArrObjetos3.h"

#include "CSatelite.h"
#include "CSateliteVertical.h"
#include "CSateliteHorizontal.h"

#include <conio.h>
class CJuego
{
public:
	CJuego();
	~CJuego();
	void jugar(); 
	void Resporte(); 
	void borrarTodo();
	void moverTodo(); 
	void mostrarTodo(); 

private:
	CSatelite* objSatelite; 
	CSateliteVer* objSateliteVer;
	CSateliteHor* objSateliteHor;
	CArrObjetos* objArr; 
	CArrObjetos2* objArr2;
	CArrObjetos3* objArr3;
	char tecla; 
	bool juego;
};

CJuego::CJuego()
{
	
	objArr = new CArrObjetos(); 
	objArr2 = new CArrObjetos2();
	objArr3 = new CArrObjetos3();
	objSateliteVer = new CSateliteVer();
	objSateliteHor = new CSateliteHor();
	objSatelite = new CSatelite();

	juego = true;
}

CJuego::~CJuego()
{
	
}

void CJuego::borrarTodo(){
	for (int i = 0; i < objArr2->size(); i++)
	{
		objArr2->at(i)->borrar();

	}
	for (int i = 0; i < objArr3->size(); i++)
	{
		objArr3->at(i)->borrar();

	}
	for (int i = 0; i < objArr->size(); i++)
	{
		objArr->at(i)->borrar();

	}
}
void CJuego::moverTodo(){
	for (int i = 0; i < objArr2->size(); i++)
	{
		objArr2->at(i)->moverVertical();
	}
	for (int i = 0; i < objArr3->size(); i++)
	{
		objArr3->at(i)->moverHorizontal();

	}
	for (int i = 0; i < objArr->size(); i++)
	{
		objArr->at(i)->moverTodaPantalla();

	}
}
void CJuego::mostrarTodo(){
	for (int i = 0; i < objArr2->size(); i++)
	{
		objArr2->at(i)->dibujar();
	}
	for (int i = 0; i < objArr3->size(); i++)
	{
		objArr3->at(i)->dibujar();

	}
	for (int i = 0; i < objArr->size(); i++)
	{
		objArr->at(i)->dibujar();

	}
}
void CJuego::jugar() {
	
	while (juego) {
		if (_kbhit()) {
			tecla = getch();
			if (tecla == 'v')
			{
				objArr2->push_back(objSateliteVer);
			}
			if (tecla == 'h')
			{
				objArr3->push_back(objSateliteHor);
			}
			if (tecla == 't')
			{
				objArr->push_back(objSatelite);
			}
			if (tecla == char(27)) {
				juego = false;
				Resporte();
			}
		}
		borrarTodo(); 
		moverTodo(); 
		mostrarTodo(); 
		
		_sleep(100);
	}
}
void CJuego::Resporte() {
	Console::SetCursorPosition(0, 4); cout << "            Satelite " << endl;
	Console::SetCursorPosition(0, 5);cout << "Reporte:     " << endl; 
	Console::SetCursorPosition(0, 6);cout << "Horizontal:     " << objArr3->size()  << endl;
	Console::SetCursorPosition(0, 7); cout << "Vertical:       " << objArr2->size() << endl;
	Console::SetCursorPosition(0, 8);cout << "Toda Pantalla:  " << objArr->size() << endl;
}