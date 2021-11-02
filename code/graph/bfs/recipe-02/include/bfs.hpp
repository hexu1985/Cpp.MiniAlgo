/**
 * @file bfs.hpp
 * @brief 广度优先的搜索(Breadth-first Search, BFS)算法
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
protected:
    const Graph& G;
    std::vector<bool> visited;

    template <typename T>
    struct Queue {
        std::queue<T> q;
        void Put(T elem) { q.push(elem); }
        T Get() { T elem = q.front(); q.pop(); return elem; }
        bool Empty() { return q.empty(); }
    };

public:
    BFS(const Graph& graph): G(graph), visited(graph.V(), false) {}

    void Explore(Edge e)
    {
        // Q := 一个队列数据结构，用e进行初始化
        Queue<Edge> Q;
        Q.Put(e);

        // 只要队列不为空，就一直处理
        while (!Q.Empty()) {
            // 从Q的头部删除一个顶点，称之为v
            e = Q.Get();

            // 如果e.w为未探索
            if (!IsVisited(e.w)) {
                // 把e.w标注为已探索
                Visit(e);

                // 遍历e.w的邻接列表
                for (int t: G.AdjList(e.w)) {
                    // 如果t为未探索
                    if (!IsVisited(t)) { 
                        // 把Edge(e.w, t)添加到Q的尾部
                        Q.Put(Edge(e.w, t));
                    }
                }
            }
        }
    }

    virtual bool IsVisited(int v)
    {
        return visited[v];
    }

    virtual void Visit(Edge e)
    {
        visited[e.w] = true;
    }
};

}   // namespace mini_algo

#endif

