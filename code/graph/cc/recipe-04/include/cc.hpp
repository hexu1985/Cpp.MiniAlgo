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
#include "dfs.hpp"

namespace mini_algo {

/**
 * @brief 无向图连通分量(Connected Components, CC)算法
 *
 * @tparam Graph 图类型
 */
template <typename Graph>
class CC: public DFS<Graph> {
private:
    std::vector<int> cc;    // 顶点 -> 连通分量号，序号从0开始，例如cc[1]表示为顶点1连通分量号
    int num_cc = 0;         // 连通分量个数

    using Base = DFS<Graph>;
    using Base::G;
    using Base::IsVisited;
    using Base::Explore;

public:
    CC(const Graph& graph): Base(graph), cc(graph.V(), -1), num_cc(0) {}

    /**
     * @brief Connected Components main function
     */
    void Search()
    {
        for (int v = 0; v < G.V(); v++) {
            if (!IsVisited(v)) {
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
    void Visit(int v) override
    {
        this->Base::Visit(v);
        cc[v] = num_cc;
    }
};

}   // namespace mini_algo

#endif

