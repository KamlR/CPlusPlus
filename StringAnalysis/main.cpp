#include "DataGenerator.h"
#include "PatternSearch.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

/*
 * Этот метод используется для работы с подстановками символов.
 * Генерируются рандомные индексы, на которые будут подставлены знаки вопроса.
 */
void putQuestion(vector<char> &pattern, int count_subs, std::vector<int> &questions_pos) {
    int first, second, third, fourth;
    int size = static_cast<int>(pattern.size());
    if (count_subs == 1) {
        first = (rand() % (size - 0 + 1)) + 0;
        pattern[first] = '?';
        questions_pos.push_back(first);
    } else if (count_subs == 2) {
        first = (rand() % (size - 0 + 1)) + 0;
        second = (rand() % (size - 0 + 1)) + 0;
        pattern[first] = '?';
        pattern[second] = '?';
        questions_pos.push_back(first);
        questions_pos.push_back(second);
    } else if (count_subs == 3) {
        first = (rand() % (size - 0 + 1)) + 0;
        second = (rand() % (size - 0 + 1)) + 0;
        third = (rand() % (size - 0 + 1)) + 0;
        pattern[first] = '?';
        pattern[second] = '?';
        pattern[third] = '?';
        questions_pos.push_back(first);
        questions_pos.push_back(second);
        questions_pos.push_back(third);
    } else {
        first = (rand() % (size - 0 + 1)) + 0;
        second = (rand() % (size - 0 + 1)) + 0;
        third = (rand() % (size - 0 + 1)) + 0;
        fourth = (rand() % (size - 0 + 1)) + 0;
        pattern[first] = '?';
        pattern[second] = '?';
        pattern[third] = '?';
        pattern[fourth] = '?';
        questions_pos.push_back(first);
        questions_pos.push_back(second);
        questions_pos.push_back(third);
        questions_pos.push_back(fourth);
    }
}

/*
 * Метод, как и прошлый предназначен для работы с подстановками.
 * Здесь происходит составление всех возможных комбинаций символов, которые могут оказаться на местах вопросительных знаков.
 */
std::vector<std::string> getArrayWithSubs(int count_subs, std::vector<int> &alphabet) {
    std::vector<std::string> subs_combo = std::vector<string>();
    if (count_subs == 1) {
        for (int i = 0; i < alphabet.size(); ++i) {
            std::stringstream ss;
            ss << (char) alphabet[i];
            subs_combo.push_back(ss.str());
        }
    } else if (count_subs == 2) {
        for (int i = 0; i < alphabet.size(); ++i) {
            for (int j = 0; j < alphabet.size(); ++j) {
                std::stringstream ss;
                ss << (char) alphabet[i] << (char) alphabet[j];
                subs_combo.push_back(ss.str());
            }
        }
    } else if (count_subs == 3) {
        for (int i = 0; i < alphabet.size(); ++i) {
            for (int j = 0; j < alphabet.size(); ++j) {
                for (int k = 0; k < alphabet.size(); ++k) {
                    std::stringstream ss;
                    ss << (char) alphabet[i] << (char) alphabet[j] << (char) alphabet[k];
                    subs_combo.push_back(ss.str());
                }
            }
        }
    } else {
        for (int i = 0; i < alphabet.size(); ++i) {
            for (int j = 0; j < alphabet.size(); ++j) {
                for (int k = 0; k < alphabet.size(); ++k) {
                    for (int l = 0; l < alphabet.size(); ++l) {
                        std::stringstream ss;
                        ss << (char) alphabet[i] << (char) alphabet[j] << (char) alphabet[k] << (char) alphabet[l];
                        subs_combo.push_back(ss.str());
                    }
                }
            }
        }
    }
    return subs_combo;
}

/*
 * Метод, в котором обрабатывается каждый из 3 алгоритмов на бинарном алфавите из 10 000 символов.
 * Данные пишутся в файл, на основе которого потом строятся графики.
 * Для каждой длины шаблона прогоняются алгоритмы по 30 раз для усреднения.
 */
void binaryTextSmaller(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name) {
    std::fstream fs;
    fs.open("Binary 10 000.txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Binary text small:"
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    for (int i = 100; i < 3001; i += 100) {
        sum = 0;
        std::vector<char> pattern;
        std::copy(data.binary_smaller.begin(), data.binary_smaller.begin() + i, std::back_inserter(pattern));
        for (int j = 0; j < 30; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            answer = patternSearch(data.binary_smaller, pattern);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
        fs << i << " " << sum / 30 << "\n";
    }
    fs.close();
}

/*
 * Метод, в котором обрабатывается каждый из 3 алгоритмов на бинарном алфавите из 100 000 символов.
 * Данные пишутся в файл, на основе которого потом строятся графики.
 * Для каждой длины шаблона прогоняются алгоритмы по 30 раз для усреднения.
 */
void binaryTextBigger(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name) {
    std::fstream fs;
    fs.open("Binary 100 000.txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Binary text big:"
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    for (int i = 100; i < 3001; i += 100) {
        sum = 0;
        std::vector<char> pattern;
        std::copy(data.binary_bigger.begin(), data.binary_bigger.begin() + i, std::back_inserter(pattern));
        for (int j = 0; j < 30; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            answer = patternSearch(data.binary_bigger, pattern);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
        fs << i << " " << sum / 30 << "\n";
    }
    fs.close();
}

/*
 * Метод, в котором обрабатывается каждый из 3 алгоритмов на тексте из 10 000 символов. Текст составлен из 4 букв.
 * Данные пишутся в файл, на основе которого потом строятся графики.
 * Для каждой длины шаблона прогоняются алгоритмы по 30 раз для усреднения.
 */
void fourTextSmaller(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name) {
    std::fstream fs;
    fs.open("Four 10 000.txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Four text small:"
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    for (int i = 100; i < 3001; i += 100) {
        sum = 0;
        std::vector<char> pattern;
        std::copy(data.four_smaller.begin(), data.four_smaller.begin() + i, std::back_inserter(pattern));
        for (int j = 0; j < 30; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            answer = patternSearch(data.four_smaller, pattern);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
        fs << i << " " << sum / 30 << "\n";
    }
    fs.close();
}

/*
 * Метод, в котором обрабатывается каждый из 3 алгоритмов на тексте из 100 000 символов. Текст составлен из 4 букв.
 * Данные пишутся в файл, на основе которого потом строятся графики.
 * Для каждой длины шаблона прогоняются алгоритмы по 30 раз для усреднения.
 */
void fourTextBigger(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name) {
    std::fstream fs;
    fs.open("Four 100 000.txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Four text big:"
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    for (int i = 100; i < 3001; i += 100) {
        sum = 0;
        std::vector<char> pattern;
        std::copy(data.four_bigger.begin(), data.four_bigger.begin() + i, std::back_inserter(pattern));
        for (int j = 0; j < 30; ++j) {
            auto start = std::chrono::high_resolution_clock::now();
            answer = patternSearch(data.four_bigger, pattern);
            auto end = std::chrono::high_resolution_clock::now() - start;
            nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
            sum += nanoseconds;
        }
        std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
        fs << i << " " << sum / 30 << "\n";
    }
    fs.close();
}

/*
 * Обработка алгоритмов на тексте из 10 000 символом, который составлен на основе 2 букв.
 * Если приходит стандартный алгоритм, то просто на рандомные места ставим знаки вопроса и запускаем наш алгоритм.
 * В стандартном алгоритме заранее прописано, что символы совпадают, если они действительно совпали или же если стоит знак вопроса.
 * Если же мы берём два алгоритма  кмп, то здесь я при помощи метода  getArrayWithSubs получаем различные комбианции, которые могут стоять на месте вопросительных знаков.
 * Для каждой возможной комбианции запускаю алгоритм.
 */
void binaryTextSmallerSubs(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name, int count_subs) {
    std::fstream fs;
    fs.open("Binary 10 000  " + to_string(count_subs) + ".txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Binary text small :" << count_subs
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    std::vector<int> questions_pos = std::vector<int>();
    if (name == "StandardAlgorithm") {
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.binary_smaller.begin(), data.binary_smaller.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            for (int j = 0; j < 30; ++j) {
                auto start = std::chrono::high_resolution_clock::now();
                answer = patternSearch(data.binary_smaller, pattern);
                auto end = std::chrono::high_resolution_clock::now() - start;
                nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                sum += nanoseconds;
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    } else {
        int real_answer;
        std::vector<string> subs_combo = getArrayWithSubs(count_subs, data.binary_small_alphabet);
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.binary_smaller.begin(), data.binary_smaller.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            std::sort(questions_pos.begin(), questions_pos.end());
            for (int k = 0; k < 30; ++k) {
                for (std::string combo: subs_combo) {
                    for (int j = 0; j < count_subs; ++j) {
                        pattern[questions_pos[j]] = combo[j];
                    }
                    auto start = std::chrono::high_resolution_clock::now();
                    answer = patternSearch(data.binary_smaller, pattern);
                    if (answer == 1) {
                        real_answer = 1;
                    }
                    auto end = std::chrono::high_resolution_clock::now() - start;
                    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                    sum += nanoseconds;
                }
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << real_answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    }
    fs.close();
}

/*
 * Обработка алгоритмов на тексте из 100 000 символом, который составлен на основе 2 букв.
 * Если приходит стандартный алгоритм, то просто на рандомные места ставим знаки вопроса и запускаем наш алгоритм.
 * В стандартном алгоритме заранее прописано, что символы совпадают, если они действительно совпали или же если стоит знак вопроса.
 * Если же мы берём два алгоритма  кмп, то здесь я при помощи метода  getArrayWithSubs получаем различные комбианции, которые могут стоять на месте вопросительных знаков.
 * Для каждой возможной комбианции запускаю алгоритм.
 */
void binaryTextBiggerSubs(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name, int count_subs) {
    std::fstream fs;
    fs.open("Binary 100 000  " + to_string(count_subs) + ".txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Binary text big :" << count_subs
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    std::vector<int> questions_pos = std::vector<int>();
    if (name == "StandardAlgorithm") {
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.binary_bigger.begin(), data.binary_bigger.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            for (int j = 0; j < 30; ++j) {
                auto start = std::chrono::high_resolution_clock::now();
                answer = patternSearch(data.binary_bigger, pattern);
                auto end = std::chrono::high_resolution_clock::now() - start;
                nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                sum += nanoseconds;
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    } else {
        int real_answer;
        std::vector<string> subs_combo = getArrayWithSubs(count_subs, data.binary_big_alphabet);
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.binary_bigger.begin(), data.binary_bigger.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            std::sort(questions_pos.begin(), questions_pos.end());
            for (int k = 0; k < 30; ++k) {
                for (std::string combo: subs_combo) {
                    for (int j = 0; j < count_subs; ++j) {
                        pattern[questions_pos[j]] = combo[j];
                    }
                    auto start = std::chrono::high_resolution_clock::now();
                    answer = patternSearch(data.binary_bigger, pattern);
                    if (answer == 1) {
                        real_answer = 1;
                    }
                    auto end = std::chrono::high_resolution_clock::now() - start;
                    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                    sum += nanoseconds;
                }
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << real_answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    }
    fs.close();
}

/*
 * Обработка алгоритмов на тексте из 10 000 символом, который составлен на основе 4 букв.
 * Если приходит стандартный алгоритм, то просто на рандомные места ставим знаки вопроса и запускаем наш алгоритм.
 * В стандартном алгоритме заранее прописано, что символы совпадают, если они действительно совпали или же если стоит знак вопроса.
 * Если же мы берём два алгоритма  кмп, то здесь я при помощи метода  getArrayWithSubs получаем различные комбианции, которые могут стоять на месте вопросительных знаков.
 * Для каждой возможной комбианции запускаю алгоритм.
 */
void fourTextSmallerSubs(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name, int count_subs) {
    std::fstream fs;
    fs.open("Four 10 000  " + to_string(count_subs) + ".txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Four text small :" << count_subs
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    std::vector<int> questions_pos = std::vector<int>();
    if (name == "StandardAlgorithm") {
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.four_smaller.begin(), data.four_smaller.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            for (int j = 0; j < 30; ++j) {
                auto start = std::chrono::high_resolution_clock::now();
                answer = patternSearch(data.four_smaller, pattern);
                auto end = std::chrono::high_resolution_clock::now() - start;
                nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                sum += nanoseconds;
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    } else {
        int real_answer;
        std::vector<string> subs_combo = getArrayWithSubs(count_subs, data.four_small_alphabet);
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.four_smaller.begin(), data.four_smaller.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            std::sort(questions_pos.begin(), questions_pos.end());
            for (int k = 0; k < 30; ++k) {
                for (std::string combo: subs_combo) {
                    for (int j = 0; j < count_subs; ++j) {
                        pattern[questions_pos[j]] = combo[j];
                    }
                    auto start = std::chrono::high_resolution_clock::now();
                    answer = patternSearch(data.four_smaller, pattern);
                    if (answer == 1) {
                        real_answer = 1;
                    }
                    auto end = std::chrono::high_resolution_clock::now() - start;
                    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                    sum += nanoseconds;
                }
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << real_answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    }
    fs.close();
}

/*
 * Обработка алгоритмов на тексте из 100 000 символом, который составлен на основе 4 букв.
 * Если приходит стандартный алгоритм, то просто на рандомные места ставим знаки вопроса и запускаем наш алгоритм.
 * В стандартном алгоритме заранее прописано, что символы совпадают, если они действительно совпали или же если стоит знак вопроса.
 * Если же мы берём два алгоритма  кмп, то здесь я при помощи метода  getArrayWithSubs получаем различные комбианции, которые могут стоять на месте вопросительных знаков.
 * Для каждой возможной комбианции запускаю алгоритм.
 */
void fourTextBiggerSubs(DataGenerator &data, int (*patternSearch)(vector<char> &text, vector<char> &pattern), string &name, int count_subs) {
    std::fstream fs;
    fs.open("Four 100 000  " + to_string(count_subs) + ".txt", std::fstream::out | std::fstream::app);
    fs << name
       << "\n";
    std::cout << name << ", Four text big :" << count_subs
              << "\n";
    uint64_t sum;
    uint64_t nanoseconds;
    int answer;
    std::vector<int> questions_pos = std::vector<int>();
    if (name == "StandardAlgorithm") {
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.four_bigger.begin(), data.four_bigger.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            for (int j = 0; j < 30; ++j) {
                auto start = std::chrono::high_resolution_clock::now();
                answer = patternSearch(data.four_bigger, pattern);
                auto end = std::chrono::high_resolution_clock::now() - start;
                nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                sum += nanoseconds;
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    } else {
        int real_answer;
        std::vector<string> subs_combo = getArrayWithSubs(count_subs, data.four_big_alphabet);
        for (int i = 100; i < 3001; i += 100) {
            sum = 0;
            std::vector<char> pattern;
            std::copy(data.four_bigger.begin(), data.four_bigger.begin() + i, std::back_inserter(pattern));
            putQuestion(pattern, count_subs, questions_pos);
            std::sort(questions_pos.begin(), questions_pos.end());
            for (int k = 0; k < 30; ++k) {
                for (std::string combo: subs_combo) {
                    for (int j = 0; j < count_subs; ++j) {
                        pattern[questions_pos[j]] = combo[j];
                    }
                    auto start = std::chrono::high_resolution_clock::now();
                    answer = patternSearch(data.four_bigger, pattern);
                    if (answer == 1) {
                        real_answer = 1;
                    }
                    auto end = std::chrono::high_resolution_clock::now() - start;
                    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end).count();
                    sum += nanoseconds;
                }
            }
            std::cout << "   " << i << ": " << sum / 30 << ", found: " << real_answer << "\n";
            fs << i << " " << sum / 30 << "\n";
        }
    }
    fs.close();
}
int main() {
    // Вектор указатель на функции, чтобы можно было удобно вызывать.
    int (*algorithms[3])(std::vector<char> &, std::vector<char> &) = {standardAlgorithm, kmpAlgorithm, kmpAlgorithmImproved};
    std::vector<string> names = {"StandardAlgorithm", "KMP_Standard", "KMP_Improved"};

    // Вызов методов для генерации данных, в которых будут искаться шаблоны.
    DataGenerator generator;
    generator.getBinarySmaller();
    generator.getBinaryBigger();
    generator.getFourSmaller();
    generator.getFourBigger();

    // Вызов методов подсчёта времени работы алгоритмов без подстановок.
//    for (int i = 0; i < 3; ++i) {
//        binaryTextSmaller(generator, algorithms[i], names[i]);
//        binaryTextBigger(generator, algorithms[i], names[i]);
//        fourTextSmaller(generator, algorithms[i], names[i]);
//        fourTextBigger(generator, algorithms[i], names[i]);
//    }

    // Вызов методов подсчёта времени работы алгоритмов с подстановками.
    // Тут просто каждый раз можно менять метод, чтобы не выводилось много информации сразу, а по необходимости.
    // Для начала подставляю метод с бинарным текстом на 10000, потом на 100000 и т.д
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= 4; ++j) {
            binaryTextSmallerSubs(generator, algorithms[i], names[i], j);
        }
    }
}
