import java.util.*;

public class bai1 {

      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Nhap do dai cua day n = ");
            int n = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                  System.out.printf("a[%d] = ", i);
                  arr[i] = sc.nextInt();
            }
            int sum = 0;
            int count = 0;
            for (int j = 0; j < n; j++) {
                  if (arr[j] > 0) {
                        sum += arr[j];
                        count++;
                  }

            }
            if (count > 0) {
                  double average = (double) sum / count;
                  System.out.printf("Trung binh cong cua day so tren la" + average);
            } else {
                  System.out.println();
                  System.out.println("Khong co so nguyen duong trong day.");
            }

      }
}