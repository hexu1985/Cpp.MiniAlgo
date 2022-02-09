/**
 * @file spt.hpp
 * @brief Dijkstra单源最短路径算法
 * @author hexu_1985@sina.com
 * @version 1.0
 * @date 2019-10-28
 *
 * @see 算法概论中文版: 章节4.4
 */
#ifndef MINI_ALGO_GRAPH_SPT_INC
#define MINI_ALGO_GRAPH_SPT_INC

#include <vector>
#include <limits>
#include "Edge.hpp"

namespace mini_algo {

template <class Graph> 
class SPT { 
private:
    const Graph& G;
    std::vector<double> dist;  // 源点s到各个顶点的距离
    std::vector<int> prev;

    // 无限dist
    static double Infinity() {
        return std::numeric_limits<double>::infinity();
    }

    // dist相加
    double Plus(double a, double b) {
        if(a == Infinity() || b == Infinity()) {
            return Infinity();
        }
        return a+b;
    }

    // 顶点队列，每次弹出dist最小值顶点
    struct DistQueue {
        std::set<int> s;
        std::vector<double>& dist;

        DistQueue(int V, std::vector<double>& dist): dist(dist) {
            for (int v = 0; v < V; v++) {
                s.insert(v);
            }
        }
        
        int DeleteMin() {
            int minIdx = *s.begin();
            double minVal = dist[minIdx];
            for (auto v: s) {
                if (dist[v] < minVal) {
                    minIdx = v;
                }
            }
            s.erase(v);
            return v;
        }

        void UpdateDist(int v) {}

        bool Empty() { return s.empty(); }
    };

public:
    SPT(const Graph &graph, int s): 
        G(graph), 
        dist(graph.V(), Infinity()),
        prev(graph.V(), -1)
    {
        DistQueue Q(dist);   // 距离越小优先级越高

        dist[s] = 0.0; 
        prev[s] = s;

        while (!Q.Empty()) 
        { 
            int v = Q.DeleteMin();   // 获取最小距离的顶点索引

            for (auto e: G.AdjList(v)) { 
                int w = e->other(v); 
                if (Plus(dist[v], e->weight()) < dist[w]) {     // e:v->w, dist[v] + l(v,w) < dist[w]
                    dist[w] = Plus(dist[v], e->weight()); 
                    prev[w] = v; 
                    Q.UpdateDist(w);   // 更新到各个顶点的距离
                }
            }
        }
    }

    int Prev(int v) const { return prev[v]; }
    double Dist(int v) const { return dist[v]; }
};

}	// namespace mini_algo

#endif
