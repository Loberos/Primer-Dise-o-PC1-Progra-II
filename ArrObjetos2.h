#pragma once
#include "CSateliteVertical.h"
class CArrObjetos2
{
public:
	CArrObjetos2();
	~CArrObjetos2();

	void push_back(CSateliteVer* dato);
	void eliminar(int posicion);
	int size();
	CSateliteVer* at(int posicion);

private:
	int tamanioArr;
	CSateliteVer** arrObjetos;
};

CArrObjetos2::CArrObjetos2()
{
	tamanioArr = 0;
	arrObjetos = new CSateliteVer * [tamanioArr];
}

CArrObjetos2::~CArrObjetos2()
{
}
void CArrObjetos2::push_back(CSateliteVer* dato) {
	CSateliteVer** aux = new CSateliteVer * [tamanioArr + 1];
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
void CArrObjetos2::eliminar(int posicion) {
	CSateliteVer** aux = new CSateliteVer * [tamanioArr - 1];
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
int CArrObjetos2::size() {
	return tamanioArr;
}
CSateliteVer* CArrObjetos2::at(int posicion) {
	return arrObjetos[posicion];
}