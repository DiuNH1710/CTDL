#include <stdio.h>

int power(int a, int n)
{
      if (n == 0)
      {
            return 1; // a^0 = 1
      }

      int half = power(a, n / 2);

      if (n % 2 == 0)
      {
            return half * half; // n chẵn: a^n = (a^(n/2))^2
      }
      else
      {
            return a * half * half; // n lẻ: a^n = a * (a^(n/2))^2
      }
}

int main()
{
      int a, n;
      printf("Nhập cơ số a: ");
      scanf("%d", &a);
      printf("Nhập số mũ n: ");
      scanf("%d", &n);

      int result = power(a, n);
      printf("Kết quả %d^%d = %d\n", a, n, result);

      return 0;
}
