/**
 * @file edge.hpp
 * @brief 图算法, 无权重边的表示
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-06-24
 *
 * @see C++算法: 图算法(第3版): 章节1.2
 */
#ifndef MINI_ALGO_EDGE_INC
#define MINI_ALGO_EDGE_INC

#include <vector>

namespace mini_algo {

/**
 * @brief 边类型
 */
struct Edge {
    int v, w;
    Edge(int v, int w): v(v), w(w) {}
};

/**
 * @brief 获取指定图的边集
 *
 * @param graph 指定图
 *
 * @return 边集
 */
template <typename Graph>
std::vector<Edge> Edges(const Graph& graph)
{
    std::vector<Edge> edges;
    for (int v = 0; v < graph.V(); v++) {
        for (auto w: graph.AdjList(v)) {
            if (graph.Directed() || v < w) {
                edges.push_back(Edge(v, w));
            }
        }
    }

    return edges;
}

}   // namespace mini_algo

#endif
