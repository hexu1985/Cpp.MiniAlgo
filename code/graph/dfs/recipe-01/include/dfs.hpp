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

namespace mini_algo {

/**
 * @brief 深度优先搜索(Depth-first Search，DFS)算法，递归版本
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class DFS {
protected:
    const Graph& G;
    std::vector<bool> visited;

public:
    DFS(const Graph& graph): G(graph), visited(graph.V(), false) {}

    void Explore(int v)
    {
        PreVisit(v);

        // 把v标记为已探索
        Visit(v);

        // 遍历v的邻接列表
        for (int w: G.AdjList(v)) {
            if (!IsVisited(w)) {
                Explore(w);
            }
        }

        PostVisit(v);
    }

    virtual bool IsVisited(int v) 
    {
        return visited[v];
    }

    virtual void Visit(int v) 
    {
        visited[v] = true;
    }

    virtual void PreVisit(int v) 
    {
    }

    virtual void PostVisit(int v) 
    {
    }
};

}   // namespace mini_algo

#endif



