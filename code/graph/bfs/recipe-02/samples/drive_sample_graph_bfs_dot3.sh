#!/usr/bin/env bash

echo "./sample_graph_bfs_dot3 graph_bfs3.dot"
./sample_graph_bfs_dot3 graph_bfs3.dot
dot graph_bfs3.dot -T png -o graph_bfs3.png
echo "output png is graph_bfs3.png"

