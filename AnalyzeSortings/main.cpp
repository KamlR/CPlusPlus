// АИСД 2, 2023, задание 5
// Мавлетова Карина Радиковна, БПИ216


#include "ArrayOperations.h"
#include "ArrayTime.h"
#include "SortingOperations.h"
#include "sorting_operations.h"
#include "sorting_time.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> zeroToFive;
std::vector<int> zeroToFourThousand;
std::vector<int> almostSorted;
std::vector<int> reverseOrder;
std::vector<std::string> nameSort;

// Метод для чтения массивов, с которыми я работаю в программе
void fillVectors() {
    zeroToFive = std::vector<int>(4100);
    zeroToFourThousand = std::vector<int>(4100);
    almostSorted = std::vector<int>(4100);
    reverseOrder = std::vector<int>(4100);
    int a, b, c, d;
    std::ifstream first("one_to_five.txt");
    std::ifstream second("zero_to_thousands.txt");
    std::ifstream third("almost_sorted.txt");
    std::ifstream fourth("reverse.txt");
    for (int i = 0; i < 4100; ++i) {
        first >> a;
        second >> b;
        third >> c;
        fourth >> d;
        zeroToFive[i] = a;
        zeroToFourThousand[i] = b;
        almostSorted[i] = c;
        reverseOrder[i] = d;
    }
    first.close();
    second.close();
    third.close();
    fourth.close();
}

// Для тестирования сортировок на массиве чисел от 0 до 5
void randomZeroToFive(void (*sortFunc)(std::vector<int> &nums, int n), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFive"
       << "\n";
    std::cout << "RandomZeroToFive, "
              << "50 - 300, " << nameSort[index_name] << "\n";
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
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFive"
       << "\n";
    std::cout << "RandomZeroToFive, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
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

// Для тестирования сортиовок на массиве чисел от 0 до 4000
void randomZeroToFourThousand(void (*sortFunc)(std::vector<int> &nums, int n), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFourThousand"
       << "\n";
    std::cout << "RandomZeroToFourThousand, "
              << "50 - 300, " << nameSort[index_name] << "\n";
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
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomZeroToFourThousand"
       << "\n";
    std::cout << "RandomZeroToFourThousand, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
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

// Для тестирования всех сортировок на массиве почти отсорт. чисел
void randomAlmostSorted(void (*sortFunc)(std::vector<int> &nums, int n), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomAlmostSorted"
       << "\n";
    std::cout << "AlmostSorted, "
              << "50 - 300, " << nameSort[index_name] << "\n";
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
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomAlmostSorted"
       << "\n";
    std::cout << "AlmostSorted, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
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

// Для тестирования всех сортировок на массиве в обратном порядке
void randomReverseOrder(void (*sortFunc)(std::vector<int> &nums, int n), int index_name) {
    std::fstream fs;
    fs.open(nameSort[index_name] + " 50 - 300.txt", std::fstream::out | std::fstream::app);
    fs << "RandomReverseOrder"
       << "\n";
    std::cout << "ReverseOrder, "
              << "50 - 300, " << nameSort[index_name] << "\n";
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
    fs.open(nameSort[index_name] + " 100 - 4100.txt", std::fstream::out | std::fstream::app);
    fs << "RandomReverseOrder"
       << "\n";
    std::cout << "ReverseOrder, "
              << "100 - 4100, " << nameSort[index_name] << "\n";
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


int main() {
    fillVectors();
    nameSort = std::vector<std::string>{"selection_sort", "bubble_sort", "bubble_iverson1", "bubble_iverson2", "insertion_sort", "binary_insertion_sort", "count_sort", "radix_sort", "merge_sort", "quick_sort", "heap_sort", "shell_sort", "cyurania_sequence"};
    // Массивы указателей на функции
    void (*sort[13])(std::vector<int> &, int) = {selectionSort, bubbleSort, bubbleSortIverson1, bubbleSortIverson2, insertionSort, binaryInsertionSort, countSort, radixSort, mergeSortS, quickSortQ, heapSort, shellSort, cyuSequenceSort};
    uint64_t (*sortCount[13])(std::vector<int> &, int) = {selectionSortOp, bubbleSortOp, bubbleSortIverson1Op, bubbleSortIverson2Op, insertionSortOp, binaryInsertionSortOp, countSortOp, radixSortOp, mergeSortSOp, quickSortQOp, heapSortOp, shellSortOp, cyuSequenceSortOp};
    // Каждую сортировку прогоняю на всех 4 массивах по времени
//    for (int i = 0; i < 13; ++i) {
//        for (int j = 0; j < 4; ++j) {
//            if (j == 0) {
//                randomZeroToFive(sort[i], i);
//            } else if (j == 1) {
//                randomZeroToFourThousand(sort[i], i);
//            } else if (j == 2) {
//                randomAlmostSorted(sort[i], i);
//            } else {
//                randomReverseOrder(sort[i], i);
//            }
//        }
//    }
//
//    // Каждый массив прогоняю на всех 13 сортировках по времени
//    ArrayTime arrayTime(zeroToFive, zeroToFourThousand, almostSorted, reverseOrder, nameSort);
//    for (int i = 0; i < 4; ++i) {
//        for (int j = 0; j < 13; ++j) {
//            if (i == 0) {
//                arrayTime.randomZeroToFive(sort[j], j);
//            } else if (i == 1) {
//                arrayTime.randomZeroToFourThousand(sort[j], j);
//            } else if (i == 2) {
//                arrayTime.randomAlmostSorted(sort[j], j);
//            } else if (i == 3) {
//                arrayTime.randomReverseOrder(sort[j], j);
//            }
//        }
//    }

    // Каждую сортировку прогоняю на всех 4 массивах по операциям
    SortingOperations sortingOperations(zeroToFive, zeroToFourThousand, almostSorted, reverseOrder, nameSort);
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j == 0) {
                sortingOperations.randomZeroToFive(sortCount[i], i);
            } else if (j == 1) {
                sortingOperations.randomZeroToFourThousand(sortCount[i], i);
            } else if (j == 2) {
                sortingOperations.randomAlmostSorted(sortCount[i], i);
            } else {
                sortingOperations.randomReverseOrder(sortCount[i], i);
            }
        }
    }

    // Каждый массив прогоняю на всех 13 сортировках по операциям
    ArrayOperations arrayOperations(zeroToFive, zeroToFourThousand, almostSorted, reverseOrder, nameSort);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (i == 0) {
                arrayOperations.randomZeroToFive(sortCount[j], j);
            } else if (i == 1) {
                arrayOperations.randomZeroToFourThousand(sortCount[j], j);
            } else if (i == 2) {
                arrayOperations.randomAlmostSorted(sortCount[j], j);
            } else if (i == 3) {
                arrayOperations.randomReverseOrder(sortCount[j], j);
            }
        }
    }
}
