#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define N 4
#define INF 1e9

// Hàm giải bài toán người du lịch bằng Dynamic Programming
int tsp(int mask, int pos, vector<vector<int>> &dist, vector<vector<int>> &dp) {
    // Nếu tất cả các thành phố đã được thăm
    if (mask == (1 << N) - 1)
        return dist[pos][0]; // Quay lại thành phố ban đầu

    // Nếu kết quả đã được tính trước
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    // Tìm hành trình ngắn nhất bằng cách thử các thành phố chưa được thăm
    int ans = INF;
    for (int city = 0; city < N; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = min(ans, newAns);
        }
    }

    // Lưu trữ kết quả
    return dp[mask][pos] = ans;
}

int main() {
    // Ma trận khoảng cách giữa các thành phố
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    // Khởi tạo mảng DP với giá trị -1
    vector<vector<int>> dp((1 << N), vector<int>(N, -1));

    // Gọi hàm TSP bắt đầu từ thành phố 0
    cout << "Chi phi nho nhat: " << tsp(1, 0, dist, dp) << endl;

    return 0;
}
