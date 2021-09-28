/**
 * @file ts.hpp
 * @brief 有向图拓扑排序算法，Topo-Sort
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2020-09-03
 *
 * @see 算法详解（卷2）图算法和数据结构：章节2.4.2
 */
#ifndef MINI_ALGO_TS_INC
#define MINI_ALGO_TS_INC

#include <vector>
#include <algorithm>
#include "dfs.hpp"

namespace mini_algo {

/**
 * @brief 有向图拓扑排序算法
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class TS: public DFS<Graph> {
private:
    int cur_label;         // 记录顺序
    std::vector<int> f;    // 每个顶点的顺序

    using Base = DFS<Graph>;
    using Base::G;
    using Base::IsVisited;
    using Base::Explore;

public:
    TS(const Graph& graph): Base(graph), cur_label(graph.V()-1), f(graph.V(), -1) {}

    /**
     * @brief Topo-Sort main function
     */
    void Search()
    {
        for (int v = 0; v < G.V(); v++) {
            if (!IsVisited(v)) {
                Explore(v);
            }
        }
    }

    /**
     * @brief 返回Topo-Sort的重新编号数组
     *
     * @return 重新编号数组，数组下标为顶点编号，值为在拓扑排序中的顺序
     */
    std::vector<int> Index()
    {
        return f;
    }

private:
    void PostVisit(int v) override
    {
        f[v] = cur_label;           // s的位置符合顺序
        cur_label = cur_label-1;    // 从右向左进行操作
    }
};

}   // namespace mini_algo

#endif

