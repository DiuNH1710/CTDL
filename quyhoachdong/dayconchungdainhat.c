#include <stdio.h>
#include <string.h>

int LCS(char X[], char Y[])
{
      int n = strlen(X);
      int m = strlen(Y);
      int dp[n + 1][m + 1];

      // Khởi tạo hàng và cột đầu tiên của bảng dp là 0
      for (int i = 0; i <= n; i++)
      {
            for (int j = 0; j <= m; j++)
            {
                  if (i == 0 || j == 0)
                        dp[i][j] = 0;
                  else if (X[i - 1] == Y[j - 1])
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                  else
                        dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
      }

      return dp[n][m];
}

int main()
{
      char X[100], Y[100];
      printf("Nhập chuỗi X: ");
      scanf("%s", X);
      printf("Nhập chuỗi Y: ");
      scanf("%s", Y);

      int result = LCS(X, Y);
      printf("Độ dài dãy con chung dài nhất: %d\n", result);

      return 0;
}
