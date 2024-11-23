#include <stdio.h>

int a[100];
int F(int n)
{

      if (n < 2)
      {
            return n;
      }
      if (a[n] == -1)
      {
            a[n] = (F(n - 1) + F(n - 2));
            return a[n];
      }
      return a[n];
}

int main()
{
      int n;
      scanf("%d", &n);

      for (int i = 0; i <= n; i++)
      {
            a[i] = -1;
      }
      printf("%d", F(n));

      return 0;
}