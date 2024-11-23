#include <stdio.h>

#define SIZE 9

int X[SIZE][SIZE];         // Ma trận để lưu kết quả Sudoku
int markR[SIZE][SIZE + 1]; // Đánh dấu các giá trị đã có trên mỗi hàng
int markC[SIZE][SIZE + 1]; // Đánh dấu các giá trị đã có trên mỗi cột
int markS[3][3][SIZE + 1]; // Đánh dấu các giá trị đã có trên mỗi ô 3x3
int found = 0;             // Biến để dừng lại khi tìm thấy lời giải

// Hàm kiểm tra xem có thể điền giá trị v vào vị trí hàng r, c không
int check(int v, int r, int c)
{
      if (markR[r][v] == 1)
            return 0;
      if (markC[c][v] == 1)
            return 0;
      if (markS[r / 3][c / 3][v] == 1)
            return 0;
      return 1;
}

// Hàm thử điền giá trị vào từng ô
void Try(int r, int c)
{
      if (found) // Nếu đã tìm được lời giải, không làm gì nữa
            return;

      if (r == SIZE)
      { // Nếu đã điền xong hàng cuối cùng, in kết quả
            for (int i = 0; i < SIZE; i++)
            {
                  for (int j = 0; j < SIZE; j++)
                  {
                        printf("%d ", X[i][j]);
                  }
                  printf("\n");
            }
            printf("\n");
            found = 1; // Đánh dấu đã tìm thấy lời giải
            return;
      }

      // Chuyển sang ô tiếp theo
      int nextR = (c == SIZE - 1) ? r + 1 : r;
      int nextC = (c == SIZE - 1) ? 0 : c + 1;

      if (X[r][c] != 0)
      { // Nếu ô hiện tại đã có giá trị, bỏ qua
            Try(nextR, nextC);
      }
      else
      { // Nếu ô hiện tại trống, thử điền giá trị từ 1 đến 9
            for (int v = 1; v <= SIZE; v++)
            {
                  if (check(v, r, c))
                  {
                        X[r][c] = v;
                        markR[r][v] = 1;
                        markC[c][v] = 1;
                        markS[r / 3][c / 3][v] = 1;

                        Try(nextR, nextC); // Gọi đệ quy để điền các ô tiếp theo

                        if (found) // Nếu đã tìm thấy lời giải, dừng lại
                              return;

                        // Khôi phục lại trạng thái nếu thử sai
                        X[r][c] = 0;
                        markR[r][v] = 0;
                        markC[c][v] = 0;
                        markS[r / 3][c / 3][v] = 0;
                  }
            }
      }
}

int main()
{
      // Khởi tạo bảng Sudoku rỗng (toàn số 0)
      for (int i = 0; i < SIZE; i++)
      {
            for (int j = 0; j < SIZE; j++)
            {
                  X[i][j] = 0;
            }
      }

      // Khởi tạo mảng đánh dấu
      for (int i = 0; i < SIZE; i++)
      {
            for (int v = 1; v <= SIZE; v++)
            {
                  markR[i][v] = 0;
                  markC[i][v] = 0;
            }
      }
      for (int i = 0; i < 3; i++)
      {
            for (int j = 0; j < 3; j++)
            {
                  for (int v = 1; v <= SIZE; v++)
                  {
                        markS[i][j][v] = 0;
                  }
            }
      }

      // Bắt đầu thử điền các giá trị vào bảng Sudoku
      Try(0, 0);

      return 0;
}
