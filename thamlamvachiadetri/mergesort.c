#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
      int n1 = mid - left + 1;
      int n2 = right - mid;
      int L[n1], R[n2]; // Tạo mảng tạm cho hai nửa

      // Sao chép dữ liệu sang các mảng tạm
      for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
      for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

      // Trộn hai mảng tạm lại thành mảng arr
      int i = 0, j = 0, k = left;
      while (i < n1 && j < n2)
      {
            if (L[i] <= R[j])
            {
                  arr[k] = L[i];
                  i++;
            }
            else
            {
                  arr[k] = R[j];
                  j++;
            }
            k++;
      }

      // Sao chép các phần tử còn lại của L, nếu có
      while (i < n1)
      {
            arr[k] = L[i];
            i++;
            k++;
      }

      // Sao chép các phần tử còn lại của R, nếu có
      while (j < n2)
      {
            arr[k] = R[j];
            j++;
            k++;
      }
}

void mergeSort(int arr[], int left, int right)
{
      if (left < right)
      {
            int mid = left + (right - left) / 2; // Tìm điểm giữa để chia mảng

            // Gọi đệ quy để chia mảng
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);

            // Gộp hai nửa lại với nhau
            merge(arr, left, mid, right);
      }
}

int main()
{
      int n;
      printf("Nhập số phần tử của mảng: ");
      scanf("%d", &n);

      int arr[n];
      printf("Nhập các phần tử của mảng:\n");
      for (int i = 0; i < n; i++)
      {
            printf("Phần tử %d: ", i + 1);
            scanf("%d", &arr[i]);
      }

      mergeSort(arr, 0, n - 1);

      printf("Mảng sau khi sắp xếp:\n");
      for (int i = 0; i < n; i++)
      {
            printf("%d ", arr[i]);
      }
      printf("\n");

      return 0;
}
