#include <iostream>
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
void bubblingSort() {
    const int size = 10;
    int array[size] = {1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    printf("冒泡排序: \n");
    show(array, size);
    for (int i = 0; i < size; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (array[j] < array[j - 1]) {
                swap(array[j], array[j - 1]);
            }
        }
    }
    show(array, size);
}
int main(int argc, const char * argv[]) {
    bubblingSort();
    return 0;
}