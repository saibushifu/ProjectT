#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

int findMinDistanceVertex(const std::vector<int>& distances, const std::vector<bool>& visited);

int dijkstra(const std::vector<std::vector<int>>& graph, int start, int end);

#endif // GRAPH_H
