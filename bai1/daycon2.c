#include <stdio.h>

// Hàm tìm tổng lớn nhất của dãy con bắt buộc phải đi qua giữa mảng, do phuc tap O (nlogn)
int maxCrossingSum(int arr[], int left, int mid, int right)
{
      { /*Khi dùng phương pháp chia để trị, ta chia mảng thành nhiều phần và giải quyết từng phần riêng biệt. Vì các phần này có thể không chứa phần tử đầu tiên của dãy ban đầu, việc khởi tạo maxSum hoặc leftSum, rightSum bằng arr[0] sẽ không chính xác trong mọi nhánh. Thay vào đó, ta cần khởi tạo leftSum và rightSum với một giá trị cực nhỏ để đảm bảo so sánh được với bất kỳ tổng nào tính được trong các nhánh con.*/
      }
      int leftSum = -1000000; // Giá trị nhỏ để bắt đầu or dùng -1e9
      int sum = 0;

      // Tìm tổng lớn nhất bên trái của mid
      for (int i = mid; i >= left; i--)
      {
            sum += arr[i];
            if (sum > leftSum)
                  leftSum = sum;
      }

      int rightSum = -1000000; // Giá trị nhỏ để bắt đầu
      sum = 0;

      // Tìm tổng lớn nhất bên phải của mid
      for (int i = mid + 1; i <= right; i++)
      {
            sum += arr[i];
            if (sum > rightSum)
                  rightSum = sum;
      }

      // Trả về tổng lớn nhất qua mid
      return leftSum + rightSum;
}

// Hàm chia để trị tìm dãy con lớn nhất
int maxSubArrayDivideAndConquer(int arr[], int left, int right)
{
      // Trường hợp cơ bản
      if (left == right)
            return arr[left];

      int mid = (left + right) / 2;

      // Tổng lớn nhất trong mảng nằm bên trái hoặc bên phải hoặc qua giữa
      int leftMax = maxSubArrayDivideAndConquer(arr, left, mid);
      int rightMax = maxSubArrayDivideAndConquer(arr, mid + 1, right);
      int crossMax = maxCrossingSum(arr, left, mid, right);

      // Trả về tổng lớn nhất của ba phần
      if (leftMax >= rightMax && leftMax >= crossMax)
            return leftMax;
      else if (rightMax >= leftMax && rightMax >= crossMax)
            return rightMax;
      else
            return crossMax;
}

int main()
{
      int arr[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7};
      int n = sizeof(arr) / sizeof(arr[0]);

      int maxSum = maxSubArrayDivideAndConquer(arr, 0, n - 1);
      printf("Tổng lớn nhất của dãy con là: %d\n", maxSum);

      return 0;
}
