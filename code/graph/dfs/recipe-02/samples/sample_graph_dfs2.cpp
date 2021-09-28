#include <vector>
#include "dense_graph.hpp"
#include "graph_print.hpp"
#include "dfs.hpp"

using namespace std;
using namespace mini_algo;

template <typename Graph>
class MyDFS: public DFS<Graph> {
public:
    int depth = 0;

    using Base = DFS<Graph>;
    MyDFS(const Graph& graph): Base(graph) {}

    void PreVisit(Edge e) override
    {
        depth++;
    }

    void Visit(Edge e) override
    {
        this->Base::Visit(e);
        PrintTab(depth);
        cout << "visit: " << e.w << endl;
    }

    void PostVisit(Edge e) override
    {
        PrintTab(depth);
        cout << "leave: " << e.w << endl;
        depth--;
    }

    void PrintTab(int n) 
    {
        for (int i = 0 ; i < n; i++)
            cout << '\t';
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

    cout << "DFS explore from node 0" << endl;
    MyDFS<DenseGraph> dfs(graph);
    dfs.Explore(Edge(0,0));

    return 0;
}
