/**
 * @file weight/SparsMultiGraph.hpp
 * @file sparse_graph.hpp
 * @brief 一个稀疏图实现, 基于邻接链表(支持平行边)
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-07-09
 *
 * @see C++算法: 图算法(第3版): 章节4.1
 */
#ifndef MINI_ALGO_SPARSE_MULTI_GRAPH_INC
#define MINI_ALGO_SPARSE_MULTI_GRAPH_INC

#include <vector>
#include <memory>
#include <forward_list>
#include <algorithm>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 一个稀疏图实现, 基于邻接链表(支持平行边)
 */
class SparseMultiGraph { 
private:
    std::vector<std::forward_list<Edge*>> adj; // 邻接链表数组
    int v_cnt = 0;                             // 顶点数
    int e_cnt = 0;                             // 边数
    bool digraph = false;                      // 是否为有向图

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
    void Insert(Edge* e)
    { 
        int v = e->v, w = e->w;
        adj[v].push_front(e);
        if (!digraph) adj[w].push_front(e);
        e_cnt++;
    } 

    /**
     * @brief 从图中删除一条边
     *
     * @param e 要删除的边
     */
    void Remove(Edge* e)
    {
        int v = e->v, w = e->w;
        int n = std::count_if(std::begin(adj[v]),
                    std::end(adj[v]), 
                    [v, w](Edge* e){ return e->Other(v) == w;});

        if (n == 0) return;

        e_cnt-=n;
        adj[v].remove_if([v, w](Edge* e) { return e->Other(v) == w; });

        if (!digraph)
            adj[w].remove_if([v, w](Edge* e) { return (e->Other(w) == v); });
    } 

    /**
     * @brief 判断两个顶点之间是否有直连边(两顶点是否邻接)
     *
     * @param u from顶点
     * @param v to顶点
     *
     * @return 如果v和w邻接, 返回边的指针, 否则返回空指针
     */
    Edge* GetEdge(int v, int w) const
    {
        for (auto e: adj[v]) {
            if (e->Other(v) == w) {
                return e;
            }
        }
        return nullptr;
    }

    /**
     * @brief 获取指定顶点的邻接顶点的列表
     *
     * @param v 指定顶点
     *
     * @return 邻接顶点的迭代器
     */
    const std::forward_list<Edge*>& AdjList(int v) const
    {
        return adj[v];
    }
};

}   // namespace mini_algo

#endif // MINI_ALGO_SPARSE_MULTI_GRAPH_INC
