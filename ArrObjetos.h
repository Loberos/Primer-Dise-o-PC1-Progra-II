#pragma once
#include "CSatelite.h"
class CArrObjetos
{
public:
	CArrObjetos();
	~CArrObjetos();

	void push_back(CSatelite* dato);
	void eliminar(int posicion); 
	int size(); 
	CSatelite* at(int posicion);
	
private: 
	int tamanioArr; 
	CSatelite** arrObjetos;
};

CArrObjetos::CArrObjetos()
{
	tamanioArr = 0; 
	arrObjetos = new CSatelite * [tamanioArr];
}

CArrObjetos::~CArrObjetos()
{
}
void CArrObjetos::push_back(CSatelite* dato) {
	CSatelite** aux = new CSatelite*[tamanioArr + 1];
	for (int i = 0; i < tamanioArr; i++)
	{
		aux[i] = arrObjetos[i]; 
	}
	aux[tamanioArr] = dato;
	tamanioArr++; 
	delete[]arrObjetos; 
	arrObjetos = aux; 
	aux = nullptr; 
	delete aux; 
}
void CArrObjetos::eliminar(int posicion) {
	CSatelite** aux = new CSatelite*[tamanioArr - 1];
	for (int i = 0; i < tamanioArr-1; i++)
	{
		if (i < posicion) {
			aux[i] = arrObjetos[i]; 
		}
		else { aux[i] = arrObjetos[i + 1];  }
	}
	tamanioArr--;
	delete[]arrObjetos;
	arrObjetos = aux;
	aux = nullptr;
	delete aux;
}
int CArrObjetos::size() {
	return tamanioArr; 
}
CSatelite* CArrObjetos::at(int posicion) {
	return arrObjetos[posicion];
}
