/**
 * @file graph_io.hpp
 * @brief 权重图的输入输出运算符重载
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-05-19
 */
#ifndef MINI_ALGO_GRAPH_IO_INC
#define MINI_ALGO_GRAPH_IO_INC

#include <cmath>
#include <iostream>
#include <iomanip>

namespace mini_algo {

/**
 * @brief 权重图的输出运算符重载
 *
 * @param strm 输出流
 * @param graph 权重图
 *
 * @return 输出流
 */
template <typename charT, typename traits, typename Graph>
std::basic_ostream<charT, traits>& operator<< (std::basic_ostream<charT, traits>& strm, const Graph& graph)
{
    int width = static_cast<int>(log10(graph.V()))+1;
    for (int v = 0; v < graph.V(); v++) {
        strm << std::setw(width) << v << ": ";
        for (auto e: graph.AdjList(v)) {
            strm << e->Other(v) << "(" << e->wt << "), ";
        }
        strm << std::endl;
    }
    return strm;
}

}   // namespace unweight

#endif  // UNWEIGHT_DENSE_GRAPH_IO_INC
