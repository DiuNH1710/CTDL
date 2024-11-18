#include <stdio.h>

// Hàm tính số Fibonacci không có nhớ
int fibonacci_no_memo(int n)
{
      if (n <= 1)
      {
            return n;
      }
      return fibonacci_no_memo(n - 1) + fibonacci_no_memo(n - 2);
}

int main()
{
      int n = 10; // Tính số Fibonacci thứ 10
      printf("Fibonacci(%d) = %d\n", n, fibonacci_no_memo(n));
      return 0;
}
