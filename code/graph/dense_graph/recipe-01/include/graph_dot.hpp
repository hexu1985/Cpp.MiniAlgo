/**
 * @file graph_dot.hpp
 * @brief 将稠密图转成dot格式
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-05-19
 */
#ifndef MINI_ALGO_GRAPH_DOT_INC
#define MINI_ALGO_GRAPH_DOT_INC

#include <iostream>
#include <string>
#include <sstream>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 将稠密图转成DOT语言格式
 *
 * @param strm 输出流
 * @param graph 指定图
 */
template <typename charT, typename traits, typename Graph>
void WriteDot(std::basic_ostream<charT, traits>& strm, const Graph& graph) 
{
    bool is_digraph = graph.Directed();
    std::string title = is_digraph ? "digraph G" : "graph G";
    std::string line_symbol = is_digraph ? "->" : "--";

    strm << title << " {\n";

    // 打印点集
    for (int v = 0; v < graph.V(); v++) {
        strm << "\t" << v << ";\n";
    }

    // 打印边集
    for (auto e: Edges(graph)) {
        strm << "\t" << e.v << line_symbol << e.w << ";\n";
    }

    strm << "}\n";
}

template <typename Graph>
std::string ToDotStr(const Graph& graph)
{
    std::ostringstream os;
    WriteDot(os, graph);
    return os.str();
}

template <typename Graph>
bool WriteDotFile(const std::string& dot_file_path, const Graph& graph) {
    std::ofstream ofile(dot_file_path, std::ios::out | std::ios::trunc);
    if (!ofile) {
        return false;
    }
    WriteDot(ofile, graph);
    return true;
}

}   // namespace unweight

#endif  // UNWEIGHT_DENSE_GRAPH_DOT_INC
