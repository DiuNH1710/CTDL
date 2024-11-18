#include <stdio.h>

// Khai báo biến toàn cục
int M[1000000]; // Mảng lưu trữ giá trị Fibonacci đã tính
int n;          // Biến để lưu giá trị Fibonacci cần tính

// Hàm khởi tạo
void init()
{
      M[0] = 0;
      M[1] = 1;
      for (int i = 2; i <= n; i++) // Bắt đầu từ 2 để không ghi đè M[0] và M[1]
            M[i] = 0;
}

// Hàm đệ quy có nhớ để tính Fibonacci
int F(int n)
{
      if (n != 0 && M[n] == 0)
      { // Chỉ tính nếu M[n] chưa được tính trước đó
            M[n] = F(n - 1) + F(n - 2);
      }

      return M[n];
}

int main()
{
      // Nhập giá trị n từ bàn phím
      printf("Nhập giá trị n: ");
      scanf("%d", &n);

      // Khởi tạo mảng lưu trữ
      init();

      // Gọi hàm Fibonacci và in ra kết quả
      printf("Fibonacci(%d) = %d\n", n, F(n));

      return 0;
}
