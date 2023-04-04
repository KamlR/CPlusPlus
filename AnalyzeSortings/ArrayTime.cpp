#include "ArrayTime.h"
#include <chrono>
#include <fstream>
#include <iostream>


// Просто отдельный класс для вызова методов, которые каждый массив прогоняют на сортировках по времени
ArrayTime::ArrayTime(std::vector<int> &zeroToFive, std::vector<int> &zeroToFourThousand, std::vector<int> &almostSorted,
                     std::vector<int> &reverseOrder, std::vector<std::string> &nameSort) {
    this->zeroToFive = zeroToFive;
    this->zeroToFourThousand = zeroToFourThousand;
    this->almostSorted = almostSorted;
    this->reverseOrder = reverseOrder;
    this->nameSort = nameSort;
}

void ArrayTime::randomZeroToFive(void (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_zero_to_five 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFive " << nameSort[index_name] << " 50 - 300\n";
    uint64_t sum;
    uint64_t nanoseconds;
    for (int i = 50; i <= 300; i += 50) {
        sum = 0;
        std::vector<int> vec;
        std::copy(zeroToFive.begin(), zeroToFive.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 50; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        vec.clear();
        fs << i << " " << sum / 50 << "\n";
        std::cout << "Size: " << i << " time: " << sum / 50 << "\n";
    }
    fs.close();
    fs.open("random_zero_to_five 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFive " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        sum = 0;
        std::vector<int> vec;
        std::copy(zeroToFive.begin(), zeroToFive.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 20; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 20 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 20 << "\n";
    }
    fs.close();
}
void ArrayTime::randomZeroToFourThousand(void (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_zero_to_four_thousand 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFourThousand " << nameSort[index_name] << " 50 - 300\n";
    uint64_t sum;
    uint64_t nanoseconds;
    for (int i = 50; i <= 300; i += 50) {
        sum = 0;
        std::vector<int> vec;
        std::copy(zeroToFourThousand.begin(), zeroToFourThousand.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 50; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 50 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 50 << "\n";
    }
    fs.close();
    fs.open("random_zero_to_four_thousand 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomZeroToFourThousand " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        sum = 0;
        std::vector<int> vec;
        std::copy(zeroToFourThousand.begin(), zeroToFourThousand.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 20; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 20 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 20 << "\n";
    }
}
void ArrayTime::randomAlmostSorted(void (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_almost_sorted 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomAlmostSorted " << nameSort[index_name] << " 50 - 300\n";
    uint64_t sum;
    uint64_t nanoseconds;
    for (int i = 50; i <= 300; i += 50) {
        sum = 0;
        std::vector<int> vec;
        std::copy(almostSorted.begin(), almostSorted.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 50; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 50 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 50 << "\n";
    }
    fs.close();
    fs.open("random_almost_sorted 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomAlmostSorted " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        sum = 0;
        std::vector<int> vec;
        std::copy(almostSorted.begin(), almostSorted.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 20; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 20 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 20 << "\n";
    }
    fs.close();
}
void ArrayTime::randomReverseOrder(void (*sortFunc)(std::vector<int> &, int), int index_name) {
    std::fstream fs;
    fs.open("random_reverse_order 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomReverseOrder " << nameSort[index_name] << " 50 - 300\n";
    uint64_t sum;
    uint64_t nanoseconds;
    for (int i = 50; i <= 300; i += 50) {
        sum = 0;
        std::vector<int> vec;
        std::copy(reverseOrder.begin(), reverseOrder.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 50; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 50 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 50 << "\n";
    }
    fs.close();
    fs.open("random_reverse_order 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "N" + nameSort[index_name] << "\n";
    std::cout << "RandomReverseOrder " << nameSort[index_name] << " 100 - 4100\n";
    for (int i = 100; i <= 4100; i += 100) {
        sum = 0;
        std::vector<int> vec;
        std::copy(reverseOrder.begin(), reverseOrder.begin() + i, std::back_inserter(vec));
        for (int j = 0; j < 20; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            sortFunc(vec, i);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        fs << i << " " << sum / 20 << "\n";
        vec.clear();
        std::cout << "Size: " << i << " time: " << sum / 20 << "\n";
    }
    fs.close();
}
