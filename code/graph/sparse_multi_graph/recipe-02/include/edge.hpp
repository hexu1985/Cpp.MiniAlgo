/**
 * @file edge.hpp
 * @brief 
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-07-09
 *
 * @see C++算法: 图算法(第3版): 章节4.1
 */
#ifndef MINI_ALGO_EDGE_INC
#define MINI_ALGO_EDGE_INC

#include <vector>

namespace mini_algo {

/**
 * @brief 边类型
 */
struct Edge {
    int v = -1;
    int w = -1;
    double wt = 1;

    Edge(int v_, int w_, double weight = 1): v(v_), w(w_), wt(weight) {}

    /**
     * @brief 测试顶点是否为from顶点
     *
     * @param v_ 顶点索引
     *
     * @return 如果v_为v顶点, 则返回true, 否则返回false
     */
    bool From(int v_) { return v_ == v; }

    /**
     * @brief 给定边的一个顶点, 返回另外一端顶点的索引
     *
     * @param v_ 给定的顶点
     *
     * @return 另外一端顶点的索引
     */
    int Other(int v_)
    {
        return From(v_) ? w : v;
    }
};

/**
 * @brief 获取指定图的边集
 *
 * @param graph 指定图
 *
 * @return 边集
 */
template <typename Graph>
std::vector<Edge*> Edges(const Graph& graph)
{
    std::vector<Edge*> edges;
    for (int v = 0; v < graph.V(); v++) {
        for (auto e: graph.AdjList(v)) {
            if (e->From(v)) {
                edges.push_back(e);
            }
        }
    }

    return edges;
}

}   // namespace mini_algo

#endif
