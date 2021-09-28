/**
 * @file graph_dot_vlabel.hpp
 * @brief 将无权重图打印成dot格式，指定顶点名称
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-05-19
 */
#ifndef MINI_ALGO_GRAPH_DOT_VLABEL_INC
#define MINI_ALGO_GRAPH_DOT_VLABEL_INC

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 将无权重图转成DOT语言格式, 写入指定输出流
 *
 * @param os 输出流
 * @param graph 指定图
 * @param vlabel_map 顶点号到名称映射
 */
template <typename charT, typename traits, typename Graph, typename VLabelMap>
void WriteDot(std::basic_ostream<charT, traits>& os, const Graph& graph, const VLabelMap& vlabel_map)
{
    bool is_digraph = graph.Directed();
    std::string title = is_digraph ? "digraph G" : "graph G";
    std::string line_symbol = is_digraph ? "->" : "--";

    os << title << " {\n";

    // 打印点集
    for (int v = 0; v < graph.V(); v++) {
        os << "\t" << v 
            << " [label = " << vlabel_map[v] << "]" << ";\n";
    }

    // 打印边集
    for (auto e: Edges(graph)) {
        os << "\t" << e.v << line_symbol << e.w << ";\n";
    }

    os << "}\n";
}

/**
 * @brief 将无权重图转成DOT语言格式字符串
 *
 * @param graph 指定图
 * @param vlabel_map 顶点号到名称映射
 *
 * @return DOT语义格式字符串
 */
template <typename Graph, typename VLabelMap>
std::string ToDotStr(const Graph& graph, const VLabelMap& vlabel_map)
{
    std::ostringstream os;
    WriteDot(os, graph, vlabel_map);
    return os.str();
}

/**
 * @brief 将无权重图转成DOT语言格式, 写入指定文件
 *
 * @param dot_file_path dot文件路径
 * @param graph 指定图
 * @param vlabel_map 顶点号到名称映射
 *
 * @return 如果写入成功, 返回true, 否则返回false
 */
template <typename Graph, typename VLabelMap>
bool WriteDotFile(const std::string& dot_file_path, const Graph& graph, const VLabelMap& vlabel_map) {
    std::ofstream ofile(dot_file_path, std::ios::out | std::ios::trunc);
    if (!ofile) {
        return false;
    }
    WriteDot(ofile, graph, vlabel_map);
    return true;
}

}   // namespace unweight

#endif  // UNWEIGHT_DENSE_GRAPH_DOT_INC
