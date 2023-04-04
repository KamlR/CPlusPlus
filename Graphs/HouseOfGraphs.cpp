#include "HouseOfGraphs.h"

HouseOfGraphs::HouseOfGraphs(string currentName, vector<vector<int>> current_graph,
                             int vertices, int edges) {
    this->currentName = currentName;
    this->current_graph = current_graph;
    this->vertices = vertices;
    this->edges = edges;
    if (currentName == "adjacency matrix") {
        adjacency_matrix = current_graph;
    } else if (currentName == "incidence matrix") {
        FromSecondToAm();
    } else if (currentName == "adjacency list") {
        FromThirdToAm();
    } else if (currentName == "list of edges") {
        FromFourthToAm();
    }

}

HouseOfGraphs::HouseOfGraphs() {}

// Вывод матрицы смежности в консоль.
void HouseOfGraphs::AdjacencyMatrixOutputConsole() {
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            cout << current_graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Вывод матрицы инцидентности в консоль.
void HouseOfGraphs::IncidenceMatrixOutputConsole() {
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < edges + 1; ++j) {
            cout << current_graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Вывод списка смежности в консоль.
void HouseOfGraphs::AdjacencyListOutputConsole() {
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            if (current_graph[i][j] != 0) {
                cout << current_graph[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Вывод списка рёбр в консоль.
void HouseOfGraphs::ListOfEdgesOutputConsole() {
    for (size_t i = 0; i < current_graph.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << current_graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Проверка, какой граф должен быть выведен и сохранён.
// Вызов методов переводов и выводов графов.
void HouseOfGraphs::FirstCheckConsole(string &name) {
    if (name == currentName) {
        if (name == "adjacency matrix") {
            AdjacencyMatrixOutputConsole();
        } else if (name == "incidence matrix") {
            IncidenceMatrixOutputConsole();
        } else if (name == "adjacency list") {
            AdjacencyListOutputConsole();
        } else {
            ListOfEdgesOutputConsole();
        }
    } else {
        if (name == "adjacency matrix") {
            PrintTranslateGraph();
            current_graph.clear();
            current_graph = adjacency_matrix;
            currentName = "adjacency matrix";
        } else if (name == "incidence matrix") {
            FromAmToSecond();
            IncidenceMatrixOutputConsole();
        } else if (name == "adjacency list") {
            FromAmToThird();
            AdjacencyListOutputConsole();
        } else if (name == "list of edges") {
            FromAmToFourth();
            ListOfEdgesOutputConsole();
        }
    }
}

// Перевод из матрицы инцидентности в матрицу смежности.
// Изначально заполняются сами границы, затем ячейки вектора.
void HouseOfGraphs::FromSecondToAm() {
    vector<vector<int>> translate(vertices + 1, vector<int>(vertices + 1));
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            if (i == 0) {
                translate[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                translate[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    for (int i = 1; i < vertices + 1; ++i) {
        for (int j = 1; j < edges + 1; ++j) {
            if (current_graph[i][j] == 1) {
                for (int k = 1; k < vertices + 1; ++k) {
                    if (k != i && current_graph[k][j] != 0) {
                        translate[i][k] = 1;
                    }
                }
            }
        }
    }
    adjacency_matrix = translate;
}

// Перевод из списка смежности в матрицу смежности.
// Всё построено на том, что вершины исходного вектора уже являются индексами для заполнения нового.
void HouseOfGraphs::FromThirdToAm() {
    vector<vector<int>> translate(vertices + 1, vector<int>(vertices + 1));
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            if (i == 0) {
                translate[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                translate[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    for (int i = 1; i < vertices + 1; ++i) {
        for (int j = 1; j < vertices + 1; ++j) {
            if (current_graph[i][j] != 0) {
                translate[i][current_graph[i][j]] = 1;
            }
        }
    }
    adjacency_matrix = translate;
}

// Перевод из списка рёбр в матрицу смежности.
// Всё построено на том, что вершины исходного вектора уже являются индексами для заполнения нового.
void HouseOfGraphs::FromFourthToAm() {
    vector<vector<int>> translate(vertices + 1, vector<int>(vertices + 1));
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            if (i == 0) {
                translate[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                translate[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    for (int i = 0; i < current_graph.size(); ++i) {
        translate[current_graph[i][0]][current_graph[i][1]] = 1;
    }
    adjacency_matrix = translate;
}

// Дополнительный вывод для матрицы смежности в консоль.
// Используется, если не нужно использовать перевод.
void HouseOfGraphs::PrintTranslateGraph() {
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Перевод из матрицы смежности в матрицу инцидентности.
// Исохдный вектор очищается и граф сохраняется в новом виде.
void HouseOfGraphs::FromAmToSecond() {
    vector<vector<int>> translate(vertices + 1, vector<int>(edges + 1));
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < edges + 1; ++j) {
            if (i == 0) {
                translate[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                translate[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    int count_edge = 1;
    for (int i = 1; i < vertices + 1; ++i) {
        for (int j = 1; j < vertices + 1; ++j) {
            if (adjacency_matrix[i][j] == 1 && i <= j) {
                translate[i][count_edge] = 1;
                if (adjacency_matrix[j][i] == 0) {
                    translate[j][count_edge] = -1;
                } else {
                    translate[j][count_edge] = 1;
                }
                count_edge += 1;
            } else if (adjacency_matrix[i][j] == 0 && i <= j) {
                if (adjacency_matrix[j][i] != 0) {
                    translate[j][count_edge] = 1;
                    translate[i][count_edge] = -1;
                    count_edge += 1;
                }
            }
        }
    }
    current_graph.clear();
    current_graph = translate;
    currentName = "incidence matrix";
}

// Перевод из матрицы смежности в список смежности.
// Исохдный вектор очищается и граф сохраняется в новом виде.
void HouseOfGraphs::FromAmToThird() {
    vector<vector<int>> translate(vertices + 1, vector<int>(vertices + 1));
    int index_col;
    for (int i = 1; i < vertices + 1; ++i) {
        index_col = 1;
        for (int j = 1; j < vertices + 1; ++j) {
            if (adjacency_matrix[i][j] == 1) {
                if (translate[i][0] == 0) {
                    translate[i][0] = i;
                }
                translate[i][index_col] = j;
                index_col += 1;
            }
        }
    }
    current_graph.clear();
    current_graph = translate;
    currentName = "adjacency list";
}

// Перевод из матрицы смежности в список рёбр.
// Исохдный вектор очищается и граф сохраняется в новом виде.
void HouseOfGraphs::FromAmToFourth() {
    // Число рядов.
    int rows = 0;
    for (int i = 1; i < vertices + 1; ++i) {
        for (int j = 1; j < vertices + 1; ++j) {
            if (adjacency_matrix[i][j] == 1) {
                rows += 1;
            }
        }
    }
    // Текущий ряд.
    int row_count = 0;
    vector<vector<int>> translate(rows, vector<int>(2));
    for (int i = 1; i < vertices + 1; ++i) {
        for (int j = 1; j < vertices + 1; ++j) {
            if (adjacency_matrix[i][j] == 1) {
                translate[row_count][0] = i;
                translate[row_count][1] = j;
                row_count += 1;
            }
        }
    }
    current_graph.clear();
    current_graph = translate;
    currentName = "list of edges";
}

// Проверка, какой граф должен быть выведен и сохранён.
// Вызов методов переводов и выводов графов.
void HouseOfGraphs::FirstCheckFile(string &name) {
    string path;
    cout << "Enter the name of the file for output" << endl;
    cin >> path;
    if (name == currentName) {
        if (name == "adjacency matrix") {
            AdjacencyMatrixOutputFile(path);
        } else if (name == "incidence matrix") {
            IncidenceMatrixOutputFile(path);
        } else if (name == "adjacency list") {
            AdjacencyListOutputFile(path);
        } else {
            ListOfEdgesOutputFile(path);
        }
    } else {
        if (name == "adjacency matrix") {
            current_graph.clear();
            current_graph = adjacency_matrix;
            currentName = "adjacency matrix";
            AdjacencyMatrixOutputFile(path);
        } else if (name == "incidence matrix") {
            FromAmToSecond();
            IncidenceMatrixOutputFile(path);
        } else if (name == "adjacency list") {
            FromAmToThird();
            AdjacencyListOutputFile(path);
        } else if (name == "list of edges") {
            FromAmToFourth();
            ListOfEdgesOutputFile(path);
        }
    }
}

// Вывод матрицы смежности в файл.
// Разница с консольным выводом только в другом потоке.
void HouseOfGraphs::AdjacencyMatrixOutputFile(string &path) {
    ofstream flow(path);
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            flow << current_graph[i][j] << " ";
        }
        flow << endl;
    }
    cout << "The graph has been successfully written to the file" << endl;
}

// Вывод матрицы инцидентности в файл.
// Разница с консольным выводом только в другом потоке.
void HouseOfGraphs::IncidenceMatrixOutputFile(string &path) {
    ofstream flow(path);
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < edges + 1; ++j) {
            flow << current_graph[i][j] << " ";
        }
        flow << endl;
    }
    cout << "The graph has been successfully written to the file" << endl;
}

// Вывод списка смежности в файл.
// Разница с консольным выводом только в другом потоке.
void HouseOfGraphs::AdjacencyListOutputFile(string &path) {
    ofstream flow(path);
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < vertices + 1; ++j) {
            if (current_graph[i][j] != 0) {
                flow << current_graph[i][j] << " ";
            }
        }
        flow << endl;
    }
    cout << "The graph has been successfully written to the file" << endl;
}

// Вывод списка рёбр в файл.
// Разница с консольным выводом только в другом потоке.
void HouseOfGraphs::ListOfEdgesOutputFile(string &path) {
    ofstream flow(path);
    for (size_t i = 0; i < current_graph.size(); ++i) {
        for (int j = 0; j < 2; ++j) {
            flow << current_graph[i][j] << " ";
        }
        flow << endl;
    }
    cout << "The graph has been successfully written to the file" << endl;
}

// Подсчёт полкстепеней вершин для ориентированного графа.
// Используется матрица инциденцности.
void HouseOfGraphs::VertexOriented() {
    vector<vector<int>> translate = HelpToSecond();
    for (int i = 1; i < vertices + 1; ++i) {
        int comesOut = 0;
        int comesIn = 0;
        for (int j = 1; j < edges + 1; ++j) {
            if (translate[i][j] == 1) {
                comesOut += 1;
            } else if (translate[i][j] == -1) {
                comesIn += 1;
            }
        }
        cout << "For " << i << " vertex:  " << "comes out - " << comesOut << ", " << " comes in - " << comesIn << endl;
    }
}

// Подсчёт полкстепеней вершин для неориентированного графа.
// Используется матрица смежности.
void HouseOfGraphs::VertexNotOriented() {
    for (int i = 1; i < vertices + 1; ++i) {
        int count = 0;
        for (int j = 1; j < vertices + 1; ++j) {
            if (adjacency_matrix[i][j] == 1) {
                count += 1;
            }
        }
        cout << "For " << i << " vertex: " << count << endl;
    }
}

// Дополнительный переовод из матрицы смежности в матрицу инцидентности.
// Основной перевод заточен под сохранение графа в новом виде, здесь такого не требуется.
vector<vector<int>> HouseOfGraphs::HelpToSecond() {
    vector<vector<int>> translate(vertices + 1, vector<int>(edges + 1));
    int count_horizontal = 0;
    int count_vertical = 0;
    for (int i = 0; i < vertices + 1; ++i) {
        for (int j = 0; j < edges + 1; ++j) {
            if (i == 0) {
                translate[i][j] = count_horizontal;
                count_horizontal += 1;
            }
            if (j == 0) {
                translate[i][j] = count_vertical;
                count_vertical += 1;
            }
        }
    }
    int count_edge = 1;
    for (int i = 1; i < vertices + 1; ++i) {
        for (int j = 1; j < vertices + 1; ++j) {
            if (adjacency_matrix[i][j] == 1 && i <= j) {
                translate[i][count_edge] = 1;
                if (adjacency_matrix[j][i] == 0) {
                    translate[j][count_edge] = -1;
                } else {
                    translate[j][count_edge] = 1;
                }
                count_edge += 1;
            } else if (adjacency_matrix[i][j] == 0 && i <= j) {
                if (adjacency_matrix[j][i] != 0) {
                    translate[j][count_edge] = 1;
                    translate[i][count_edge] = -1;
                    count_edge += 1;
                }
            }
        }
    }
    return translate;
}

// Подсчёт рёбр/дуг.
// Используется матрица смежности или же данные, введённые пользователем.
void HouseOfGraphs::EdgesCount(int point) {
    if (point == 1) {
        int count = 0;
        for (int i = 1; i < vertices + 1; ++i) {
            for (int j = 1; j < vertices + 1; ++j) {
                if (adjacency_matrix[i][j] == 1) {
                    count++;
                }
            }
        }
        cout << "Number of arcs: " << count << endl;
    } else {
        cout << "Number of edges: " << edges << endl;
    }
}