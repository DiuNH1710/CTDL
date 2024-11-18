#include <stdio.h>
#include <math.h>


int main() {
    int a, b, c;

    printf("Nhap he so a (a khac 0): ");
    scanf("%d", &a);
    printf("Nhap he so b: ");
    scanf("%d", &b);
    printf("Nhap he so c: ");
    scanf("%d", &c);

    if (a == 0) {
        printf("He so a phai khac 0.\n");
    } else {
            int delta = b * b - 4 * a * c;

    // Kiểm tra delta
    if (delta < 0) {
        printf("Phuong trinh vo nghiem.\n");
    } else if (delta == 0) {
        double x = -b / (2.0 * a);
        printf("Phuong trinh co nghiem kep: x = %.2f\n", x);
    } else {
        double x1 = (-b + sqrt(delta)) / (2.0 * a);
        double x2 = (-b - sqrt(delta)) / (2.0 * a);
        printf("Phuong trinh co 2 nghiem phan biet: x1 = %.2f, x2 = %.2f\n", x1, x2);
    }
}


    return 0;
}
