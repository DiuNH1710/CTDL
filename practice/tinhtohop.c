#include <stdio.h>

int M[100][100];

int C(int k, int n)
{
      if (k == 0 || k == n)
      {
            return M[k][n] = 1;
      }
      else
      {
            if (M[k][n] == 0)
            {
                  M[k][n] = C(k - 1, n - 1) + C(k, n - 1);
                  return M[k][n];
            }
            return M[k][n];
      }
}

int main()
{
      int k, n;
      scanf("%d", &k);
      scanf("%d", &n);
      for (int i = 0; i <= k; i++)
      {
            for (int j = 0; j <= n; j++)
            {
                  M[i][j] = 0;
            }
      }
      printf("%d", C(k, n));
      return 0;
}