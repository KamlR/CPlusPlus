#include <iostream>
#include <vector>
#include "HouseOfGraphs.h"
#include "ConsoleInput.h"
#include "FileInput.h"

using namespace std;

// Заголовок метода для работы с функциями графа
void WorkWithGraph(HouseOfGraphs &house);


// Заголовок метода для подсчёта кол-ва вершин.
void CountVertices(HouseOfGraphs &house);

// Заголовок метода для подсчёта кол-ва рёбр.
void CountEdges(HouseOfGraphs &house);

// Работа с консольным вводом графа.
// Вызов соответствующих методов для ввода графа в разных форматах.
// Производится создание объектов класса HouseOfGraphs.
HouseOfGraphs WorkWithConsole() {
    cout << "Select the way of input your graph (enter a number):" << "\n"
         << "In this format, the graph will initially be stored!" << endl;
    vector<string> waysOfInput{"adjacency matrix", "incidence matrix",
                               "adjacency list", "list of edges"};
    for (size_t i = 0; i < waysOfInput.size(); ++i) {
        cout << i + 1 << ") " << waysOfInput[i] << endl;
    }
    // номер ввода, кол-во вершин, кол-во рёбр.
    int number, vertices, edges;
    cin >> number;
    cout << "Enter the number of vertices" << endl;
    cin >> vertices;
    cout << "Enter the number of edges" << endl;
    cin >> edges;
    if (number == 1) {
        vector<vector<int>> graph_input1(vertices + 1, vector<int>(vertices + 1));
        GraphConsoleInputFirst(graph_input1, vertices);
        HouseOfGraphs house = HouseOfGraphs("adjacency matrix", graph_input1, vertices, edges);
        return house;
    } else if (number == 2) {
        vector<vector<int>> graph_input2(vertices + 1, vector<int>(edges + 1));
        GraphConsoleInputSecond(graph_input2, vertices, edges);
        HouseOfGraphs house = HouseOfGraphs("incidence matrix", graph_input2, vertices, edges);
        return house;
    } else if (number == 3) {
        vector<vector<int>> graph_input3(vertices + 1, vector<int>(vertices + 1));
        GraphConsoleInputThird(graph_input3, vertices);
        HouseOfGraphs house = HouseOfGraphs("adjacency list", graph_input3, vertices, edges);
        return house;
    } else if (number == 4) {
        int rows;
        cout << "Enter the number of rows in this view:" << endl;
        cin >> rows;
        vector<vector<int>> graph_input4(rows, vector<int>(2));
        GraphConsoleInputFourth(graph_input4, vertices, rows);
        HouseOfGraphs house = HouseOfGraphs("list of edges", graph_input4, vertices, edges);
        return house;
    }
    HouseOfGraphs houseNew = HouseOfGraphs();
    return houseNew;
}

// Метод очень похож на прошлый, но здесь работа идёт с файлом.
// Все графы считываются из файлов.
HouseOfGraphs WorkWithFile() {
    cout << "Select the way of input your graph (enter a number):" << "\n"
         << "In this format, the graph will initially be stored!" << endl;
    vector<string> waysOfInput{"adjacency matrix", "incidence matrix",
                               "adjacency list", "list of edges"};
    for (size_t i = 0; i < waysOfInput.size(); ++i) {
        cout << i + 1 << ") " << waysOfInput[i] << endl;
    }
    // Номер ввода, кол-во вершин, кол-во рёбр.
    int number, vertices, edges;
    string path;
    cin >> number;
    cout << "Enter the path to the file(near the .exe):" << endl;
    cin >> path;
    cout << "Enter the number of vertices" << endl;
    cin >> vertices;
    cout << "Enter the number of edges" << endl;
    cin >> edges;
    if (number == 1) {
        vector<vector<int>> graph_input1(vertices + 1, vector<int>(vertices + 1));
        GraphFileInputFirst(graph_input1, vertices, path);
        HouseOfGraphs house = HouseOfGraphs("adjacency matrix", graph_input1, vertices, edges);
        return house;
    } else if (number == 2) {
        vector<vector<int>> graph_input2(vertices + 1, vector<int>(edges + 1));
        GraphFileInputSecond(graph_input2, vertices, edges, path);
        HouseOfGraphs house = HouseOfGraphs("incidence matrix", graph_input2, vertices, edges);
        return house;
    } else if (number == 3) {
        vector<vector<int>> graph_input3(vertices + 1, vector<int>(vertices + 1));
        GraphFileInputThird(graph_input3, vertices, path);
        HouseOfGraphs house = HouseOfGraphs("adjacency list", graph_input3, vertices, edges);
        return house;
    } else if (number == 4) {
        int lines;
        cout << "Enter the number of lines in your file:" << endl;
        cin >> lines;
        vector<vector<int>> graph_input4(lines, vector<int>(2));
        GraphFileInputFourth(graph_input4, lines, path);
        HouseOfGraphs house = HouseOfGraphs("list of edges", graph_input4, vertices, edges);
        return house;
    }
    HouseOfGraphs houseNew = HouseOfGraphs();
    return houseNew;
}

// Пользователю предлагается вид ввода графа
// В зависимости от выбора ввода вызываются нужные методы.
HouseOfGraphs Begin() {
    cout << "Hello!" << "\n" << "Here is an application for working with graphs:)" << endl;
    cout << "Select the way of input your graph (enter a number):" << endl;
    cout << "1) console" << "\n" << "2) file" << endl;
    int number;
    while (true) {
        cin >> number;
        if (number == 1) {
            HouseOfGraphs house = WorkWithConsole();
            return house;
        } else if (number == 2) {
            HouseOfGraphs house = WorkWithFile();
            return house;
        }
    }
}

// Входная точка программы.
// Реализация повтора решения.
int main() {
    int finish_first;
    int finish_second;
    do {
        HouseOfGraphs house = Begin();
        do {
            WorkWithGraph(house);
            cout << "To finish tne program or print a new graph enter 1, else 0" << endl;
            cin >> finish_second;
        } while (finish_second != 1);
        cout << "To finish tne program enter 1, else 0" << endl;
        cin >> finish_first;
    } while (finish_first != 1);

    return 0;
}

// Графа выводится в выбранном представлении в консоль.
// Вызывается метод класса для дальнейшей обработки.
void OutputToConsole(HouseOfGraphs &house) {
    // Номер ввода.
    int number;
    cout << "In what form do you want to output and save the graph:" << endl;
    vector<string> waysOfInput{"adjacency matrix", "incidence matrix",
                               "adjacency list", "list of edges"};
    for (size_t i = 0; i < waysOfInput.size(); ++i) {
        cout << i + 1 << ") " << waysOfInput[i] << endl;
    }
    cin >> number;
    house.FirstCheckConsole(waysOfInput[number - 1]);
}

// Графа выводится в выбранном представлении в файл.
// Вызывается метод класса для дальнейшей обработки.
void OutputToFile(HouseOfGraphs &house) {
    int number;
    cout << "In what form do you want to output and save the graph:" << endl;
    vector<string> waysOfInput{"adjacency matrix", "incidence matrix",
                               "adjacency list", "list of edges"};
    for (size_t i = 0; i < waysOfInput.size(); ++i) {
        cout << i + 1 << ") " << waysOfInput[i] << endl;
    }
    cin >> number;
    house.FirstCheckFile(waysOfInput[number - 1]);
}

// Пользователь выбирает, какую информацию он хочет получить о графе.
// Также может вывести и сохранить граф в новом представлении.
void WorkWithGraph(HouseOfGraphs &house) {
    int number;
    vector<string> menu{"counting degrees or half-degrees of graph vertices",
                        "counting the number of edges or arcs",
                        "output and save the graph in the same or in a different representation"};
    for (int i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ") " << menu[i] << endl;
    }
    cin >> number;
    if (number == 1) {
        CountVertices(house);
    } else if (number == 2) {
        CountEdges(house);
    } else if (number == 3) {
        int point;
        cout << "Select the way of output your graph (enter a number):" << endl;
        cout << "1) console" << "\n" << "2) file" << endl;
        cin >> point;
        if (point == 1) {
            OutputToConsole(house);
        } else if (point == 2) {
            OutputToFile(house);
        }
    }
}

// Производится подсчёт степеней или полустепеней графа.
// Сам подсчёт производится в методе класса HouseOfGraphs, здесь лишь обработка запроса.
void CountVertices(HouseOfGraphs &house) {
    cout << "Is your graph oriented" << endl;
    vector<string> answer{"yes", "no"};
    for (int i = 0; i < 2; ++i) {
        cout << i + 1 << ") " << answer[i] << endl;
    }
    int number;
    cin >> number;
    if (number == 1) {
        house.VertexOriented();
    } else {
        house.VertexNotOriented();
    }
}

// Производится подсчёт рёбр или дуг графа.
// Сам подсчёт производится в методе класса HouseOfGraphs, здесь лишь обработка запроса.
void CountEdges(HouseOfGraphs &house) {
    cout << "Is your graph oriented" << endl;
    vector<string> answer{"yes", "no"};
    for (int i = 0; i < 2; ++i) {
        cout << i + 1 << ") " << answer[i] << endl;
    }
    int number;
    cin >> number;
    house.EdgesCount(number);
}