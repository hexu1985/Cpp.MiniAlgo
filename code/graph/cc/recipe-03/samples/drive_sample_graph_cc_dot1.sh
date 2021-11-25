#!/usr/bin/env bash

echo "./sample_graph_cc_dot1 graph_cc1.dot"
./sample_graph_cc_dot1 graph_cc1.dot
dot graph_cc1.dot -T png -o graph_cc1.png
echo "output png is graph_cc1.png"

