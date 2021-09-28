/**
 * @file graph_print_vlabel.hpp
 * @brief 打印无权重图，指定顶点名称
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
 * @param vlabel_map 顶点号到名称映射
 * @param width 对齐宽度
 *
 * @return 输出流
 */
template <typename charT, typename traits, typename Graph, typename VLabelMap>
void Print(std::basic_ostream<charT, traits>& os, const Graph& graph, const VLabelMap& vlabel_map, int width=1)
{
    for (int v = 0; v < graph.V(); v++) {
        os << std::setw(width) << vlabel_map[v] << ": ";
        for (auto w: graph.AdjList(v)) {
            os << vlabel_map[w] << ", ";
        }
        os << std::endl;
    }
}

}   // namespace unweight

#endif  // UNWEIGHT_DENSE_GRAPH_IO_INC
