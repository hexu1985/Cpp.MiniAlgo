#!/usr/bin/env bash

echo "./sample_sparse_multi_digraph"
./sample_sparse_multi_digraph

echo
echo

echo "./sample_sparse_multi_digraph_dot sparse_multi_digraph.dot"
./sample_sparse_multi_digraph_dot sparse_multi_digraph.dot
dot sparse_multi_digraph.dot -T png -o sparse_multi_digraph.png
echo "output png is sparse_multi_digraph.png"

echo
echo

echo "./sample_sparse_multi_digraph_dot_vlabel sparse_multi_digraph_vlabel.dot"
./sample_sparse_multi_digraph_dot_vlabel sparse_multi_digraph_vlabel.dot
dot sparse_multi_digraph_vlabel.dot -T png -o sparse_multi_digraph_vlabel.png
echo "output png is sparse_multi_digraph_vlabel.png"

echo
echo

echo "./sample_sparse_multi_graph"
./sample_sparse_multi_graph

echo
echo

echo "./sample_sparse_multi_graph_dot sparse_multi_graph.dot"
./sample_sparse_multi_graph_dot sparse_multi_graph.dot
dot sparse_multi_graph.dot -T png -o sparse_multi_graph.png
echo "output png is sparse_multi_graph.png"

echo
echo

echo "./sample_sparse_multi_graph_dot_vlabel sparse_multi_graph_vlabel.dot"
./sample_sparse_multi_graph_dot_vlabel sparse_multi_graph_vlabel.dot
dot sparse_multi_graph_vlabel.dot -T png -o sparse_multi_graph_vlabel.png
echo "output png is sparse_multi_graph_vlabel.png"

