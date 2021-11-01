/**
 * @file bfs.hpp
 * @brief 广度优先的搜索(Breadth-first Search, BFS)算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2021-11-1
 *
 * @see 算法详解（卷2）图算法和数据结构：章节2.2.2
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

    struct Queue {
        std::queue<int> q;
        void Put(int v) { q.push(v); }
        int Get() { int v = q.front(); q.pop(); return v; }
        bool Empty() { return q.empty(); }
    };

public:
    BFS(const Graph& graph): G(graph), visited(graph.V(), false) {}

    void Explore(int s)
    {
        // 把s标记为已探索
        Visit(s);

        // Q := 一个队列数据结构，用s进行初始化
        Queue Q;
        Q.Put(s);

        // 只要队列不为空，就一直处理
        while (!Q.Empty()) {
            // 从Q的头部删除一个顶点，称之为v
            int v = Q.Get();

            // 遍历v的邻接列表
            for (int w: G.AdjList(v)) {
                // 如果w为未探索
                if (!IsVisited(w)) {
                    // 把w标记为已探索
                    Visit(w);
                    // 把w添加到Q的尾部
                    Q.Put(w);
                }
            }
        }
    }

    virtual bool IsVisited(int v)
    {
        return visited[v];
    }

    virtual void Visit(int v)
    {
        visited[v] = true;
    }
};

}   // namespace mini_algo

#endif

