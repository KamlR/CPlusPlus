#include "ConsoleInput.h"

// Считывание данных о матрице смежности с консоли.
// Изначально заполняются первый столбец и первая строка, затем информация о вершинах.
// Пользователю выводятся подсказки о правильном вводе данных.
void GraphConsoleInputFirst(vector<vector<int>> &graph_input, int vertices) {
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
    int number;
    for (int i = 1; i < vertices; ++i) {
        cout << "Enter into the line, separated by a space, with whom " << i << " vertex is connected:" << endl;
        for (int j = 1; j < vertices; ++j) {
            cin >> number;
            graph_input[i][j] = number;
        }
    }
}

// Считывание данных о миатрице инцидентности с консоли.
// Изначально заполняются первый столбец и первая строка, затем информация о вершинах и выходящих рёбрах.
// Пользователю выводятся подсказки о правильном вводе данных.
void GraphConsoleInputSecond(vector<vector<int>> &graph_input, int vertices, int edges) {
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
    int number;
    for (int i = 1; i < vertices; ++i) {
        cout << "Enter information about edges for " << i << " vertex separated by a space" << endl;
        for (int j = 1; j < edges; ++j) {
            cin >> number;
            graph_input[i][j] = number;
        }
    }
}

// Считывание данных о списке смежности с консоли.
// Изначально заполняются первый столбец, затем информация о вершинах.
// Пользователю выводятся подсказки о правильном вводе данных.
void GraphConsoleInputThird(vector<vector<int>> &graph_input, int vertices) {
    int count = 0;
    vertices += 1;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            if (j == 0) {
                graph_input[i][j] = count;
                count += 1;
            }
        }
    }
    int number;
    for (int i = 1; i < vertices; ++i) {
        cout << "Enter the number of vertices corresponding to " << i << " vertex:" << endl;
        cin >> number;
        if (number == 0) {
            continue;
        }
        cout << "Enter a list of vertices separated by a space corresponding to " << i << " vertex:" << endl;
        // Информация о вершине.
        int vertex;
        for (int j = 1; j < vertices; ++j) {
            if (number == 0) {
                break;
            }
            cin >> vertex;
            graph_input[i][j] = vertex;
            number -= 1;
        }
    }
}

// Считывание данных о списке рёбр с консоли.
// Пользователю выводятся подсказки о правильном вводе данных.
void GraphConsoleInputFourth(vector<vector<int>> &graph_input, int vertices, int rows) {
    int count = 1;
    int number;
    cout << "Enter the number of neighbors for " << count << " vertex:" << endl;
    cin >> number;
    // Информация о вершине.
    int vertex;
    // Номер соседа вершины.
    int neighbor = 1;
    for (int i = 0; i < rows; ++i) {
        if (number == 0) {
            count += 1;
            neighbor = 1;
            cout << "Enter the number of neighbors for " << count << " vertex:" << endl;
            cin >> number;
        }
        cout << "Enter " << neighbor << " neighbor of " << count << " vertex:" << endl;
        cin >> vertex;
        graph_input[i][0] = count;
        graph_input[i][1] = vertex;
        number -= 1;
        neighbor += 1;
    }
}