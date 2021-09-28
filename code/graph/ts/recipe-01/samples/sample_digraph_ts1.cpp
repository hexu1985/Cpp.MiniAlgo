#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "graph_print_vlabel.hpp"
#include "ts.hpp"

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

    DenseGraph digraph(vertex_number, true);

    cout << "insert edges\n";
    for (auto edge: edges)
        digraph.Insert(edge);

    // show adjLists
    cout << "graph after insert edges:\n";
    Print(cout, digraph, vmap);
    cout << endl;

    TS<DenseGraph> topo_sort(digraph);
    topo_sort.Search();

    cout << "topo-sort order:\n";
    auto tsI = topo_sort.Index();
    for (int i = 0; i < vertex_number; i++) {
        cout << vmap[i] << ": " << tsI[i] << endl;
    }
    cout << endl;

    std::vector<int> ts(vertex_number, -1);
    for (int i = 0; i < vertex_number; i++) {
        ts[tsI[i]] = i;
    }
    cout << "topo-sort:\n";
    for (int i = 0; i < vertex_number; i++) {
        cout << vmap[ts[i]] << ", ";
    }
    cout << endl;

    return 0;
}
