#include <iostream>
#include <vector>

const int BOARD_SIZE = 3;

// Function to print the Tic-Tac-Toe board
void printBoard(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << board[i][j];
            if (j < BOARD_SIZE - 1)
                std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1) {
            for (int j = 0; j < BOARD_SIZE; ++j) {
                std::cout << "----";
                if (j < BOARD_SIZE - 1)
                    std::cout << "|";
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Function to check if the move is valid
bool isValidMove(const std::vector<std::vector<char>>& board, int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ');
}

// Function to check if the game is over (someone wins or it's a draw)
bool isGameOver(const std::vector<std::vector<char>>& board) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return true;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return true;
    }

    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return true;
    }

    // Check for a draw
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false; // Empty cell found, the game is not a draw yet
            }
        }
    }

    return true; // All cells are filled, and no one has won - it's a draw
}

int main() {
    std::vector<std::vector<char>> board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));
    int currentPlayer = 0; // 0 for Player 1, 1 for Player 2

    while (true) {
        // Print the current board
        std::cout << "Tic-Tac-Toe Game\n";
        printBoard(board);

        int row, col;
        std::cout << "Player " << (currentPlayer + 1) << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (isValidMove(board, row, col)) {
            if (currentPlayer == 0) {
                board[row][col] = 'X';
                currentPlayer = 1;
            } else {
                board[row][col] = 'O';
                currentPlayer = 0;
            }

            if (isGameOver(board)) {
                // Print the final board and game result
                printBoard(board);
                if (isGameOver(board) && !isValidMove(board, row, col))
                    std::cout << "Invalid move! Player " << (currentPlayer + 1) << " wins!" << std::endl;
                else
                    std::cout << "It's a draw!" << std::endl;
                break;
            }
        } else {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    return 0;
}
