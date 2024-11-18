import java.util.Scanner;

public class Main {
    // Hàm tìm đoạn con có tổng lớn nhất
    public static int maxSubArray(int[] nums) {
        int current_max = nums[0];
        int global_max = nums[0];

        for (int i = 1; i < nums.length; i++) {
            current_max = Math.max(nums[i], current_max + nums[i]);
            System.out.printf("current max[%d]:", i);
            global_max = Math.max(global_max, current_max);
        }

        return global_max;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập số lượng phần tử của mảng
        System.out.print("Nhập số phần tử của mảng: ");
        int n = scanner.nextInt();

        // Tạo mảng có n phần tử
        int[] arr = new int[n];

        // Nhập các phần tử của mảng
        System.out.println("Nhập các phần tử của mảng:");
        for (int i = 0; i < n; i++) {
            System.out.print("Phần tử thứ " + (i + 1) + ": ");
            arr[i] = scanner.nextInt();
        }

        // Gọi hàm maxSubArray để tìm tổng đoạn con lớn nhất
        int result = maxSubArray(arr);

        // In ra kết quả
        System.out.println("Tổng lớn nhất của đoạn con là: " + result);
    }
}
