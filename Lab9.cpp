/*
Name: Zaid Bulbul
Date: 11/01/2024

This program is a tic tac toe game that allows you to play against the comuter, where
it will randomly make plays on the table until either the user wins or program wins.
The program has a simulated thinking mode so that the game is not so fast and abrupt.

*/

// all needed for operations of this progam
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <thread>     
#include <chrono>   

// all the functions related to teh game
class THEGAME {
private:
    char board[3][3];
    char turn;
    char user;
    char cpu;


//setting up the board, seeds random number generator and decides who goes first
public:
    THEGAME() { 
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
                usermove();
            } else {
                cpumove();
            }

            display();
            wincond = win1(turn);
            even = draw();
//when you win, lose, or draw and its outputs
            if (wincond) {
                if (turn == user) {
                    std::cout << "Congratulations! You win!\n";
                } else {
                    std::cout << "Computer wins! Better luck next time.\n";
                }
            } else if (even) {
                std::cout << "It's a draw!\n";
            } else {
                switchTurn(); 
            }
        }
    }
//this fills the board with the cells
private:
    void intboard() { 
        char count = '1';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = count++;
            }
        }
    }
// rendering the board is rendered
    void display() {
        std::cout << "\n";
        std::cout << "-------------\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << "| ";
            for (int j = 0; j < 3; ++j) {
                std::cout << board[i][j] << " | ";
            }
            std::cout << "\n";
            std::cout << "-------------\n";
        }
        std::cout << "\n";
    }
//Making sure the entered number is valid and occupying the entry
    void usermove() {
        int move;
        bool allowedmove = false;

        while (!allowedmove) {
            std::cout << "Enter the number of the cell where you want to place your '" << user << "': ";
            std::cin >> move;

            if (std::cin.fail() || move < 1 || move > 9) {
                std::cin.clear(); // Clear error flag
                std::cin.ignore(1000, '\n'); // Discard input
                std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            } else {
                int row = (move - 1) / 3;
                int col = (move - 1) % 3;

                if (board[row][col] != 'X' && board[row][col] != 'O') {
                    board[row][col] = user;
                    allowedmove = true;
                } else {
                    std::cout << "Cell already occupied. Please choose another cell.\n";
                }
            }
        }
    }

    void cpumove() {
        std::cout << "Computer is making a move...\n";
        
        // emulate thinking
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // 1-second delay

        // checking all available moves
        std::vector<int> movesleft;
        for (int i = 0; i < 9; ++i) {
            int row = i / 3;
            int col = i % 3;
            if (board[row][col] != 'X' && board[row][col] != 'O') {
                movesleft.push_back(i);
            }
        }

        if (!movesleft.empty()) {
            // pick a random move
            int randomIndex = rand() % movesleft.size();
            int move = movesleft[randomIndex];
            int row = move / 3;
            int col = move % 3;
            board[row][col] = cpu;
        }
    }
// win conditions
    bool win1(char player) {
        // rows
        for (int i = 0; i < 3; ++i)
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;

        // columns
        for (int j = 0; j < 3; ++j)
            if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
                return true;

        // diagonals
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;

        return false;
    }
// on draw
    bool draw() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] != 'X' && board[i][j] != 'O')
                    return false;
        return true;
    }

    void switchTurn() { 
        turn = (turn == 'X') ? 'O' : 'X';
    }
};

int main() {
    THEGAME game;
    game.play();
    return 0;
}
