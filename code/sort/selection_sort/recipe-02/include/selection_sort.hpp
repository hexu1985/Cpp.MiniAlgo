/**
 * @file selection_sort.hpp
 * @brief 选择排序算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-03-17
 *
 * @see 程序设计基础 原书第3版 9.2节 选择排序算法
 *
 */
#ifndef MINI_ALGO_SELECTION_SORT_INC
#define MINI_ALGO_SELECTION_SORT_INC

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
void SelectionSort(T array[], int arraySize)
{
    // startScan将存储扫描的起始位置
    int startScan;

    // minIndex将存储
    // 扫描范围内的最小值元素的下标
    int minIndex;

    // minValue将存储
    // 扫描范围内的最小值
    T minValue;

    // index是一个计数器变量，用于存储一个下标
    int index;

    // 外层循环对数组中除最后一个元素之外的
    // 每一个元素都迭代一次。startScan变量
    // 记录这扫描起始位置
    for (startScan = 0; startScan <= arraySize-2; startScan++) {

        // 假定扫描区域中的第一个元素
        // 具有最小值
        minIndex = startScan;
        minValue = array[startScan];

        // 从扫描区域的第2个元素
        // 开始扫描数组
        // 寻找最小值
        for (index = startScan+1; index <= arraySize-1; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }

        // 将具有最小值的元素
        // 与扫描区域中的第一个元素交换
        Swap(array[minIndex], array[startScan]);
    }
}

}   // namespace mini_algo

#endif

