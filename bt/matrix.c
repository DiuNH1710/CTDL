#include <stdio.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

// Cấu trúc lưu tọa độ ô
typedef struct {
    int x;
    int y;
} Point;

// Cấu trúc lưu tọa độ ô và khoảng cách
typedef struct {
    Point pt;
    int dist;
} queueNode;

// Hướng di chuyển: lên, xuống, trái, phải
int rowNum[] = {-1, 1, 0, 0};
int colNum[] = {0, 0, -1, 1};

// Kiểm tra ô có hợp lệ không
bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

// Tìm đường đi ngắn nhất giữa điểm nguồn và điểm đích
int BFS(int mat[ROW][COL], Point src, Point dest) {
    // Nếu điểm bắt đầu hoặc kết thúc không hợp lệ
    if (mat[src.x][src.y] != 1 || mat[dest.x][dest.y] != 1)
        return -1;

    bool visited[ROW][COL] = {false};

    // Đánh dấu ô bắt đầu đã thăm
    visited[src.x][src.y] = true;

    // Hàng đợi để thực hiện BFS
    queueNode queue[ROW * COL];
    int front = 0, rear = 0;

    // Đưa ô bắt đầu vào hàng đợi với khoảng cách 0
    queue[rear++] = (queueNode){src, 0};

    // BFS
    while (front < rear) {
        queueNode curr = queue[front++];
        Point pt = curr.pt;

        // Nếu đến ô đích
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;

        // Kiểm tra các ô lân cận
        for (int i = 0; i < 4; i++) {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            // Nếu ô lân cận hợp lệ và chưa thăm
            if (isValid(row, col) && mat[row][col] == 1 && !visited[row][col]) {
                visited[row][col] = true;
                queue[rear++] = (queueNode){{row, col}, curr.dist + 1};
            }
        }
    }

    // Trả về -1 nếu không tìm thấy đường đi
    return -1;
}

int main() {
    int mat[ROW][COL] = {
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };

    Point source = {0, 0};
    Point dest = {3, 4};

    int dist = BFS(mat, source, dest);

    if (dist != -1)
        printf("Shortest Path is %d\n", dist);
    else
        printf("Shortest Path doesn't exist\n");

    return 0;
}
