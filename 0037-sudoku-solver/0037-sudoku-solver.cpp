class Solution {
public:
    bool findEmptyCell(vector<vector<char>>& board, int& row, int& col) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    row = i;
                    col = j;
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num)
                return false;
        }

        int startRow = (row / 3) * 3;
        int endCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = endCol; j < endCol + 3; j++) {
                if (board[i][j] == num)
                    return false;
            }
        }
        return true;
    }

    bool solver(vector<vector<char>>& board) {
        int row, col;
        if (!findEmptyCell(board, row, col))
            return true;

        for (char i = '1'; i <= '9'; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = i;
                if (solver(board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};