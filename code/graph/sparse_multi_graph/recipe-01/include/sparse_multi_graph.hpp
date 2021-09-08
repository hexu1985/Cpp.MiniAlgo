/**
 * @file sparse_multi_graph.hpp
 * @brief 一个稀疏图实现, 基于邻接链表(支持平行边)
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-06-24
 *
 * @see C++算法: 图算法(第3版): 章节1.4
 */
#ifndef MINI_ALGO_SPARSE_MUTLI_GRAPH_INC
#define MINI_ALGO_SPARSE_MUTLI_GRAPH_INC

#include <tuple>
#include <memory>
#include <vector>
#include <forward_list>
#include <algorithm>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 一个稀疏图实现, 基于邻接链表(支持平行边)
 */
class SparseMultiGraph { 
private:
    std::vector<std::forward_list<int>> adj;  // 邻接链表数组
    int v_cnt = 0;                            // 顶点数
    int e_cnt = 0;                            // 边数
    bool digraph = false;                     // 是否为有向图

public:
    /**
     * @brief 构造一个稀疏图对象
     *
     * @param v_cnt 图的顶点数
     * @param digraph 是否为有向图
     */
    SparseMultiGraph(int V, bool digraph = false) :
        adj(V), v_cnt(V), e_cnt(0), digraph(digraph) 
    { 
    }

    /**
     * @brief 返回图的顶点数
     *
     * @return 顶点个数
     */
    int V() const { return v_cnt; }

    /**
     * @brief 返回图的边数
     *
     * @return 边的个数
     */
    int E() const { return e_cnt; }

    /**
     * @brief 是否为有向图
     *
     * @return 如果为有向图, 返回true, 否则为false
     */
    bool Directed() const { return digraph; }

    /**
     * @brief 向图中插入一条边
     *
     * @param e 要插入的边
     */
    void Insert(Edge e)
    { 
        int v = e.v, w = e.w;
        adj[v].push_front(w);
        if (!digraph) adj[w].push_front(v);
        e_cnt++;
    } 

    /**
     * @brief 从图中删除一条边
     *
     * @param e 要删除的边
     */
    void Remove(Edge e)
    {
        int v = e.v, w = e.w;
        int n = std::count(std::begin(adj[v]), std::end(adj[v]), w);

        if (n == 0) return;

        e_cnt-=n;
        adj[v].remove(w);

        if (!digraph) adj[w].remove(v);
    } 

    /**
     * @brief 判断边是否属于指定图
     *
     * @param e 边
     *
     * @return 如果边属于指定图, 返回true, 否则返回false
     */
    bool HasEdge(int v, int w) const 
    {
        return (std::find(std::begin(adj[v]), std::end(adj[v]), w) != std::end(adj[v]));
    }

    /**
     * @brief 获取指定顶点的邻接顶点的列表
     *
     * @param v 指定顶点
     *
     * @return 邻接顶点的迭代器
     */
    const std::forward_list<int>& AdjList(int v) const 
    { 
        return adj[v]; 
    }
};

}   // namespace mini_algo

#endif
