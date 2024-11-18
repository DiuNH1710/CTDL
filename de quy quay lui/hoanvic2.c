#include <stdio.h>

// Hàm hoán đổi giá trị của hai phần tử
void hoanDoi(int arr[], int i, int j)
{
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
}

// Hàm đệ quy liệt kê hoán vị
void lietKeHoanVi(int arr[], int start, int n)
{
      // Điều kiện dừng: Nếu đã hoán vị hết tất cả các vị trí thì in ra mảng hiện tại
      if (start == n)
      {
            for (int i = 0; i < n; i++)
            {
                  printf("%d ", arr[i]);
            }
            printf("\n");
            return;
      }

      // Duyệt qua các phần tử từ vị trí start đến n
      for (int i = start; i < n; i++)
      {
            // Hoán đổi phần tử tại vị trí start với phần tử tại vị trí i
            hoanDoi(arr, start, i);

            // Gọi đệ quy để tiếp tục hoán vị cho các phần tử còn lại
            lietKeHoanVi(arr, start + 1, n);

            // Đổi lại để khôi phục mảng gốc (backtracking)
            hoanDoi(arr, start, i);
      }
}

int main()
{
      int n;
      printf("Nhập số phần tử n: ");
      scanf("%d", &n);

      // Tạo mảng chứa các số từ 1 đến n
      int arr[n];
      for (int i = 0; i < n; i++)
      {
            arr[i] = i + 1; // Khởi tạo mảng với các số từ 1 đến n
      }

      printf("Các hoán vị của dãy số từ 1 đến %d là:\n", n);
      lietKeHoanVi(arr, 0, n);

      return 0;
}
