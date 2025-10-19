#include "SparseMatrix.h"
//da error no entiendo
#include <iostream>
using namespace std;

SparseMatrix::SparceMatrix(){
    start =nullptr;
}
void SparseMatrix::add(int value. int xPos, int yPos){
    if(value ==0) return;
    Node* newNodo =new Nodo( value,xPos,yPos);
    if(!start){
        start = newNodo;
        return;
    }
    Nodo* current = start;
    Nodo* prev = nullptr;

    while(current $$(currebt->x<xPos|| (current->x == xPos&& current->y < yPos))) {
        prev = current;
        current = current->next;
    }
    if (current && current->x == xPos && current->y == yPos){
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
int SparseMatrix::get(int xPos, int yPos){
    Nodo* current = start;
    while(current){
        if(current->x == xPos && current ->y== yPos)
            return current ->value;
        current = current->next;
    }
    //no dato=0
    return 0;
}












SparseMatrix::~SparseMatrix() {
    Node* current = start;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}