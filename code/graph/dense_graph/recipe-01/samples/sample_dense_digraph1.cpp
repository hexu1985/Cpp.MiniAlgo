/** \example sample_unweight_dense_graph1.cpp
 * This is an example of how to use the unweight::dense_graph class.
 */
#include <vector>
#include "dense_graph.hpp"
#include "graph_io.hpp"

using namespace std;
using namespace mini_algo;

int main()
{
    int vertex_number = 13;
    vector<Edge> edges = {
        {4,2}, {2,3}, {3,2}, {0,6}, {0,1},
        {2,0}, {11,12}, {12,9}, {9,10}, {9,11},
        {8,9}, {10,12}, {4,11}, {4,3}, {3,5},
        {7,8}, {8,7}, {5,4}, {0,5}, {6,4},
        {6,9}, {7,6}};

    DenseGraph digraph(vertex_number, true);

    cout << "insert edges\n";
    for (auto edge: edges)
        digraph.Insert(edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after insert edges:\n" << digraph << endl;

    cout << "remove edges\n";
    for (auto edge: edges)
        digraph.Remove(edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after remove edges:\n" << digraph << endl;

    return 0;
}
