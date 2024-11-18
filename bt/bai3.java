// Tím giá trị lớn nhất của dãy n số nguyên a1, a2, ..., an. Và cho biết có bao nhiêu số trong dãy có giá trị lớn nhất này. 

import java.util.*;

public class bai3 {
      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Nhap do dai cua day n = ");
            int n = sc.nextInt();

            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                  System.out.printf("Nhap gia tri a[%d]: ", i);
                  arr[i] = sc.nextInt();
            }

            int countMax = 1;
            int maxValue = arr[0];
            for (int j = 1; j < n; j++) {
                  if (arr[j] > maxValue) {
                        maxValue = arr[j];
                        countMax = 1;
                  } else if (arr[j] == maxValue) {
                        countMax++;
                  }
            }

            System.out.println("Gia tri lon nhat trong day la: " + maxValue);
            System.out.println("So luong phan tu co gia tri lon nhat la: " + countMax);
      }
}