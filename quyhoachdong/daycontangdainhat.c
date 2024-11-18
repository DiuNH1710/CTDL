#include <stdio.h>

int longestIncreasingSubsequence(int A[], int n)
{
      int dp[n];         // Mảng dp để lưu độ dài dãy con tăng
      int maxLength = 1; // Độ dài dãy con tăng dài nhất

      // Khởi tạo mảng dp
      for (int i = 0; i < n; i++)
      {
            dp[i] = 1; // Mỗi phần tử tối thiểu có độ dài 1
      }

      // Tính toán độ dài dãy con tăng
      for (int i = 1; i < n; i++)
      {
            for (int j = 0; j < i; j++)
            {
                  if (A[i] > A[j])
                  {
                        dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
                  }
            }
            // Cập nhật độ dài lớn nhất
            if (dp[i] > maxLength)
            {
                  maxLength = dp[i];
            }
      }

      return maxLength; // Trả về độ dài dãy con tăng dài nhất
}

int main()
{
      int A[] = {10, 22, 9, 33, 21, 50, 41, 60, 80}; // Dãy số cho trước
      int n = sizeof(A) / sizeof(A[0]);

      int length = longestIncreasingSubsequence(A, n);
      printf("Độ dài của dãy con tăng dài nhất là: %d\n", length);
      return 0;
}
