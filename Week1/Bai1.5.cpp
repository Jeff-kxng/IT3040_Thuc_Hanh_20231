/*
 Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. Nếu mảng rỗng hãy trả về NULL.*/

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
    for (int i = 1; i < size; i++){
        if (a[i] > *max){
            max = &a[i];
        }
    }
    return max;
}