#include <stdio.h>



void quayLui(int n, char x[], int index) {
    // Điều kiện dừng: Nếu index đã bằng n thì in ra xâu nhị phân
    if (index == n) {
        x[n] = '\0'; // Kết thúc chuỗi xâu nhị phân
        printf("%s\n", x);
        return;
    }

    // Gán '0' tại vị trí index và gọi đệ quy tiếp theo
    x[index] = '0';
    quayLui(n, x, index + 1);

    // Gán '1' tại vị trí index và gọi đệ quy tiếp theo
    x[index] = '1';
    quayLui(n, x, index + 1);
}

int main() {
    int n;
    printf("Nhap do dai xau nhi phan n: ");
    scanf("%d", &n);

    // Khai báo mảng ký tự để chứa xâu nhị phân
    char x[100];  // MAX_LEN là kích thước tối đa của chuỗi

    // Bắt đầu liệt kê các xâu nhị phân
    quayLui(n, x, 0);

    return 0;
}
