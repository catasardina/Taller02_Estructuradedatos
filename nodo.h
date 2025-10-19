#pragma once

class Nodo {
public:
    int value;
    int x, y;
    Nodo* next;

    Nodo(int value, int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        this->next = nullptr;
    }
};
