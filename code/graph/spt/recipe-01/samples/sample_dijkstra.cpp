#include <vector>
#include "dense_graph.hpp"
#include "graph_print.hpp"

using namespace std;
using namespace mini_algo;

int main()
{
    int vertexNumber = 6;
    vector<Edge> edges = {
        {1,0, .41},
        {2,1, .51},
        {3,2, .50},
        {3,4, .36},
        {5,3, .38},
        {0,3, .45},
        {5,0, .29},
        {4,5, .21},
        {4,1, .32},
        {2,4, .32},
        {1,5, .29},
    };

    DenseGraph digraph(vertexNumber, true);

    cout << "insert edges\n";
    for (auto &edge: edges)
        digraph.Insert(&edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after insert edges:\n"
        << digraph
        << endl;

    return 0;
}
