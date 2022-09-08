#pragma once
#include "CSateliteHorizontal.h"
class CArrObjetos3
{
public:
	CArrObjetos3();
	~CArrObjetos3();

	void push_back(CSateliteHor* dato);
	void eliminar(int posicion);
	int size();
	CSateliteHor* at(int posicion);

private:
	int tamanioArr;
	CSateliteHor** arrObjetos;
};

CArrObjetos3::CArrObjetos3()
{
	tamanioArr = 0;
	arrObjetos = new CSateliteHor * [tamanioArr];
}

CArrObjetos3::~CArrObjetos3()
{
}
void CArrObjetos3::push_back(CSateliteHor* dato) {
	CSateliteHor** aux = new CSateliteHor * [tamanioArr + 1];
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
void CArrObjetos3::eliminar(int posicion) {
	CSateliteHor** aux = new CSateliteHor * [tamanioArr - 1];
	for (int i = 0; i < tamanioArr - 1; i++)
	{
		if (i < posicion) {
			aux[i] = arrObjetos[i];
		}
		else { aux[i] = arrObjetos[i + 1]; }
	}
	tamanioArr--;
	delete[]arrObjetos;
	arrObjetos = aux;
	aux = nullptr;
	delete aux;
}
int CArrObjetos3::size() {
	return tamanioArr;
}
CSateliteHor* CArrObjetos3::at(int posicion) {
	return arrObjetos[posicion];
}