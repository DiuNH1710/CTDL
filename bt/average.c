#include <stdio.h>

int main() {
    int n, i;
    int sum = 0, count = 0;
    
    // Nhập số lượng phần tử n
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    int arr[n];
    
    // Nhập dãy các số
    printf("Nhap %d so nguyen:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Kiểm tra nếu số nhập vào là số nguyên dương
        if (arr[i] > 0) {
            sum += arr[i];  // Cộng các số nguyên dương
            count++;        // Đếm số lượng số nguyên dương
        }
    }
    
    // Kiểm tra có số nguyên dương nào không
    if (count > 0) {
        double average = (double)sum / count;
        printf("Trung binh cong cua cac so nguyen duong: %.2f\n", average);
    } else {
        printf("Khong co so nguyen duong trong day.\n");
    }

    return 0;
}
