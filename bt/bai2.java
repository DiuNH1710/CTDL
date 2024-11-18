//Nhập số nguyên d > 0, hãy tính diện tích của hình vuông, hình tam giác đều và hình tròn có chu vi bằng d.

import java.util.*;

public class bai2 {

      public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Nhap chu vi d");
            int d = sc.nextInt();

            if (d <= 0) {
                  System.out.println("Nhap chu vi d > 0");
            } else {

                  // Dien tich hinh vuong
                  double dienTichHinhVuong = Math.pow((double) d / 4, 2);
                  System.out.println("Dien tich hinh vuong la: " + dienTichHinhVuong);

                  // Dien tich hinh tam giac
                  double dienTichHinhTamGiac = (Math.sqrt(3) / 4) * Math.pow((double) d / 3, 2);
                  System.out.println("Dien tich hinh tam giac la: " + dienTichHinhTamGiac);

                  // Tính diện tích hình tròn
                  double dientTichHinhTron = Math.PI * Math.pow(d / (2 * Math.PI), 2);
                  System.out.println("Dien tich hinh tron la: " + dientTichHinhTron);
            }
      }

}
