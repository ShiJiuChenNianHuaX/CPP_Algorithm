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
void heapSort() {
    const int size = 11;
    // 0号节点弃用，因为完全二叉树的计算使用1下标为根节点更易于计算
    int array[size] = {0, 1, 3, 2, 10, 6, 4, 7, 5, 8, 9};
    printf("堆排序: \n");
    show(array, size, 1);
    
    auto adjust = [&](int (&array)[size], int s, int m) {
        int temp = array[s];
        // 从s开始，乘2操作表示移动到左孩子节点
        for (int j = 2 * s; j <= m; j *= 2) {
            // 左右孩子节点比较，选中较大的节点
            if (j < m && array[j] < array[j + 1]) {
                ++j;
            }
            // 如果父节点比左右孩子节点都大，则无需操作
            if (temp >= array[j]) {
                break;
            }
            // 否则父节点和子节点换位置
            array[s] = array[j];
            s = j;
        }
        array[s] = temp;
    };
    int length = size - 1;
    // 从length / 2 开始，即遍历所有非叶子节点
    // 所有非叶子节点调整完后，堆定肯定是最大元素了
    for (int i = length / 2; i > 0; --i) {
        adjust(array, i, length);
    }
    for (int i = length; i > 1; i--) {
        // 将堆顶和最后一个元素交换，在重新调整大根堆
        swap(array[1], array[i]);
        adjust(array, 1, i - 1);
    }
    show(array, size, 1);
}
int main(int argc, const char * argv[]) {
    heapSort();
    return 0;
}