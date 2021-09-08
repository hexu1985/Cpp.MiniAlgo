/**
 * @file dense_graph.hpp
 * @brief 带权重的稠密图实现, 基于邻接矩阵(不支持平行边)
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-07-09
 *
 * @see C++算法: 图算法(第3版): 章节4.1
 */
#ifndef MINI_ALGO_DENSE_GRAPH_INC
#define MINI_ALGO_DENSE_GRAPH_INC

#include <tuple>
#include <vector>
#include <memory>
#include "edge.hpp"

namespace mini_algo {

/**
 * @brief 带权重的稠密图实现, 基于邻接矩阵(不支持平行边)
 */
class DenseGraph { 
private:
    std::vector<std::vector<Edge*>> adj;  // 邻接矩阵
    int v_cnt = 0;                        // 顶点数
    int e_cnt = 0;                        // 边数
    bool digraph = false;                 // 是否为有向图

public:
    /**
     * @brief 构造一个稠密图对象
     *
     * @param v_cnt 图的顶点数
     * @param digraph 是否为有向图
     */
    DenseGraph(int V, bool digraph = false) :
        adj(V), v_cnt(V), e_cnt(0), digraph(digraph)
    { 
        for (int i = 0; i < v_cnt; i++)
            adj[i].assign(v_cnt, nullptr);
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
        if (adj[v][w] == nullptr) e_cnt++;
        adj[v][w] = e;
        if (!digraph) adj[w][v] = e; 
    } 

    /**
     * @brief 从图中删除一条边
     *
     * @param e 要删除的边
     */
    void Remove(Edge* e)
    { 
        int v = e->v, w = e->w;
        if (adj[v][w]) e_cnt--;
        adj[v][w] = nullptr;
        if (!digraph) adj[w][v] = nullptr; 
    } 

    /**
     * @brief 判断两个顶点之间是否有直连边(两顶点是否邻接)
     *
     * @param u from顶点
     * @param v to顶点
     *
     * @return 如果u和v邻接, 返回边的指针, 否则返回空指针
     */
    Edge* GetEdge(int v, int w) const { return adj[v][w]; }

    /**
     * @brief 获取指定顶点的邻接顶点的列表
     *
     * @param v 指定顶点
     *
     * @return 邻接顶点的迭代器
     */
    std::vector<Edge*> AdjList(int v) const 
    {
        std::vector<Edge*> adj_list;
        for (int i = 0; i < v_cnt; i++) {
            Edge* e = adj[v][i];
            if (e) {
                adj_list.push_back(e);
            }
        } 
        return adj_list;
    }
};

}   // namespace mini_algo

#endif
