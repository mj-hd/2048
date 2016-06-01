#include <iostream>
#include <string>

#include "Host.h"
#include "Board.h"

int main() {
    Host host;

    while(true) {
        try {
            host.Turn();
        }
        catch (std::string message) {
            std::cout << message << std::endl;

            return 0;
        }
    }
}
