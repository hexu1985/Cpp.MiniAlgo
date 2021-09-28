#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "sparse_multi_graph.hpp"
#include "graph_print_vlabel.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    //                      0    1    2    3  
    vector<string> vmap = {"s", "v", "w", "t"};
    vector<Edge> edges = {
                            {0,1}, // s - v
                            {0,2}, // s - w 
                            {1,2}, // v - w
                            {1,3}, // v - t
                            {2,3}, // w - t
                         };
    int vertex_number = vmap.size();

    SparseMultiGraph digraph(vertex_number, true);

    cout << "insert edges\n";
    for (auto edge: edges)
        digraph.Insert(edge);

    // show adjLists
    cout << "graph after insert edges:\n";
    Print(cout, digraph, vmap);
    cout << endl;

    cout << "remove edges\n";
    for (auto edge: edges)
        digraph.Remove(edge);

    // show edges
    cout << digraph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after remove edges:\n"; 
    Print(cout, digraph, vmap);
    cout << endl;

    return 0;
}
