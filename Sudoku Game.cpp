#include <iostream>
#include <vector>

const int N = 9; // Size of the Sudoku board

// Function to print the Sudoku board
void printBoard(const std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        if (i % 3 == 0 && i != 0) {
            std::cout << "---------------------" << std::endl;
        }
        for (int j = 0; j < N; j++) {
            if (j % 3 == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a number can be placed in a cell
bool isValidMove(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[boxRow + i][boxCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (isValidMove(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0; // If the current configuration doesn't lead to a solution, backtrack.
                    }
                }
                return false; // If no number can be placed, the puzzle is unsolvable in this configuration.
            }
        }
    }
    return true; // The puzzle is solved.
}

int main() {
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));

    // Example Sudoku puzzle (0 represents empty cells)
    std::vector<std::vector<int>> puzzle = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Copy the puzzle to the board
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = puzzle[i][j];
        }
    }

    std::cout << "Sudoku Puzzle:" << std::endl;
    printBoard(board);

    if (solveSudoku(board)) {
        std::cout << "\nSolved Sudoku:" << std::endl;
        printBoard(board);
    } else {
        std::cout << "\nNo solution exists." << std::endl;
    }

    return 0;
}