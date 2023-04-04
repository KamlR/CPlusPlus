#include "FileInput.h"

// Считывание данных о матрице смежности из файла.
// Как и слудующие методы очень похож на консольный ввод, разве что другой поток.
void GraphFileInputFirst(vector<vector<int>> &graph_input, int vertices, string path) {
    vertices += 1;
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (i == 0) {
                graph_input[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                graph_input[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    // Использование файлового потока.
    ifstream flow(path);
    string numbers;
    int index = 1;
    for (int i = 1; i < vertices; ++i) {
        index = 1;
        getline(flow, numbers);
        stringstream ss1(numbers);
        int num;
        while (ss1 >> num) {
            graph_input[i][index] = num;
            index += 1;
        }
    }
}

// Считывание данных о матрице инцидентности из файла.
// Изначально заполняются первый столбец и первая строка, затем информация о вершинах и выходящих рёбрах.
void GraphFileInputSecond(vector<vector<int>> &graph_input, int vertices, int edges, string path) {
    vertices += 1;
    edges += 1;
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < edges; ++j) {
            if (i == 0) {
                graph_input[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                graph_input[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    ifstream flow(path);
    string numbers;
    int index = 1;
    for (int i = 1; i < vertices; ++i) {
        index = 1;
        getline(flow, numbers);
        stringstream ss1(numbers);
        int num;
        while (ss1 >> num) {
            graph_input[i][index] = num;
            index += 1;
        }
    }
}

// Считывание данных о списке смежности из файла.
// Изначально заполняются первый столбец, затем информация о вершинах.
void GraphFileInputThird(vector<vector<int>> &graph_input, int vertices, string path) {
    ifstream flow(path);
    string numbers;
    int num;
    int index;
    for (int i = 1; i < vertices + 1; ++i) {
        index = 0;
        getline(flow, numbers);
        stringstream ss1(numbers);
        while (ss1 >> num) {
            graph_input[i][index] = num;
            index += 1;
        }
    }
}

// Считывание данных о списке рёбр из файла.
void GraphFileInputFourth(vector<vector<int>> &graph_input, int lines, string path) {
    ifstream flow(path);
    string numbers;
    int num;
    int index;
    for (int i = 0; i < lines; ++i) {
        index = 0;
        getline(flow, numbers);
        stringstream ss1(numbers);
        while (ss1 >> num) {
            graph_input[i][index] = num;
            index += 1;
        }
    }
}
