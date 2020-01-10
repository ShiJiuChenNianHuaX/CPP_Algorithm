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
void shellSort() {
    const int size = 10;
    int array[size] = {1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    printf("希尔排序: \n");
    show(array, size);
    int temp; // 哨兵
    int increment = size;
    do {
        increment = increment / 3 + 1;
        for (int i = increment; i < size; ++i) {
            // 跳跃increment格来比较
            if (array[i] < array[i - increment]) {
                temp = array[i];
                int j;
                for (j = i - increment; j > 0 && array[j] > temp; j-=increment) {
                    array[j + increment] = array[j];
                }
                array[j + increment] = temp;
            }
        }
    } while (increment > 1);
    show(array, size);
}
int main(int argc, const char * argv[]) {
    shellSort();
    return 0;
}