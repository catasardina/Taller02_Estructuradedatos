#pragma once

class Node {
public:
    int value;
    int x, y;
    Node* next;

    Node(int value, int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        this->next = nullptr;
    }
};
