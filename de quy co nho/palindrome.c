#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palindrome(char str[], int start, int end)
{
      if (start >= end)
      {
            return 1;
      }
      else
      {
            if (str[start] == str[end])
            {
                  return palindrome(str, start + 1, end - 1);
            }
            else
                  return -1;
      }
}

int main()
{
      char str[100];

      printf("Nhập chuỗi: ");
      fgets(str, sizeof(str), stdin);

      str[strcspn(str, "\n")] = '\0';

      int length = strlen(str);

      int ans = palindrome(str, 0, length - 1);
      if (ans == 1)
      {
            printf("Chuoi la chuoi palindrome");
      }
      else
      {
            printf("Chuoi khong phai la chuoi palindrome ");
      }

      return 0;
}