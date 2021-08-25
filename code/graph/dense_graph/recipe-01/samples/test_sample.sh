#!/usr/bin/env bash

echo "./sample_dense_digraph1"
./sample_dense_digraph1

echo
echo

echo "./sample_dense_digraph_dot1 dense_digraph1.dot"
./sample_dense_digraph_dot1 dense_digraph1.dot
dot dense_digraph1.dot -T png -o dense_digraph1.png
echo "output png is dense_digraph1.png"

echo
echo

exit 1

echo "./sample_unweight_dense_graph2 unweight_dense_graph2.dot"
./sample_unweight_dense_graph2 unweight_dense_graph2.dot
dot unweight_dense_graph2.dot -T png -o unweight_dense_graph2.png
echo "output png is unweight_dense_graph2.png"

echo
echo

echo "./sample_unweight_dense_graph_dot1 unweight_dense_graph_dot1.dot"
./sample_unweight_dense_graph_dot1 unweight_dense_graph_dot1.dot 
dot unweight_dense_graph_dot1.dot -T png -o unweight_dense_graph_dot1.png
echo "output png is unweight_dense_graph_dot1.png"

echo
echo

echo "./sample_unweight_dense_digraph1"
./sample_unweight_dense_digraph1

echo
echo

echo "./sample_unweight_dense_digraph_dot1 unweight_dense_digraph_dot1.dot"
./sample_unweight_dense_digraph_dot1 unweight_dense_digraph_dot1.dot 
dot unweight_dense_digraph_dot1.dot -T png -o unweight_dense_digraph_dot1.png
echo "output png is unweight_dense_digraph_dot1.png"

