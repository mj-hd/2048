#include "Board.h"

#include <iostream>
#include <vector>

Direction ToDirection(std::string str) {
    if (str == "Up")    return Direction::Up;
    if (str == "Left")  return Direction::Left;
    if (str == "Right") return Direction::Right;
    if (str == "Down")  return Direction::Down;

    return Direction::Up;
}

Board::Board(int size)
    : _Size(size) {
    this->_Board.resize(size);

    for (auto& item : this->_Board) {
        item.resize(size);
    }
}

Board::~Board() {
}

void Board::Tilt(Direction d) {
    int size   = this->GetSize() - 1;

    int yStart = (int)(d == Direction::Down)  * size;
    int yEnd   = (int)(d != Direction::Down)  * size;
    int xStart = (int)(d == Direction::Right) * size;
    int xEnd   = (int)(d != Direction::Right) * size;

    int yStep  = (yEnd - yStart) / size;
    int xStep  = (xEnd - xStart) / size;

    int yRelativePos = yStep * -1 * (int)(d == Direction::Up  || d == Direction::Down);
    int xRelativePos = xStep * -1 * (int)(d == Direction::Left || d == Direction::Right);

    for (int i = 0; i < this->GetSize(); i++) {
        for (int y = yStart; y != yEnd + yStep; y += yStep) {
            if (y == yStart && yRelativePos != 0) continue;

            for (int x = xStart; x != xEnd + xStep; x += xStep) {
                if (x == xStart && xRelativePos != 0) continue;

                Value& currentCell  = (*this)(x, y);
                Value& previousCell = (*this)(x + xRelativePos, y + yRelativePos);

                if (currentCell == 0) continue;

                if (previousCell == currentCell) {
                    previousCell += currentCell;
                    currentCell   = 0;
                }

                if (previousCell == 0) {
                    previousCell = currentCell;
                    currentCell  = 0;
                }
            }
        }
    }
}

std::ostream& operator<<(std::ostream& stream, const Board& b) {
    for (int y = 0; y < b.GetSize(); y++) {
        for (int x = 0; x < b.GetSize(); x++) {
            if (b.Get(x, y) == 0) {
                stream << "  ";
            } else {
                stream << b.Get(x, y) << " ";
            }
        }

        stream << std::endl;
    }

    return stream;
}
