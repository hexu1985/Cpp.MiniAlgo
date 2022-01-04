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

    // 将arr[i]放到子表arr[0] ... arr[i-1], 1 <= i < n中,
    // 使之处于正确的位置
    for (i = 1; i < n; i++)
    {
        // 下标j从arr[i]向下扫描表, 查找放置target的正确位置. 将它赋值给arr[j]
        j = i;
        target = arr[i];
        // 只要target < arr[j-1], 而且没有遇到表的开始, 就通过向下扫描定位插入点
        while (j > 0 && target < arr[j-1])
        {
            // 将元素在表中向上移动, 留出插入的空间
            arr[j] = arr[j-1];
            j--;
        }
        // 找到位置; 插入目标
        arr[j] = target;
    }
}

/**
 * @brief 选择排序指定向量
 *
 * @tparam T 向量元素类型
 * @param v  向量引用
 */
template <typename T>
void InsertionSort(std::vector<T>& v)
{
    int i, j, n = v.size();
    T target;

    // 将v[i]放到子表v[0] ... v[i-1], 1 <= i < n中,
    // 使之处于正确的位置
    for (i = 1; i < n; i++)
    {
        // 下标j从v[i]向下扫描表, 查找放置target的正确位置. 将它赋值给v[j]
        j = i;
        target = v[i];
        // 只要target < v[j-1], 而且没有遇到表的开始, 就通过向下扫描定位插入点
        while (j > 0 && target < v[j-1])
        {
            // 将元素在表中向上移动, 留出插入的空间
            v[j] = v[j-1];
            j--;
        }
        // 找到位置; 插入目标
        v[j] = target;
    }
}

}   // namespace mini_algo

#endif

