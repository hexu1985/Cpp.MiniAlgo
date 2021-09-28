#include <vector>
#include "dense_graph.hpp"
#include "graph_print.hpp"

using namespace std;
using namespace mini_algo;

int main()
{
    int vertexNumber = 8;
    vector<Edge> edges = {
        {0,6, .51},
        {0,1, .32},
        {0,2, .29},
        {4,3, .34},
        {5,3, .18},
        {7,4, .46},
        {5,4, .40},
        {0,5, .60},
        {6,4, .51},
        {7,0, .31},
        {7,6, .25},
        {7,1, .21}
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

    cout << "remove edges\n";
    for (auto edge: edges)
        digraph.Remove(&edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after remove edges:\n"
        << digraph
        << endl;

    return 0;
}
