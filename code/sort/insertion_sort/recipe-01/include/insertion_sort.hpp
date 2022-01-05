/**
 * @file insertion_sort.hpp
 * @brief 插入排序算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2021-06-07
 *
 * @see Data Structures with C++ Using STL, Chapter 4.4 \n
 * https://github.com/hexu1985/Data.Structures.With.Cpp.Using.STL
 *
 */
#ifndef MINI_ALGO_INSERTION_SORT_INC
#define MINI_ALGO_INSERTION_SORT_INC

#include <vector>

namespace mini_algo {

/**
 * @brief 插入排序指定数组
 *
 * @tparam T    数组元素类型
 * @param arr[] 数组首地址
 * @param n     数组元素格式
 */
template <typename T>
void InsertionSort(T arr[], int n)
{
    int i, j;
    T target;

    // place arr[i] into the sublist
    //   arr[0] ... arr[i-1], 1 <= i < n,
    // so it is in the correct position
    for (i = 1; i < n; i++)
    {
        // index j scans down list from arr[i] looking for
        // correct position to locate target. assigns it to
        // arr[j]
        j = i;
        target = arr[i];
        // locate insertion point by scanning downward as long
        // as target < arr[j-1] and we have not encountered the
        // beginning of the list
        while (j > 0 && target < arr[j-1])
        {
            // shift elements up list to make room for insertion
            arr[j] = arr[j-1];
            j--;
        }
        // the location is found; insert target
        arr[j] = target;
    }
}

}   // namespace mini_algo

#endif

