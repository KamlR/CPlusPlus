#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Класс для хранения информации о графе.
class HouseOfGraphs {
    // Текущее названия вида хранения графа.
    string currentName;
    // Вектор для текущего хранения графа.
    vector<vector<int>> current_graph;
    // Вектор для хранения текущего графа в виде матрицы смежности.
    vector<vector<int>> adjacency_matrix;
    // Кол-во вершин.
    int vertices;
    // Кол-во рёбр.
    int edges;
public:
    // Конструктор для инициализации нужных полей.
    HouseOfGraphs(string currentName, vector<vector<int>> current_graph,
                  int vertices, int edges);

    // Конструктор по умолчанию.
    HouseOfGraphs();

public:
    // Для обработки данных вывода в консоль.
    void FirstCheckConsole(string &name);

    // Для обработки данных вывода в файл.
    void FirstCheckFile(string &name);

    // Вывод матрицы смежности в консоль.
    void AdjacencyMatrixOutputConsole();

    // Вывод матрицы инцидентности в консоль.
    void IncidenceMatrixOutputConsole();

    // Вывод списка смежности в консоль.
    void AdjacencyListOutputConsole();

    // Вывод списка рёбр в консоль.
    void ListOfEdgesOutputConsole();

public:
    // Перевод из матрицы инцидентности в матрицу смежности.
    void FromSecondToAm();

    // Перевод из списка смежности в матрицу смежности.
    void FromThirdToAm();

    // Перевод из списка рёбр в матрицу смежности.
    void FromFourthToAm();

    // Дополнительный вывод для матрицы смежности в консоль.
    void PrintTranslateGraph();

public:
    // Перевод из матрицы смежности в матрицу инцидентности.
    void FromAmToSecond();

    // Перевод из матрицы смежности в список смежности.
    void FromAmToThird();

    // Перевод из матрицы смежности в список рёбр.
    void FromAmToFourth();

public:
    // Вывод матрицы смежности в файл.
    void AdjacencyMatrixOutputFile(string &path);

    // Вывод матрицы инцидентности в файл.
    void IncidenceMatrixOutputFile(string &path);

    // Вывод списка смежности в файл.
    void AdjacencyListOutputFile(string &path);

    // Вывод списка рёбр в файл.
    void ListOfEdgesOutputFile(string &path);

public:
    // Подсчёт степеней вершин для ориентированного графа.
    void VertexOriented();

    // Подсчёт степеней вершин для неориентированного графа.
    void VertexNotOriented();

    // Подсчёт рёбр/дуг.
    void EdgesCount(int number);

    // Дополнительный переовод из матрицы смежности в матрицу инцидентности.
    vector<vector<int>> HelpToSecond();
};



