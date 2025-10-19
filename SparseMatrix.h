#pragma once
#include "Nodo.h"
class SparseMatrix {
    private:
    Nodo* start;
    public:
    SparseMatrix();
// Insertar un dato en las coordenadas correspondientes (X, Y).
void add(int value, int xPos, int yPos);
//Obtener un dato según las coordenadas dadas (X, Y). no dato= 0.
int get(int xPos, int yPos);
//Eliminar un dato según las coordenadas dadas (X, Y)
void remove(int xPos, int yPos);
//Imprimir los elementos existentes en la matriz que sean distintos de 0 de forma tabular.
void printStoredValues();
//obtener la densidad
int density();
// multiplicar la matriz po parametro
SparseMatrix* multiply(SparseMatrix* second);
~SparseMatrix();
};