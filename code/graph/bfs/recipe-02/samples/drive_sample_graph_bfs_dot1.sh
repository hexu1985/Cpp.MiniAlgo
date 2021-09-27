#!/usr/bin/env bash

echo "./sample_graph_bfs_dot1 graph_bfs1.dot"
./sample_graph_bfs_dot1 graph_bfs1.dot
dot graph_bfs1.dot -T png -o graph_bfs1.png
echo "output png is graph_bfs1.png"

