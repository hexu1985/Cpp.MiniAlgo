#!/usr/bin/env bash

echo "./sample_dense_digraph"
./sample_dense_digraph

echo
echo

echo "./sample_dense_digraph_dot dense_digraph.dot"
./sample_dense_digraph_dot dense_digraph.dot
dot dense_digraph.dot -T png -o dense_digraph.png
echo "output png is dense_digraph.png"

echo
echo

echo "./sample_dense_digraph_dot_vlabel dense_digraph_vlabel.dot"
./sample_dense_digraph_dot_vlabel dense_digraph_vlabel.dot
dot dense_digraph_vlabel.dot -T png -o dense_digraph_vlabel.png
echo "output png is dense_digraph_vlabel.png"

echo
echo

echo "./sample_dense_graph"
./sample_dense_graph

echo
echo

echo "./sample_dense_graph_dot dense_graph.dot"
./sample_dense_graph_dot dense_graph.dot
dot dense_graph.dot -T png -o dense_graph.png
echo "output png is dense_graph.png"

echo
echo

echo "./sample_dense_graph_dot_vlabel dense_graph_vlabel.dot"
./sample_dense_graph_dot_vlabel dense_graph_vlabel.dot
dot dense_graph_vlabel.dot -T png -o dense_graph_vlabel.png
echo "output png is dense_graph_vlabel.png"

