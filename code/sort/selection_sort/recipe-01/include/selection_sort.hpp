/**
 * @file selection_sort.hpp
 * @brief 选择排序算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-03-17
 *
 * @see Data Structures with C++ Using STL, Chapter 3.1 \n
 * https://github.com/hexu1985/Data.Structures.With.Cpp.Using.STL
 *
 */
#ifndef MINI_ALGO_SELECTION_SORT_INC
#define MINI_ALGO_SELECTION_SORT_INC

#include <vector>

namespace mini_algo {

/**
 * @brief 选择排序指定数组
 *
 * @tparam T    数组元素类型
 * @param arr[] 数组首地址
 * @param n     数组元素格式
 */
template <typename T>
void SelectionSort(T arr[], int n)
{
    int smallIndex; // 子表中最小元素的下标
    int pass, j;
    T temp;

    // pass的范围是0 ~ n-2
    for (pass = 0; pass < n-1; pass++)
    {
        // 从下标pass开始扫描子表
        smallIndex = pass;

        // j遍历子表arr[pass+1]到arr[n-1]
        for (j = pass+1; j < n; j++) {
            // 如果找到更小的元素, 则将smallIndex赋值给该位置
            if (arr[j] < arr[smallIndex]) {
                smallIndex = j;
            }
        }

        // 如果smallIndex和pass不在相同的位置,
        // 将子表中的最小项与arr[pass]交换
        if (smallIndex != pass)
        {
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        }
    }
}

/**
 * @brief 选择排序指定向量
 *
 * @tparam T 向量元素类型
 * @param v  向量引用
 */
template <typename T>
void SelectionSort(std::vector<T>& v)
{
    int smallIndex; // 子表中最小元素的下标
    int pass, j, n = v.size();
    T temp;

    // pass的范围是0 ~ n-2
    for (pass = 0; pass < n-1; pass++) {
        // 从下标pass开始扫描子表
        smallIndex = pass;

        // j遍历子表v[pass+1]到v[n-1]
        for (j = pass+1; j < n; j++) {
            // 如果找到更小的元素, 则将smallIndex赋值给该位置
            if (v[j] < v[smallIndex]) {
                smallIndex = j;
            }
        }

        // 如果smallIndex和pass不在相同的位置,
        // 将子表中的最小项与arr[pass]交换
        if (smallIndex != pass) {
            temp = v[pass];
            v[pass] = v[smallIndex];
            v[smallIndex] = temp;
        }
    }
}

}   // namespace mini_algo

#endif

