/**
 * @file insertion_sort.hpp
 * @brief 插入排序算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2021-09-14
 *
 * @see 程序设计基础 原书第3版 9.1节 冒泡排序算法
 *
 */
#ifndef MINI_ALGO_INSERTION_SORT_INC
#define MINI_ALGO_INSERTION_SORT_INC

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
void InsertionSort(T array[], int arraySize)
{
    // 循环计数器
    int index;

    // 用于扫描数组的变量
    int scan;

    // 一个变量用于存储第一个无序的值
    T unsortedValue;

    // 因为元素0的值已经默认有序，
    // 所以外层循环从元素1开始
    // 用index变量提取数组的每个下标
    for (index = 1; index <= arraySize-1; index++) {

        // 有序子集外的第一个元素是array[index]
        // 将此元素的值存储在
        // 变量unsortedValue
        unsortedValue = array[index];

        // 从有序子集外的
        // 第一个元素开始向有序子集扫描
        scan = index;

        // 将有序子集外的第一个元素的值移到
        // 有序子集的有序位置
        while (scan > 0 && array[scan-1] > unsortedValue) {
            array[scan] = array[scan-1];
            scan = scan - 1;
        }

        // 将无序的值插入到有序子集
        // 的有序位置
        array[scan] = unsortedValue;
    }
}

}   // namespace mini_algo

#endif

