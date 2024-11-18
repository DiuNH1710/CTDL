#include <stdio.h>

int max(int a, int b)
{
      return (a > b) ? a : b;
}

int maxLeft(int a[], int low, int mid)
{
      int maxSum = -1e9;
      int sum = 0;
      for (int k = mid; k >= low; k--)
      {
            sum += a[k];
            maxSum = max(sum, maxSum);
      }

      return maxSum;
}

int maxRight(int a[], int mid1, int high)
{
      int maxSum = -1e9;
      int sum = 0;
      for (int k = mid1; k <= high; k++)
      {
            sum += a[k];
            maxSum = max(sum, maxSum);
      }

      return maxSum;
}

int maxSub(int a[], int low, int high)
{
      if (low == high)
            return a[low];
      else
      {
            int mid = (low + high) / 2;
            int wL = maxSub(a, low, mid);
            int wR = maxSub(a, mid + 1, high);
            int wM = maxLeft(a, low, mid) + maxRight(a, mid + 1, high);
            return max(wL, max(wR, wM));
      }
}

int main()
{
      int n;
      scanf("%d", &n);
      int a[n];
      for (int i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }

      printf("%d", maxSub(a, 0, n - 1));
      return 0;
}