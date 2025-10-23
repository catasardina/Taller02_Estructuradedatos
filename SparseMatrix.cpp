#include "SparseMatrix.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix() {  // Era "SparceMatrix" (typo)
    start = nullptr;
}

void SparseMatrix::add(int value, int xPos, int yPos) {  // Era "value." en vez de "value,"
    if(value == 0) return;
    
    Nodo* newNodo = new Nodo(value, xPos, yPos);  // Era "Node*", debe ser "Nodo*"
    
    if(!start) {
        start = newNodo;
        return;
    }
    
    Nodo* current = start;
    Nodo* prev = nullptr;

    // Corregido: era "$$" y "currebt"
    while(current && (current->x < xPos || (current->x == xPos && current->y < yPos))) {
        prev = current;
        current = current->next;
    }
    
    if(current && current->x == xPos && current->y == yPos) {
        current->value = value;
        delete newNodo;
        return;
    }
    
    newNodo->next = current;
    if(prev)
        prev->next = newNodo;
    else
        start = newNodo;
}

int SparseMatrix::get(int xPos, int yPos) {
    Nodo* current = start;
    while(current) {
        if(current->x == xPos && current->y == yPos)
            return current->value;
        current = current->next;
    }
    return 0;
}

void SparseMatrix::remove(int xPos, int yPos) {
    Nodo* current = start;  // Era "Node*", debe ser "Nodo*"
    Nodo* prev = nullptr;

    while(current) {
        if(current->x == xPos && current->y == yPos) {
            if(prev) 
                prev->next = current->next;
            else 
                start = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void SparseMatrix::printStoredValues() {
    Nodo* current = start;  // Era "Node*", debe ser "Nodo*"
    if(!current) {
        cout << "La matriz está vacía." << endl;
        return;
    }
    while(current) {
        cout << "(" << current->x << ", " << current->y << ") --> " << current->value << endl;
        current = current->next;
    }
}

int SparseMatrix::density() {  // Cambiado de float a int según el .h
    if(!start) return 0;

    int count = 0;
    int maxX = 0, maxY = 0;

    Nodo* current = start;  // Era "Node*", debe ser "Nodo*"
    while(current) {
        count++;
        if(current->x > maxX) maxX = current->x;
        if(current->y > maxY) maxY = current->y;
        current = current->next;
    }

    int totalSize = (maxX + 1) * (maxY + 1);
    return (count * 100) / totalSize;  // Retorna porcentaje como int
}

SparseMatrix* SparseMatrix::multiply(SparseMatrix* second) {  // Debe retornar puntero
    SparseMatrix* result = new SparseMatrix();
    Nodo* a = start;
    
    while(a) {
        Nodo* b = second->start;
        while(b) {
            if(a->y == b->x) {
                int currentVal = result->get(a->x, b->y);
                result->add(currentVal + (a->value * b->value), a->x, b->y);
            }
            b = b->next;
        }
        a = a->next;
    }
    
    return result;
}

SparseMatrix::~SparseMatrix() {
    Nodo* current = start;  // Era "Node*", debe ser "Nodo*"
    while(current) {
        Nodo* temp = current;
        current = current->next;
        delete temp;
    }
}