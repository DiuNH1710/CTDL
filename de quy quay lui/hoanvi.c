#include <stdio.h>

int n;
int used[100];
int arr[100];

void Try(int k)
{
      for (int i = 1; i <= n; i++)
      {
            if (used[i] == 0)
            {
                  arr[k] = i;
                  used[i] = 1;
                  if (k == n - 1)
                  {
                        for (int j = 0; j < n; j++)
                        {
                              printf("%d", arr[j]);
                        }
                        printf("\n");
                  }
                  else
                  {
                        Try(k + 1);
                  }
                  used[i] = 0;
            }
      }
}

int main()
{
      printf("Nhap so phan tu n: ");
      scanf("%d", &n);

      // Khoi tao mang used
      for (int i = 0; i < n; i++)
      {
            used[i] = 0;
      }
      Try(0);
      return 0;
}