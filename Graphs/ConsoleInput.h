#pragma once
#include <vector>
#include <iostream>
using namespace std;
// Ввод матрицы смежности в консоль.
void GraphConsoleInputFirst(vector<vector<int>> &graph_input, int vertices);

// Ввод матрицы инцидентности в консоль.
void GraphConsoleInputSecond(vector<vector<int>> &graph_input, int vertices, int edges);

// Ввод списка смежности в консоль.
void GraphConsoleInputThird(vector<vector<int>> &graph_input, int vertices);

// Ввод списка дуг/рёбр в консоль.
void GraphConsoleInputFourth(vector<vector<int>> &graph_input, int vertices, int rows);