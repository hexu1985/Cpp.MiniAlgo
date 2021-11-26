#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "bfs.hpp"
#include "graph_dot_vlabel.hpp"

using namespace std;
using namespace mini_algo;

template <typename Graph>
class MyBFS: public BFS<Graph> {
public:
    vector<int> dist;   // 广度优先搜索，节点到源点的距离

    using Base = BFS<Graph>;

    MyBFS(const Graph& graph): Base(graph), dist(graph.V(), -1) {}

    void Explore(Edge e) {
        dist[e.w] = 0;
        this->Base::Explore(e);
    }

    void Visit(Edge e) override
    {
        this->Base::Visit(e);
        if (e.v != e.w)
            dist[e.w] = dist[e.v] + 1;
    }
};

int main(int argc, char *argv[])
{
    string dot_file = "graph_bfs3.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

    //                      0    1    2    3    4    5    6
    vector<string> vmap = {"s", "a", "b", "c", "d", "e", "f"};
    vector<Edge> edges = {
                            {0,1}, // s - a
                            {0,2}, // s - b 
                            {1,3}, // a - c
                            {2,3}, // b - c
                            {2,4}, // b - d
                            {3,4}, // c - d
                            {3,5}, // c - e
                            {4,5}, // d - e
                         };
    int vertex_number = vmap.size();

    DenseGraph graph(vertex_number, false);

    cout << "insert edges\n";
    for (auto edge: edges)
        graph.Insert(edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    cout << "BFS explore from node 0" << endl;
    MyBFS<DenseGraph> bfs(graph);
    bfs.Explore(Edge(0,0));

    // save dot file
    vector<int>& dist = bfs.dist;
    for (int i = 0; i < vertex_number; i++) {
        if (dist[i] > 0) {
            vmap[i] += " (dist: " + std::to_string(dist[i]) + ")";
        } else if (dist[i] < 0) {
            vmap[i] += " (dist: inf)";
        } else {    // source
            vmap[i] += " (source point)";
        }
    }
    cout << "save graph to " << dot_file << " ...\n";
    WriteDotFile(dot_file, graph, vmap);

    cout << "write dot file success!" << endl;

    return 0;
}
