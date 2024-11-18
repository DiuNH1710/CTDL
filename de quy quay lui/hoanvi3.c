#include <stdio.h>

int n;
int used[100];
int arr[100];

void Try(int k)
{
      for (int i = 1; i <= n; i++)
      {
            if (used[i] == 0) // Kiểm tra xem phần tử i đã được sử dụng chưa
            {
                  arr[k] = i;  // Gán phần tử i vào vị trí k
                  used[i] = 1; // Đánh dấu phần tử i đã được sử dụng
                  if (k == n)  // Kiểm tra điều kiện in ra hoán vị
                  {
                        for (int j = 1; j <= n; j++) // In từ 1 đến n
                        {
                              printf("%d", arr[j]);
                        }
                        printf("\n");
                  }
                  else
                  {
                        Try(k + 1); // Gọi đệ quy cho vị trí tiếp theo
                  }
                  used[i] = 0; // Đặt lại phần tử i chưa được sử dụng
            }
      }
}

int main()
{
      printf("Nhap so phan tu n: ");
      scanf("%d", &n);

      // Khởi tạo mảng used
      for (int i = 1; i <= n; i++) // Khởi tạo từ 1 đến n
      {
            used[i] = 0; // Đặt tất cả các phần tử chưa được sử dụng
      }

      Try(1); // Bắt đầu từ chỉ số 1
      return 0;
}
