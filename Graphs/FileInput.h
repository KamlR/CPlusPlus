#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Ввод матрицы смежности из файла.
void GraphFileInputFirst(vector<vector<int>> &graph_input, int vertices, string path);

// Ввод матрицы инцидентности из файла.
void GraphFileInputSecond(vector<vector<int>> &graph_input, int vertices, int edges, string path);

// Ввод списка смежности из файла.
void GraphFileInputThird(vector<vector<int>> &graph_input, int vertices, string path);

// Ввод списка дуг/рёбр из файла.
void GraphFileInputFourth(vector<vector<int>> &graph_input, int lines, string path);