/*
Name: Zaid Bulbul
Date: 11/08/2024

This program is a tic tac toe game that allows you to play against the comuter, where
it will randomly make plays on the table until either the user wins or program wins.
The program has a simulated thinking mode so that the game is not so fast and abrupt.
Updated to be played in 3D
*/

// all needed for operations of this progam
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <thread>
#include <chrono>

// all the functions related to teh game
class THEGAME3D { // 3D TIME LETS GOOOOOOOOOOO
private:
    char board3D[3][3][3];  // 3 by 3 layers
    char turn;
    char user;
    char cpu;
    int userscore = 0; //score
    int cpuscore = 0;

//setting up the board, seeds random number generator and decides who goes first
public:
    THEGAME3D() {
        intboard();
        srand(static_cast<unsigned int>(time(0)));
        if (rand() % 2 == 0) {
            turn = 'X';
            user = 'X';
            cpu = 'O';
            std::cout << "You will go first as 'X'.\n";
        } else {
            turn = 'O';
            user = 'O';
            cpu = 'X';
            std::cout << "Computer will go first as 'X'.\n";
        }
    }
// the gameplay
    void play() {
        bool wincond = false;//repeats until either someone wins or we reach a draw
        bool even = false;

        display();
//alternating turns
        while (!wincond && !even) {
            if (turn == user) {
                userMove();
            } else {
                cpuMove();
            }

            display();
            wincond = checkW(turn);
            even = checkDraw();

//when you win, lose, or draw and its outputs
            if (wincond) {
                if (turn == user) {
                    std::cout << "WINNER WINNER CHICKEN DINNER\n";
                    userscore++;
                } else {
                    std::cout << "Its.. so...  jover..\n";
                    cpuscore++;
                }
                dispscore();
                resetBoard();  // resets board
            } else if (even) {
                std::cout << "Draw\n";
                dispscore();
                resetBoard();
            } else {
                switchTurn();
            }
        }
    }

private:
    void intboard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    board3D[i][j][k] = ' ';  // this fills the board with the cells
                }
            }
        }
    }
    
// rendering the board is rendered
    void display() {
        for (int k = 0; k < 3; ++k) {
            std::cout << "\nLayer " << k + 1 << ":\n";
            std::cout << "-------------\n";
            for (int i = 0; i < 3; ++i) {
                std::cout << "| ";
                for (int j = 0; j < 3; ++j) {
                    std::cout << board3D[k][i][j] << " | ";
                }
                std::cout << "\n";
                std::cout << "-------------\n";
            }
            std::cout << "\n";
        }
    }

//Making sure the entered number is valid and occupying the entry
    void userMove() {
        int layer, row, col;
        bool allowedMove = false;

        while (!allowedMove) {
            std::cout << "Enter the layer (1-3), row (1-3), and column (1-3) separated by spaces (eg. 1 3 3): ";
            std::cin >> layer >> row >> col;

            layer--; row--; col--;  

            if (layer >= 0 && layer < 3 && row >= 0 && row < 3 && col >= 0 && col < 3) {
                if (board3D[layer][row][col] != 'X' && board3D[layer][row][col] != 'O') {
                    board3D[layer][row][col] = user;
                    allowedMove = true;
                } else {
                    std::cout << "Cell is full. Try elsewhere\n";
                }
            } else {
                std::cout << "Bad input buddy.\n";
            }
        }
    }

    void cpuMove() {
        std::cout << "The CPU is thinking...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // pretends to think because its no fun otherwise O_O

        std::vector<int> movesLeft;
        for (int i = 0; i < 27; ++i) {
            int layer = i / 9;
            int row = (i % 9) / 3;
            int col = i % 3;
            if (board3D[layer][row][col] != 'X' && board3D[layer][row][col] != 'O') {
                movesLeft.push_back(i);
            }
        }

        if (!movesLeft.empty()) {
            int randomIndex = rand() % movesLeft.size();
            int move = movesLeft[randomIndex];
            int layer = move / 9;
            int row = (move % 9) / 3;
            int col = move % 3;
            board3D[layer][row][col] = cpu;
        }
    }

    bool checkW(char player) {
        // checking for win
        for (int layer = 0; layer < 3; ++layer) {
            for (int i = 0; i < 3; ++i) {
                // check rows
                if (board3D[layer][i][0] == player && board3D[layer][i][1] == player && board3D[layer][i][2] == player)
                    return true;
                // check columns
                if (board3D[layer][0][i] == player && board3D[layer][1][i] == player && board3D[layer][2][i] == player)
                    return true;
            }
            // diagnols
            if (board3D[layer][0][0] == player && board3D[layer][1][1] == player && board3D[layer][2][2] == player)
                return true;
            if (board3D[layer][0][2] == player && board3D[layer][1][1] == player && board3D[layer][2][0] == player)
                return true;
        }

        // the columns
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board3D[0][i][j] == player && board3D[1][i][j] == player && board3D[2][i][j] == player)
                    return true;
            }
        }

        // 3D diagonals
        if (board3D[0][0][0] == player && board3D[1][1][1] == player && board3D[2][2][2] == player)
            return true;
        if (board3D[0][0][2] == player && board3D[1][1][1] == player && board3D[2][2][0] == player)
            return true;
        if (board3D[0][2][0] == player && board3D[1][1][1] == player && board3D[2][0][2] == player)
            return true;
        if (board3D[0][2][2] == player && board3D[1][1][1] == player && board3D[2][0][0] == player)
            return true;

        return false;
    }

    bool checkDraw() {
        for (int layer = 0; layer < 3; ++layer)
            for (int row = 0; row < 3; ++row)
                for (int col = 0; col < 3; ++col)
                    if (board3D[layer][row][col] != 'X' && board3D[layer][row][col] != 'O')
                        return false;
        return true;
    }

    void switchTurn() {
        turn = (turn == 'X') ? 'O' : 'X';
    }

    void resetBoard() {
        intboard();
    }

    void dispscore() {
        std::cout << "Your Score: " << userscore << " | CPU Score: " << cpuscore << "\n";
    }
};

int main() {
    THEGAME3D game;
    game.play();
    return 0;
}
