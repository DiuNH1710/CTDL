// Tìm dãy con lớn nhất
#include <stdio.h>

// c1: duyệt toàn bộ (On^3)

void maxSubArray(int arr[], int n)
{
      int maxSum = arr[0];
      for (int i = 0; i < n; i++)
      {
            for (int j = i; j < n; j++)
            {
                  int sum = 0;
                  for (int k = i; k <= j; k++)
                  {
                        sum += arr[k];
                        if (sum > maxSum)
                              maxSum = sum;
                  }
            }
      }

      printf("%d", maxSum);
}
// cach 2: su dung Kadane (On)
void maxSubArrayKadane(int arr[], int n)
{
      int maxSum = arr[0];
      int currentSum = arr[0];

      for (int i = 1; i < n; i++)
      {
            currentSum = (currentSum + arr[i] > arr[i]) ? currentSum + arr[i] : arr[i];
            if (currentSum > maxSum)
            {
                  maxSum = currentSum;
            }
      }

      printf("Tổng của dãy con lớn nhất là: %d\n", maxSum);
}
// cach 3: O(n^2)
void maxSumArray2(int arr[], int n)
{
      int maxSum = arr[0];
      for (int i = 0; i < n; i++)
      {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                  sum += arr[j];
                  if (sum > maxSum)
                        maxSum = sum;
            }
      }
      printf("%d", maxSum);
}

int main()
{
      int n;
      printf("nhap so phan tu cua mang: ");
      scanf("%d", &n);
      int arr[n];
      for (int i = 0; i < n; i++)
      {
            scanf("%d", &arr[i]);
      }
      maxSubArray(arr, n);
      printf("\n");
      maxSubArrayKadane(arr, n);
      printf("\n");
      maxSumArray2(arr, n);
}