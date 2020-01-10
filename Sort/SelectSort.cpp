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
void selectSort() {
    const int size = 10;
    int array[size] = {1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    printf("简单选择排序: \n");
    show(array, size);
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[min] > array[j]) {
                min = j;
            }
        }
        if (min != i) {
            swap(array[min], array[i]);
        }
    }
    show(array, size);
}
int main(int argc, const char * argv[]) {
    selectSort();
    return 0;
}