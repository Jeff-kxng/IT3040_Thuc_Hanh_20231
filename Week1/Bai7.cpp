/*
 Viết chương trình nhập vào một ma trận 2 chiều kích thước m*n với m và n nhập từ bàn phím. Sau đó đưa ra tổng các phần tử chẵn của ma trận đó.

Lưu ý: Khi viết hàm cấp phát bộ nhớ cho một ma trận hai chiều biểu diễn bởi con trỏ int **mt, nếu ta truyền con trỏ theo kiểu địa chỉ void allocate_mem(int **mt, int m, int n) sẽ dẫn tới việc cấp phát bộ nhớ cho một bản sao của con trỏ **mt. Do đó, sau khi gọi hàm thì con trỏ **mt gốc vẫn không được cấp phát bộ nhớ. Để cấp phát thành công cần truyền con trỏ theo dạng địa chỉ, ví dụ sử dụng con trỏ cấp 3 dạng int ***mt.*/

#include <stdio.h>
#include <stdlib.h>

void allocate_mem(int **arr, int m, int n) {
    *arr = (int *)malloc(m * n * sizeof(int));
}

void input(int *arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i * n + j]);
        }
    }
}

void output(int *arr, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", arr[i * n + j]);
        printf("\n");
    }
}

int process(int *arr, int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i * n + j] % 2 == 0)
                tong += arr[i * n + j];
        }
    }
    return tong;
}

void free_mem(int *arr) {
    free(arr);
}

int main() {
    int m, n, *arr;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);
    allocate_mem(&arr, m, n);
    input(arr, m, n);
    output(arr, m, n);
    printf("The sum of all even elements is %d", process(arr, m, n));
    free_mem(arr);
    return 0;
}
