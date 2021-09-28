#include <vector>
#include "dense_graph.hpp"
#include "graph_print.hpp"
#include "bfs.hpp"

using namespace std;
using namespace mini_algo;

template <typename Graph>
class MyBFS: public BFS<Graph> {
public:
    using Base = BFS<Graph>;
    MyBFS(const Graph& graph): Base(graph) {}

    void Visit(Edge e) override
    {
        this->Base::Visit(e);
        cout << "visit: " << e.w << endl;
    }
};


int main(int argc, char *argv[])
{
    int vertex_number = 8;
    vector<Edge> edges = {{0,2}, {0,5}, {0,7}, {1,7}, {2,6}, {3,4}, {3,5}, {4,5}, {4,6}, {4,7}};

    DenseGraph graph(vertex_number, false);

    cout << "insert edges\n";
    for (auto edge: edges)
        graph.Insert(edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after insert edges:\n" << graph << endl;

    cout << "BFS explore from node 0" << endl;
    MyBFS<DenseGraph> bfs(graph);
    bfs.Explore(Edge(0,0));

    return 0;
}
