#include <stdio.h>

void hanoi(int n, char source, char auxiliary, char target)
{
      if (n == 1)
      {
            printf("Di chuyen dia 1 tu %c den %c\n", source, target);
            return;
      }
      hanoi(n - 1, source, target, auxiliary);
      printf("Di chuyen dia %d tu %c den %c\n", n, source, target);
      hanoi(n - 1, auxiliary, source, target);
}

int main()
{
      int soDia;
      printf("Nhap so dia: ");
      scanf("%d", &soDia);

      printf("Cac buoc de chuyen %d dia tu A den C:\n", soDia);
      hanoi(soDia, 'A', 'B', 'C');

      return 0;
}
