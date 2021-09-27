/**
 * @file dfs.hpp
 * @brief 深度优先搜索(Depth-first Search, DFS)算法，迭代式版本
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-09-23
 *
 * @see 算法详解（卷2）图算法和数据结构：章节2.4.2
 */
#ifndef MINI_ALGO_GRAPH_DFS_INC
#define MINI_ALGO_GRAPH_DFS_INC

#include <vector>
#include <stack>
#include <algorithm>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 深度优先搜索(Depth-first Search, DFS)算法，迭代式版本
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class DFS {
private:
    const Graph& graph_;
    std::vector<bool> visited_;

    struct Stack {
        std::stack<Edge> s;
        void Put(Edge e) { s.push(e); }
        Edge Get() { Edge e = s.top(); s.pop(); return e; }
        bool Empty() { return s.empty(); }
    };

public:
    DFS(const Graph& graph): graph_(graph), visited_(graph_.V(), false) {}

    void Explore(Edge e)
    {
        // S := 一个堆栈数据结构，用e初始化
        Stack S;
        S.Put(e);

        // 只要堆栈不为空，就一直处理
        while (!S.Empty()) {
            // 从S的头部删除("弹出")边e
            e = S.Get();

            // 如果e.w为未探索
            if (!IsVisited(e.w)) {
                // 把e.w标注为已探索
                Visit(e);

                // 遍历e.w的邻接列表
                for (int t: graph_.AdjList(e.w)) {
                    // 把Edge(e.w, t)添加("压入")到S的头部
                    S.Put(Edge(e.w, t));
                }
            }
        }
    }

    virtual bool IsVisited(int v) 
    {
        return visited_[v];
    }

    virtual void Visit(Edge e) 
    {
        visited_[e.w] = true;
    }
};

}   // namespace mini_algo

#endif

