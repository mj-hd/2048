#ifndef _HOST_H_
#define _HOST_H_

#include "Board.h"

class Host {
public:
    Host() : _Board(*new Board()) {}

    void Turn();

protected:
    Board& _Board;

    void _PutRandomValue();
};

#endif
