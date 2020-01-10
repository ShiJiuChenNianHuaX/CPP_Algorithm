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
void insertSort() {
    const int size = 10;
    int array[size] = {1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    printf("直接插入排序: \n");
    show(array, size);
    int temp; // 哨兵
    for (int i = 1; i < size; ++i) {
        // 比左边的小
        if (array[i] < array[i - 1]) {
            temp = array[i]; // 哨兵位储存小的值
            int j;
            // 向左找所有大于哨兵的值，统统右移，空出一格
            for (j = i - 1; array[j] > temp; j--) {
                array[j + 1] = array[j];
            }
            array[j + 1] = temp; // 将哨兵插入
        }
    }
    show(array, size);
}
int main(int argc, const char * argv[]) {
    insertSort();
    return 0;
}