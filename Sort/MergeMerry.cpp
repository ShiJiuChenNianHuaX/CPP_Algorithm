#include <iostream>

// 输出排序后的结果
void show(int *array, int size, int start = 0) {
    for (int i = start; i < size; ++i) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

// 交换两个元素
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}
void mergeArray(int array[], int first, int mid, int last, int temp[]) {
    // 将两个有序数列a[first...mid]和a[mid...last]合并。
    int i = first;
    int j = mid + 1;
    int m = mid;
    int n = last;
    int k = 0;
    // 如果i < mid + 1，将较小的放入temp，i右移
    // 如果i > mid + 1，将较小的放入temp，mid + 1右移
    while (i <= m && j <= n) {
        if (array[i] <= array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    // 处理剩余的array[i .. m]，填充到temp末尾
    while (i <= m) {
        temp[k++] = array[i++];
    }
    
    // 处理剩余的array[j .. n]，填充到temp末尾
    while (j <= n) {
        temp[k++] = array[j++];
    }
    
    // 让array = temp
    for (i = 0; i < k; i++) {
        array[first + i] = temp[i];
    }
}

void mergeSortRecursive(int array[], int first, int last, int temp[]) {
    if (first < last) {
        int mid = (first + last) / 2;
        mergeSortRecursive(array, first, mid, temp);    //左边有序
        mergeSortRecursive(array, mid + 1, last, temp); //右边有序
        mergeArray(array, first, mid, last, temp); // 再将二个有序数列合并
    }
}

void mergeSort() {
    const int size = 10;
    int array[size] = {1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    int temp[size];
    printf("归并排序: \n");
    show(array, size);
    mergeSortRecursive(array, 0, size - 1, temp);
    show(temp, size);
}
int main(int argc, const char * argv[]) {
    mergeSort();
    return 0;
}