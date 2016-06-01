#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include <vector>
#include <string>

typedef unsigned int Value;

enum class Direction : unsigned char {
    Up = 0,
    Left,
    Right,
    Down
};

Direction ToDirection(std::string str);

class Board {
public:
    Board() : Board(4) {}
    Board(int size);
    ~Board();

    Value& operator() (int x, int y) { return this->_Board[x][y]; }
    Value  Get(int x, int y) const { return this->_Board[x][y]; }
    int GetSize() const { return this->_Size; }

    void Tilt(Direction d);

    friend std::ostream& operator<<(std::ostream& stream, const Board &b);

protected:
    std::vector<std::vector<Value>> _Board;
    int _Size;
};

#endif
