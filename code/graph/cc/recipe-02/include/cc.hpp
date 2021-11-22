/**
 * @file cc.hpp
 * @brief 无向图连通分量(Connected Components, CC)算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-08-07
 *
 * @see C++算法：图算法：章节2.5，程序2.4 图的连通性
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
    std::vector<int> id;    // 顶点 -> 连通分量号，序号从0开始，例如id[1]表示为顶点1连通分量号
    int ccnt = 0;           // 连通分量个数

    template <typename T>
    struct Queue {
        std::queue<T> q;
        void Put(T elem) { q.push(elem); }
        T Get() { T elem = q.front(); q.pop(); return elem; }
        bool Empty() { return q.empty(); }
    };

public:
    CC(const Graph& graph): G(graph), id(graph.V(), -1), ccnt(0) {}

    /**
     * @brief Connected Components main function
     */
    void Search()
    {
        for (int v = 0; v < G.V(); v++) {
            if (id[v] == -1) {
                Explore(v);
                ccnt++;
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
        return id;
    }

    /**
     * @brief 返回连通分量个数
     *
     * @return 连通分量个数
     */
    int Count() const
    {
        return ccnt;
    }

private:
    void Explore(int w)
    {
        id[w] = ccnt;

        for (int v: G.AdjList(w)) {
            if (id[v] == -1) {
                Explore(v);
            }
        }
    }
};

}   // namespace mini_algo

#endif

