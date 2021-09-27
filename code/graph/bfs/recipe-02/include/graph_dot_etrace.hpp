/**
 * @file graph_dot_etrace.hpp
 * @brief 将无权重图转成dot格式，指定边搜索轨迹
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-05-19
 */
#ifndef MINI_ALGO_GRAPH_DOT_ETRACE_INC
#define MINI_ALGO_GRAPH_DOT_ETRACE_INC

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "edge.hpp"

namespace mini_algo {

bool operator== (const Edge& a, const Edge& b)
{
    return (a.v == b.v && a.w == b.w)
        || (a.v == b.w && a.w == b.v);
}

int FindEdge(const std::vector<Edge>& edges, Edge e)
{
    const auto iter = std::find(edges.begin(), edges.end(), e);
    if (iter == edges.end())
        return -1;
    return iter - edges.begin();
}

/**
 * @brief 将无权重图转成DOT语言格式, 写入指定输出流
 *
 * @param strm 输出流
 * @param graph 指定图
 */
template <typename charT, typename traits, typename Graph>
void WriteDot(std::basic_ostream<charT, traits>& strm, const Graph& graph, const std::vector<Edge>& edges)
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
        int index = FindEdge(edges, e);
        if (index < 0) {
            strm << "\t" << e.v << line_symbol << e.w << ";\n";
        } else {
            strm << "\t" << e.v << line_symbol << e.w << "[label = " << index+1 << ", penwidth=5];\n";
        }
    }

    strm << "}\n";
}

/**
 * @brief 将无权重图转成DOT语言格式字符串
 *
 * @param graph 指定图
 *
 * @return DOT语义格式字符串
 */
template <typename Graph>
std::string ToDotStr(const Graph& graph, const std::vector<Edge>& edges)
{
    std::ostringstream os;
    WriteDot(os, graph, edges);
    return os.str();
}

/**
 * @brief 将无权重图转成DOT语言格式, 写入指定文件
 *
 * @param dot_file_path dot文件路径
 * @param graph 指定图
 *
 * @return 如果写入成功, 返回true, 否则返回false
 */
template <typename Graph>
bool WriteDotFile(const std::string& dot_file_path, const Graph& graph, const std::vector<Edge>& edges) {
    std::ofstream ofile(dot_file_path, std::ios::out | std::ios::trunc);
    if (!ofile) {
        return false;
    }
    WriteDot(ofile, graph, edges);
    return true;
}

}   // namespace unweight

#endif  // UNWEIGHT_DENSE_GRAPH_DOT_INC
