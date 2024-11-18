public class tinhGiaiThua {
      public static int factorial(int n) {
            if (n == 0) {
                  return 1;
            } else {
                  return n * factorial(n - 1);
            }
      }

      public static void main(String[] args) {
            int n = 10;
            System.out.println("Giai thua cua " + n + " la: " + factorial(n));
      }
}