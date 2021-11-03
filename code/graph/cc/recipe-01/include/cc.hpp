/**
 * @file cc.hpp
 * @brief 无向图连通分量(Connected Components, CC)算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-08-07
 *
 * @see 算法详解（卷2）图算法和数据结构：章节2.3.3
 */
#ifndef MINI_ALGO_CC_INC
#define MINI_ALGO_CC_INC

#include <vector>
#include <queue>
#include <algorithm>

namespace mini_algo {

/**
 * @brief 无向图连通分量(Connected Components, CC)算法
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class CC {
private:
    const Graph& G;
    std::vector<bool> visited;
    std::vector<int> cc;    // 顶点 -> 连通分量号，序号从0开始，例如cc[1]表示为顶点1连通分量号
    int num_cc = 0;         // 连通分量个数

    template <typename T>
    struct Queue {
        std::queue<T> q;
        void Put(T elem) { q.push(elem); }
        T Get() { T elem = q.front(); q.pop(); return elem; }
        bool Empty() { return q.empty(); }
    };

public:
    CC(const Graph& graph): G(graph), visited(graph.V(), false), cc(graph.V(), -1), num_cc(0) {}

    /**
     * @brief Connected Components main function
     */
    void Search()
    {
        for (int v = 0; v < G.V(); v++) {
            if (!visited[v]) {
                Explore(v);
                num_cc = num_cc+1;
            }
        }
    }

    /**
     * @brief 返回顶点的连通分量索引数组
     *
     * @return 顶点索引数组，数组下标为顶点，值为在连通分量的序号
     */
    std::vector<int> Index() const
    {
        return cc;
    }

    /**
     * @brief 返回连通分量个数
     *
     * @return 连通分量个数
     */
    int Count() const
    {
        return num_cc;
    }

private:
    void Explore(int v)
    {
        // 把v标记为已探索
        visited[v] = true;

        // Q := 一个队列数据结构，用v进行初始化
        Queue<int> Q;
        Q.Put(v);

        // 只要队列不为空，就一直处理
        while (!Q.Empty()) {
            // 从Q的头部删除一个顶点，称之为v
            int v = Q.Get();
            cc[v] = num_cc;

            // 遍历v的邻接列表
            for (int w: G.AdjList(v)) {
                // 如果w为未探索
                if (!visited[w]) {
                    // 把w标记为已探索
                    visited[w] = true;
                    // 把w添加到Q的尾部
                    Q.Put(w);
                }
            }
        }
    }
};

}   // namespace mini_algo

#endif

