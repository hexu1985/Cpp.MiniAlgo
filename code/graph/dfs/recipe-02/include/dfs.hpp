/**
 * @file dfs.hpp
 * @brief  深度优先搜索(Depth-first Search, DFS)算法，递归版本
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-08-31
 *
 * @see 算法概论中文版：章节3.2.1~3.2.2
 * @see 算法详解（卷2）图算法和数据结构：章节2.4.2
 */
#ifndef MINI_ALGO_GRAPH_DFS_INC
#define MINI_ALGO_GRAPH_DFS_INC

#include <vector>
#include <algorithm>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 深度优先搜索(Depth-first Search，DFS)算法，递归版本
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class DFS {
private:
    const Graph& graph_;
    std::vector<bool> visited_;

public:
    DFS(const Graph& graph): graph_(graph), visited_(graph_.V(), false) {}

    void Explore(Edge e)
    {
        PreVisit(e);

        // 把e.w标记为已探索
        Visit(e);

        // 遍历e.w的邻接列表
        for (int t: graph_.AdjList(e.w)) {
            if (!IsVisited(t)) {
                Explore(Edge(e.w,t));
            }
        }

        PostVisit(e);
    }

    virtual bool IsVisited(int v) 
    {
        return visited_[v];
    }

    virtual void Visit(Edge e) 
    {
        visited_[e.w] = true;
    }

    virtual void PreVisit(Edge v) 
    {
    }

    virtual void PostVisit(Edge v) 
    {
    }
};

}   // namespace mini_algo

#endif



