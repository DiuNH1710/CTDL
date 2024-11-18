#include <stdio.h>
#include <string.h>

int n;
int c[10][10];
int x[10];
int visited[10];
int f = 0;
int xbest[10];
int fbest = 1e8;
int cmin = 1e8;

void solution()
{
      for (int i = 1; i <= n; ++i)
      {
            printf("%d:", xbest[i]);
      }
      printf("%d\n", xbest[1]);
}
int check(int v, int k)
{
      if (visited[v] == 1)
      {
            return 0;
      }
      return 1;
}

void Try(int k)
{
      for (int v = 2; v <= n; ++v)
      {
            if (check(v, k))
            {
                  x[k] = v;
                  visited[v] = 1;
                  f = f + c[x[k - 1]][x[k]];
                  if (k == n)
                  {
                        int ftemp = f + c[x[n]][x[1]];
                        if (ftemp < fbest)
                        {
                              fbest = ftemp;
                              memcpy(xbest, x, sizeof(int) * 10);
                        };
                  }
                  else
                  {
                        int g = f + (n - k + 1) * cmin;
                        if (g < fbest)
                              Try(k + 1);
                  }
                  visited[v] = 0;

                  f = f - c[x[k - 1]][x[k]];
            };
      }
}

int main()
{
      // nhap input
      printf("nhap n = ");
      scanf("%d", &n);
      for (int i = 1; i <= n; i++)
      {
            for (int j = 1; j <= n; ++j)
            {
                  scanf("%d", &c[i][j]);
                  if (c[i][j] < cmin)
                  {
                        cmin = c[i][j];
                  }
            }
      }

      for (int i = 1; i <= n; i++)
      {
            visited[i] = 0;
      }

      x[1] = 1;
      visited[1] = 1;
      Try(2);
      printf(" Chi phi nho nhat : %d", fbest);
      printf("Duong di: ");
      solution();
      return 0;
};
