/**
 * @file graph_print.hpp
 * @brief 打印无权重图
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-05-19
 */
#ifndef MINI_ALGO_GRAPH_PRINT_INC
#define MINI_ALGO_GRAPH_PRINT_INC

#include <cmath>
#include <iostream>
#include <iomanip>

namespace mini_algo {

/**
 * @brief 打印无权重图
 *
 * @param os 输出流
 * @param graph 无权重图
 *
 * @return 输出流
 */
template <typename charT, typename traits, typename Graph>
void Print(std::basic_ostream<charT, traits>& os, const Graph& graph)
{
    int width = static_cast<int>(log10(graph.V()))+1;
    for (int v = 0; v < graph.V(); v++) {
        os << std::setw(width) << v << ": ";
        for (auto w: graph.AdjList(v)) {
            os << w << ", ";
        }
        os << std::endl;
    }
}

/**
 * @brief 无权重图的输出运算符重载
 *
 * @param os 输出流
 * @param graph 无权重图
 *
 * @return 输出流
 */
template <typename charT, typename traits, typename Graph>
std::basic_ostream<charT, traits>& operator<< (std::basic_ostream<charT, traits>& os, const Graph& graph)
{
    Print(os, graph);
    return os;
}

}   // namespace unweight

#endif  // UNWEIGHT_DENSE_GRAPH_IO_INC
