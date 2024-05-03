#include "graphtasks.h"
#include "graph.h"

#include <QString>
#include <QCoreApplication>
#include <QDebug>


using namespace std;

int task_answer(int cur_task_id) {
    int points_amount = 6;
    if (cur_task_id == 1) {
        int start = 0;
        int end = 2;

        vector<int> task = {0, 7, 0, 0, 4, 0, 7, 0, 5, 0, 0, 2, 0, 5, 0, 11, 0, 6, 0, 0, 11, 0, 8, 9, 4, 0, 0, 8, 0, 3, 0, 2, 6, 9, 3, 0};

        vector<vector<int>> graph(points_amount, vector<int>(points_amount)); // Создаем матрицу смежности
        int ind = 0;
        for (int i = 0; i < points_amount; i++) {
            for (int j = 0; j < points_amount; j++) {
                graph[i][j] = task[ind];
                ind++;
            }
        }

        int res = dijkstra(graph, start, end);
        return res;
    }
    else if (cur_task_id == 2) {
        int start = 5;
        int end = 2;

        vector<int> task = {0, 10, 0, 1, 0, 20, 10, 0, 1, 0, 0, 1, 0, 1, 0, 4, 0, 0, 1, 0, 4, 0, 3, 2, 0, 0, 0, 3, 0, 1, 20, 1, 0, 2, 1, 0};

        vector<vector<int>> graph(points_amount, vector<int>(points_amount)); // Создаем матрицу смежности
        int ind = 0;
        for (int i = 0; i < points_amount; i++) {
            for (int j = 0; j < points_amount; j++) {
                graph[i][j] = task[ind];
                ind++;
            }
        }

        int res = dijkstra(graph, start, end);
        return res;
    }
    else if (cur_task_id == 3) {
        int start = 1;
        int end = 5;

        vector<int> task = {0, 15, 6, 23, 0, 16, 15, 0, 0, 1, 4, 30, 6, 0, 0, 12, 25, 4, 23, 1, 12, 0, 2, 0, 0, 4, 25, 2, 0, 0, 16, 30, 4, 0, 0, 0};

        vector<vector<int>> graph(points_amount, vector<int>(points_amount)); // Создаем матрицу смежности
        int ind = 0;
        for (int i = 0; i < points_amount; i++) {
            for (int j = 0; j < points_amount; j++) {
                graph[i][j] = task[ind];
                ind++;
            }
        }

        int res = dijkstra(graph, start, end);
        return res;
    }
    return -1;

}


/*
int start_2 = 0;
int end_2 = 6;

int start_3 = 5;
int end_3 = 8;
*/

