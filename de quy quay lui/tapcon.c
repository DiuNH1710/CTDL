// liệt kê các tập con m phần tử của tập N = { 1,2,....,n}

#include <stdio.h>
int n, m, s[1000000];

void Solution()
{
      for (int i = 1; i <= m; i++)
      {
            printf("%d", s[i]);
      }
      printf("\n");
}

void Try(int k)
{
      for (int v = s[k - 1] + 1; v <= n - m + k; v++)
      {
            s[k] = v;
            if (k == m)
            {
                  Solution();
            }
            else
            {
                  Try(k + 1);
            }
      }
}

int main()
{

      printf("nhap n = ");
      scanf("%d", &n);
      printf("nhap m =");
      scanf("%d", &m);

      Try(1);
      return 0;
}