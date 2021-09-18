/**
 * @file graph_dot_stree.hpp
 * @brief 将无权重图中的搜索树转成dot格式，
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-09-18
 */
#ifndef MINI_ALGO_GRAPH_DOT_STREE_INC
#define MINI_ALGO_GRAPH_DOT_STREE_INC

#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include "edge.hpp"

namespace mini_algo {

std::set<int> GetVSet(const std::vector<Edge>& edges)
{
    std::set<int> vset;
    for (auto e: edges) {
        vset.insert(e.v);
        vset.insert(e.w);
    }
    return vset;
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
    auto vset = GetVSet(edges);
    for (auto v: vset) {
        strm << "\t" << v << ";\n";
    }

    // 打印边集
    int index = 0;
    for (auto e: edges) {
        strm << "\t" << e.v << line_symbol << e.w << "[label = " << ++index << "];\n";
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
