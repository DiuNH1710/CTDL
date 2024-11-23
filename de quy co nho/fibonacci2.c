#include <stdio.h>

#define MAX 100 // Giới hạn cho số lượng đĩa

// Khai báo mảng để lưu trữ giá trị Fibonacci
int memo[MAX];

// Hàm tính số Fibonacci có nhớ
int fibonacci_memo(int n)
{
      if (n <= 1)
      {
            return n;
      }
      if (memo[n] == -1)
      {
            return memo[n]; // Trả về giá trị đã tính trước đó
      }
      memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2); // Tính và lưu vào mảng
      return memo[n];
}

int main()
{
      int n = 10; // Tính số Fibonacci thứ 10

      // Khởi tạo mảng memo với giá trị -1
      for (int i = 0; i < MAX; i++)
      {
            memo[i] = -1;
      }

      printf("Fibonacci(%d) = %d\n", n, fibonacci_memo(n));
      return 0;
}
