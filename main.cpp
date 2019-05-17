#include <iostream>
#include "NQBA.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    NQBA a;
    /*
          board of size NxN
          initially all the cells of the board
          is set to 0

          0 means there is no queen in the cell
          1 means there is a queen in the cell
         */
    int board[N][N] = {0};

    if (a.solveNQ(board, 0) == false) {
        printf("No solution!\n");
    } else {
        a.display(board);
    }

    return 0;
}