#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "dense_graph.hpp"
#include "graph_print.hpp"
#include "cc.hpp"

using namespace std;
using namespace mini_algo;

int main(int argc, char *argv[])
{
    int vertex_number = 13;
    vector<Edge> edges = {  {0,1}, {0,9}, {1,9}, {1,4},
                            {8,11},
                            {7,10}, {2,10}, {6,10}, {2,7}, {2,12}, {6,12}, {3,12}, {5,12}
                         };

    DenseGraph graph(vertex_number, false);

    cout << "insert edges\n";
    for (auto edge: edges)
        graph.Insert(edge);

    // show edges
    cout << graph.E() << " edges in graph" << endl;

    // show adjLists
    cout << "graph after insert edges:\n" << graph << endl;

    CC<DenseGraph> connected_component(graph);
    connected_component.Search();

    cout << connected_component.Count() << " components" << endl;

    cout << "connected-components index:\n";
    auto cc = connected_component.Index();
    for (int i = 0; i < vertex_number; i++) {
        cout << i << ": " << cc[i] << endl;
    }
    cout << endl;

    return 0;
}
