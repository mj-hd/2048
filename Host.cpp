#include "Host.h"

#include <iostream>
#include <string>
#include <random>

#include "Board.h"

static const char* Separator = "----------";

void Host::Turn() {

    this->_PutRandomValue();

    std::cout << this->_Board;

    std::cout << Separator << std::endl;


    std::cout << "Input Direction(Left, Right, Up, Down):";


    std::string operation;

    std::cin >> operation;


    this->_Board.Tilt(ToDirection(operation));

    std::cout << this->_Board;

    std::cout << Separator << std::endl;
}

void Host::_PutRandomValue() {
    std::random_device rnd;

    int size = this->_Board.GetSize();

    while (true) {
        int x = rnd() % size;
        int y = rnd() % size;

        if (this->_Board(x, y) == 0) {

            this->_Board(x, y) = (rnd() % 2) ? 2 : 4;

            break;
        }
    }
}
