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
    int smallIndex; // index of smallest element in the sublist
    int pass, j;
    T temp;

    // pass has the range 0 to n-2
    for (pass = 0; pass < n-1; pass++)
    {
        // scan the sublist starting at index pass
        smallIndex = pass;

        // j traverses the sublist arr[pass+1] to arr[n-1]
        for (j = pass+1; j < n; j++)
            // update if smaller element found
            if (arr[j] < arr[smallIndex])
                smallIndex = j;

        // if smallIndex and pass are not the same location,
        // exchange the smallest item in the sublist with arr[pass]
        if (smallIndex != pass)
        {
            temp = arr[pass];
            arr[pass] = arr[smallIndex];
            arr[smallIndex] = temp;
        }
    }
}

}   // namespace mini_algo

#endif

