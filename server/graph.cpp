#include "graph.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

// Функция для нахождения вершины с минимальным расстоянием
int findMinDistanceVertex(const vector<int>& distances, const vector<bool>& visited) {
    int minDistance = numeric_limits<int>::max();
    int minVertex = -1;
    for (int i = 0; i < int(distances.size()); ++i) {
        if (!visited[i] && distances[i] < minDistance) {
            minDistance = distances[i];
            minVertex = i;
        }
    }
    return minVertex;
}

// Функция для вычисления кратчайших расстояний до всех вершин от заданной стартовой вершины
int dijkstra(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max()); // Расстояния до всех вершин
    vector<bool> visited(n, false); // Посещенные вершины
    distances[start] = 0; // Расстояние до стартовой вершины равно 0

    for (int i = 0; i < n - 1; ++i) {
        int u = findMinDistanceVertex(distances, visited); // Находим вершину с минимальным расстоянием
        visited[u] = true; // Помечаем вершину как посещенную
        for (int v = 0; v < n; ++v) {
            // Если есть ребро между u и v, и v еще не посещена, и новое расстояние до v меньше текущего
            if (graph[u][v] != 0 && !visited[v] && distances[u] != numeric_limits<int>::max() &&
                distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v]; // Обновляем расстояние до v
            }
        }
    }

    // Выводим кратчайшие расстояния до всех вершин
    return distances[end];
}
