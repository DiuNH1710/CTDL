#include <stdio.h>
#include <string.h>

int n;
int c[10][10];
int x[10];
int visited[10];
int f = 0;
int xbest[10];
int fbest = 100000000; // Khởi tạo fbest với giá trị lớn
int cmin = 100000000;  // Khởi tạo cmin với giá trị lớn

void solution()
{
      for (int i = 0; i < n; ++i)
      {
            printf("%d ", xbest[i]);
      }
      printf("\n");
}

int check(int v, int k)
{
      return visited[v] == 0;
}

void Try(int k)
{
      for (int v = 1; v < n; ++v)
      {
            if (check(v, k))
            {
                  x[k] = v;
                  visited[v] = 1;
                  f = f + c[x[k - 1]][x[k]];

                  if (k == n - 1)
                  {
                        int ftemp = f + c[x[n - 1]][x[0]];
                        if (ftemp < fbest)
                        {
                              fbest = ftemp;
                              memcpy(xbest, x, sizeof(int) * n);
                        }
                  }
                  else
                  {
                        int g = f + (n - k) * cmin;
                        if (g < fbest)
                              Try(k + 1);
                  }

                  visited[v] = 0;
                  f = f - c[x[k - 1]][x[k]];
            }
      }
}

int main()
{
      // Nhập input
      printf("Nhập n = ");
      scanf("%d", &n);

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; ++j)
            {
                  scanf("%d", &c[i][j]);
                  if (i != j && c[i][j] < cmin)
                  {
                        cmin = c[i][j];
                  }
            }
      }

      memset(visited, 0, sizeof(visited));

      x[0] = 0; // Đặt điểm xuất phát là 0
      visited[0] = 1;
      Try(1);

      printf("Chi phí nhỏ nhất: %d\n", fbest);
      printf("Đường đi: ");
      solution();
      return 0;
}
