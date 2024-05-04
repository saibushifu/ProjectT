#include "middletasks.h"
#include "middle.h"

#include <cmath>
#include <vector>

using namespace std;


vector<double> points = { 1, 2, 0, 4, 2, 6 };

double F1(double x) {
    return x*x - 9*x + 14;
}
double F2(double x) {
    return x*x*x + x - 21;
}
double F3(double x) {
    return x - sqrt(3*x) - 1;
}

double task2_answer(int cur_task_id) {
    double a, b, eps = 0.01, x;
    if (cur_task_id == 1) {
        a = points.at(0);
        b = points.at(1);
        x = FindRoot(F1, a, b, eps);
        return x;
    }
    else if (cur_task_id == 2) {
        a = points.at(2);
        b = points.at(3);
        x = FindRoot(F2, a, b, eps);
        return x;
    }
    else if (cur_task_id == 3) {
        a = points.at(4);
        b = points.at(5);
        x = FindRoot(F3, a, b, eps);
        return x;
    }
    return -1;
}
