/**
 * @file ts.hpp
 * @brief 有向图拓扑排序算法，Topo-Sort
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-09-03
 *
 * @see C++算法：图算法：章节3.6，程序3.8 基于源点队列的拓扑排序
 */
#ifndef MINI_ALGO_TS_INC
#define MINI_ALGO_TS_INC

#include <vector>
#include <queue>
#include <algorithm>

namespace mini_algo {

/**
 * @brief 有向图拓扑排序算法
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class TS {
protected:
    const Graph& G;
    std::vector<int> in;    // 每个顶点的入度
    std::vector<int> ts;    // 按照拓扑顺序重排的顶点
    std::vector<int> tsI;   // 顶点 -> 次序，次序值从0开始，例如tsI[1]表示为顶点1在拓扑排序中的次序

    template <typename T>
    struct Queue {
        std::queue<T> q;
        void Put(T elem) { q.push(elem); }
        T Get() { T elem = q.front(); q.pop(); return elem; }
        bool Empty() { return q.empty(); }
    };

public:
    TS(const Graph& graph): G(graph), in(graph.V(), 0), ts(graph.V(), -1), tsI(graph.V(), -1) {}

    /**
     * @brief Topo-Sort main function
     */
    void Search()
    {
        Queue<int> Q;
        for (int v = 0; v < G.V(); v++) {   // 计算所有点的入度
            for (auto t: G.AdjList(v)) {
                in[t]++;
            }
        }
        for (int v = 0; v < G.V(); v++) {
            if (in[v] == 0) Q.Put(v);
        }
        for (int j = 0; !Q.Empty(); j++) {
            ts[j] = Q.Get(); tsI[ts[j]] = j;
            for (auto t: G.AdjList(ts[j])) {
                if (--in[t] == 0) {
                    Q.Put(t);
                }
            }
        }
    }

    /**
     * @brief 返回Topo-Sort的顶点索引数组
     *
     * @return 顶点索引数组，数组下标为顶点，值为在拓扑排序中的序号
     */
    std::vector<int> Index() const
    {
        return tsI;
    }
};

}   // namespace mini_algo

#endif

