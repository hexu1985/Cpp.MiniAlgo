#include <vector>
#include "dense_graph.hpp"
#include "graph_print.hpp"
#include "dfs.hpp"
#include "graph_dot_etrace.hpp"

using namespace std;
using namespace mini_algo;

template <typename Graph>
class MyDFS: public DFS<Graph> {
public:
    vector<Edge> search_trace;    // search trace

    using Base = DFS<Graph>;
    MyDFS(const Graph& graph): Base(graph) {}

    void Visit(Edge e) override
    {
        this->Base::Visit(e);
        if (e.v != e.w)
            search_trace.push_back(e);
    }
};


int main(int argc, char *argv[])
{
    string dot_file = "graph_dfs1.dot";
    if (argc >= 2) {
        dot_file = argv[1];
    }

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

    cout << "DFS explore from node 0" << endl;
    MyDFS<DenseGraph> dfs(graph);
    dfs.Explore(Edge(0,0));

    // save dot file
    cout << "save graph to " << dot_file << " ...\n";
    if (!WriteDotFile(dot_file, graph, dfs.search_trace)) {
        cout << "open " << dot_file << " failed!\n";
        exit(1);
    }

    cout << "write dot file success!" << endl;

    return 0;
}
