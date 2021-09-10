/**
 * @file bubble_sort.hpp
 * @brief 起泡排序算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2021-09-10
 *
 * @see 程序设计基础 原书第3版 9.1节 冒泡排序算法
 *
 */
#ifndef MINI_ALGO_BUBBLE_SORT_INC
#define MINI_ALGO_BUBBLE_SORT_INC

#include <vector>

namespace mini_algo {

template <typename T>
void Swap(T& a, T& b)
{
    // 临时存储的局部变量
    T temp;

    // 交换a和b中的值
    temp = a;
    a = b;
    b = temp;
}

/**
 * @brief 选择排序指定数组
 *
 * @param array[] 数组首地址
 * @param arraySize 数组元素格式
 */
template <typename T>
void BubbleSort(T array[], int arraySize)
{
    // maxElement变量将包含
    // 参与比较的数组中最后一个元素的下标
    int maxElement;

    // index变量将用于
    // 内层循环的计数器
    int index;

    // 外层循环将maxElement的值设为
    // 在一趟起泡中进行比较的最后一个元素的下标
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

#endif

