#include <iostream>
#include <vector>
using namespace std;

#define N 9

bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < N; ++x) {
        if (board[row][x] == num) return false;
    }
    for (int x = 0; x < N; ++x) {
        if (board[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    int row, col;
    bool foundEmptyCell = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                foundEmptyCell = true;
                break;
            }
        }
        if (foundEmptyCell) break;
    }
    if (!foundEmptyCell) return true;

    for (int num = 1; num <= 9; ++num) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void displayBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(N, vector<int>(N));

    cout << "Enter Sudoku puzzle (9x9 grid, use 0 for empty cells):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    cout << "\nOriginal Sudoku puzzle:" << endl;
    displayBoard(board);

    if (solveSudoku(board)) {
        cout << "\nSolved Sudoku puzzle:" << endl;
        displayBoard(board);
    } else {
        cout << "\nNo solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}
