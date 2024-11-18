#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 9

// Hàm in bảng Sudoku
void printBoard(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
    cout << endl;
}

// Hàm kiểm tra số num có hợp lệ khi điền vào ô (row, col)
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Kiểm tra hàng
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Kiểm tra cột
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Kiểm tra ô vuông 3x3
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

// Hàm shuffle số để tạo ra thứ tự ngẫu nhiên từ 1 đến 9
vector<int> getRandomNumbers() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    random_shuffle(nums.begin(), nums.end());
    return nums;
}

// Hàm giải Sudoku và tìm tất cả lời giải có thể
bool solveSudoku(int grid[N][N], int row, int col, vector<vector<int>> &solutions) {
    if (row == N - 1 && col == N)
        return true; // Đã hoàn thành

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1, solutions);

    vector<int> nums = getRandomNumbers(); // Tạo thứ tự ngẫu nhiên cho các số từ 1 đến 9

    for (int num : nums) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1, solutions)) {
                vector<int> solution;
                for (int r = 0; r < N; r++)
                    for (int c = 0; c < N; c++)
                        solution.push_back(grid[r][c]);
                solutions.push_back(solution);
            }

            grid[row][col] = 0; // Backtracking
        }
    }

    return false;
}

int main() {
    // Bảng Sudoku với các ô trống được biểu diễn bằng 0
    int grid[N][N] = {
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

    vector<vector<int>> solutions;
    srand(time(0)); // Khởi tạo seed cho random shuffle

    solveSudoku(grid, 0, 0, solutions);

    if (!solutions.empty()) {
        cout << "So luong loi giai: " << solutions.size() << endl;
        for (size_t i = 0; i < solutions.size(); i++) {
            cout << "Loi giai " << i + 1 << ":" << endl;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++)
                    cout << solutions[i][r * N + c] << " ";
                cout << endl;
            }
            cout << endl;
        }
    } else {
        cout << "Khong co loi giai." << endl;
    }

    return 0;
}
