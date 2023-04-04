#include "SortingOperations.h"
#include <fstream>
#include <iostream>

// Просто отдельный класс для вызова методов, которые каждую сортровку прогоняют на 4 массивах по операциям
SortingOperations::SortingOperations(std::vector<int> &zeroToFive, std::vector<int> &zeroToFourThousand,
                                     std::vector<int> &almostSorted, std::vector<int> &reverseOrder,
                                     std::vector<std::string> &nameSort) {
    this->zeroToFive = zeroToFive;
    this->zeroToFourThousand = zeroToFourThousand;
    this->almostSorted = almostSorted;
    this->reverseOrder = reverseOrder;
    this->nameSort = nameSort;
}
void SortingOperations::randomZeroToFive(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFive"
       << "\n";
    std::cout << "RandomZeroToFive, "
              << "50 - 300, " << nameSort[index_name] << "\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(zeroToFive.begin(), zeroToFive.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFive"
       << "\n";
    std::cout << "RandomZeroToFive, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(zeroToFive.begin(), zeroToFive.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
void SortingOperations::randomZeroToFourThousand(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFourThousand"
       << "\n";
    std::cout << "RandomZeroToFourThousand, "
              << "50 - 300, " << nameSort[index_name] << "\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(zeroToFourThousand.begin(), zeroToFourThousand.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFourThousand"
       << "\n";
    std::cout << "RandomZeroToFourThousand, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(zeroToFourThousand.begin(), zeroToFourThousand.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
void SortingOperations::randomAlmostSorted(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomAlmostSorted"
       << "\n";
    std::cout << "RandomAlmostSorted, "
              << "50 - 300, " << nameSort[index_name] << "\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(almostSorted.begin(), almostSorted.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomAlmostSorted"
       << "\n";
    std::cout << "RandomAlmostSorted, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(almostSorted.begin(), almostSorted.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
void SortingOperations::randomReverseOrder(uint64_t (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomReverseOrder"
       << "\n";
    std::cout << "RandomReverseOrder, "
              << "50 - 300, " << nameSort[index_name] << "\n";
    for (int i = 50; i <= 300; i += 50) {
        std::vector<int> vec;
        std::copy(reverseOrder.begin(), reverseOrder.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomReverseOrder"
       << "\n";
    std::cout << "RandomReverseOrder, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::vector<int> vec;
        std::copy(reverseOrder.begin(), reverseOrder.begin() + i, std::back_inserter(vec));
        fs << i << " " << sortFunc(vec, i) << "\n";
        std::cout << "Size: " << i << " operations: " << sortFunc(vec, i) << "\n";
    }
    fs.close();
}
