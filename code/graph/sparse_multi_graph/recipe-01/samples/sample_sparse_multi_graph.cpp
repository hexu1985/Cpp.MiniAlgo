#include <vector>
#include "dense_graph.hpp"
#include "graph_io.hpp"

using namespace std;
using namespace mini_algo;

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

    cout << "remove edges\n";
    for (auto edge: edges)
        graph.Remove(edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after remove edges:\n" << graph << endl;

    return 0;
}
