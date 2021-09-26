/**
 * @file dfs.hpp
 * @brief 深度优先搜索(Depth-first Search, DFS)算法，迭代式版本
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-08-28
 *
 * @see 算法详解（卷2）图算法和数据结构：章节2.4.2
 */
#ifndef MINI_ALGO_GRAPH_DFS_INC
#define MINI_ALGO_GRAPH_DFS_INC

#include <vector>
#include <stack>
#include <algorithm>

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
        std::stack<int> s;
        void Put(int v) { s.push(v); }
        int Get() { int v = s.top(); s.pop(); return v; }
        bool Empty() { return s.empty(); }
    };

public:
    DFS(const Graph& graph): graph_(graph), visited_(graph_.V(), false) {}

    void Explore(int s)
    {
        // S := 一个堆栈数据结构，用s初始化
        Stack S;
        S.Put(s);

        // 只要堆栈不为空，就一直处理
        while (!S.Empty()) {
            // 从S的头部删除("弹出")顶点v
            int v = S.Get();

            // 如果v为未探索
            if (!IsVisited(v)) {
                // 把v标注为已探索
                Visit(v);

                // 遍历v的邻接列表
                for (int w: graph_.AdjList(v)) {
                    // 把w添加("压入")到S的头部
                    S.Put(w);
                }
            }
        }
    }

    virtual bool IsVisited(int v) 
    {
        return visited_[v];
    }

    virtual void Visit(int v) 
    {
        visited_[v] = true;
    }
};

}   // namespace mini_algo

#endif

