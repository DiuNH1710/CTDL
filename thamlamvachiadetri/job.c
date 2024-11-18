#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Cấu trúc lưu trữ thông tin công việc
typedef struct
{
      int deadline;
      int profit;
} Job;

// Hàm so sánh để sắp xếp công việc theo lợi nhuận giảm dần
int compare(const void *a, const void *b)
{
      Job *jobA = (Job *)a;
      Job *jobB = (Job *)b;
      return jobB->profit - jobA->profit;
}

// Hàm chính để tính tổng lợi nhuận tối đa
int maxProfit(Job jobs[], int n)
{
      // Sắp xếp công việc theo lợi nhuận giảm dần
      qsort(jobs, n, sizeof(Job), compare);

      // Tìm deadline lớn nhất để tạo mảng thời gian
      int maxDeadline = 0;
      for (int i = 0; i < n; i++)
      {
            if (jobs[i].deadline > maxDeadline)
            {
                  maxDeadline = jobs[i].deadline;
            }
      }

      // Mảng đánh dấu các khoảng thời gian đã được sử dụng
      int slots[MAX] = {0};

      int totalProfit = 0;

      // Duyệt qua các công việc đã sắp xếp
      for (int i = 0; i < n; i++)
      {
            // Tìm khoảng thời gian trống gần nhất trước hoặc bằng deadline
            for (int j = jobs[i].deadline; j > 0; j--)
            {
                  if (slots[j] == 0)
                  {                   // Nếu khoảng thời gian chưa được dùng
                        slots[j] = 1; // Đánh dấu đã sử dụng
                        totalProfit += jobs[i].profit;
                        break;
                  }
            }
      }

      return totalProfit;
}

int main()
{
      int n;
      scanf("%d", &n);

      Job jobs[MAX];

      // Đọc dữ liệu cho mỗi công việc
      for (int i = 0; i < n; i++)
      {
            scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
      }

      // Tính và in ra tổng lợi nhuận tối đa
      int result = maxProfit(jobs, n);
      printf("%d\n", result);

      return 0;
}
