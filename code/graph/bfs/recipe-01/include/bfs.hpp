/**
 * @file bfs.hpp
 * @brief 宽度优先的搜索(Breadth-first Search, BFS)算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-07-24
 *
 * @see C++算法：图算法：章节2.7
 */
#ifndef MINI_ALGO_GRAPH_BFS_INC
#define MINI_ALGO_GRAPH_BFS_INC

#include <vector>
#include <queue>
#include <algorithm>

namespace mini_algo {

/**
 * @brief 宽度优先的搜索(Breadth-first Search, BFS)算法
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class BFS {
private:
    const Graph& graph_;
    std::vector<bool> visited_;

    struct Queue {
        std::queue<int> q;
        void Put(int v) { q.push(v); }
        int Get() { int v = q.front(); q.pop(); return v; }
        bool Empty() { return q.empty(); }
    };

public:
    BFS(const Graph& graph): graph_(graph), visited_(graph_.V(), false) {}

    void Explore(int s)
    {
        // Q := 一个队列数据结构，用s进行初始化
        Queue Q;
        Q.Put(s);

        // 只要队列不为空，就一直处理
        while (!Q.Empty()) {
            // 从Q的头部删除一个顶点，称之为v
            int v = Q.Get();

            // 如果v为未探索
            if (!IsVisited(v)) {
                // 把v标注为已探索
                Visit(v);

                // 遍历v的邻接列表
                for (int w: graph_.AdjList(v)) {
                    // 把w添加到Q的尾部
                    Q.Put(w);
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

