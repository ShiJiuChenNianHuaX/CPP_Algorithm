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
void quickSortRecursive(int (&array)[10], int left, int right) {
    if (left > right) {
        return;
    }
    int temp = array[left]; // 基准数
    int i = left;
    int j = right;
    while (i != j) {
        // 从右边开始找比基准数小的
        while (array[j] >= temp && i < j) {
            --j;
        }
        // 然后从左边开始找比基准数小的
        while (array[i] <= temp && i < j) {
            ++i;
        }
        if (i < j) {
            swap(array[i], array[j]);
        }
    }
    // 碰头后，与基准数交换
    swap(array[left], array[i]);
    
    // 递归处理左边的
    quickSortRecursive(array, left, i - 1);
    // 递归处理右边的
    quickSortRecursive(array, i + 1, right);
}
void quickSort() {
    const int size = 10;
    int array[size] = {1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    printf("快速排序: \n");
    show(array, size);
    quickSortRecursive(array, 0, size - 1);
    show(array, size);
}
int main(int argc, const char * argv[]) {
    quickSort();
    return 0;
}