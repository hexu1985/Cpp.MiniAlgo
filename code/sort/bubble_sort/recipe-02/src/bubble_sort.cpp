#include "bubble_sort.hpp"

namespace {

void Swap(int& a, int& b)
{
    // 临时存储的局部变量
    int temp;

    // 交换a和b中的值
    temp = a;
    a = b;
    b = temp;
}

}   // namespace

namespace mini_algo {

/**
 * @brief 选择排序指定数组
 *
 * @param array[] 数组首地址
 * @param arraySize 数组元素格式
 */
void BubbleSort(int array[], int arraySize)
{
    // maxElement变量将包含
    // 参与比较的数组中最后一个元素的下标
    int maxElement;

    // index变量将用于
    // 内层循环的计数器
    int index;

    // 外层循环将maxElement的值设为
    // 在一趟冒泡中进行比较的最后一个元素的下标
    // maxElement的初始值是数组最后一个元素的下标
    // 每次迭代之后，
    // 它的值都减1
    for (maxElement = arraySize-1; maxElement >= 0; maxElement--) {

        // 内层循环遍历数组，将
        // 每个元素与其相邻元素比较
        // 下标从0到maxElement的元素
        // 都进行比较。如果两个元素
        // 的值无序，则交换
        for (index = 0; index <= maxElement-1; index++) {

            // 将一元素与其相邻元素比较
            // 如有必要，则交换它们的值
            if (array[index] > array[index+1]) {
                Swap(array[index], array[index+1]);
            }
        }
    }
}

}   // namespace mini_algo

