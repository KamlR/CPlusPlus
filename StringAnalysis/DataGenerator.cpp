#include <cstdlib>
#include <iostream>
#include <vector>

#include "DataGenerator.h"
DataGenerator::DataGenerator() {
    binary_smaller = std::vector<char>(10000); // Текст из 10000 символов, составленный на основе 2 букв.
    binary_bigger = std::vector<char>(100000); // Текст из 100000 символов, составленный на основе 2 букв.
    four_smaller = std::vector<char>(10000); // Текст из 10000 символов, составленный на основе 4 букв.
    four_bigger = std::vector<char>(100000); // Текст из 100000 символов, составленный на основе 4 букв.

    binary_small_alphabet = std::vector<int>(2); // Бинарный алфавит для текста из 10000 символов.
    binary_big_alphabet = std::vector<int>(2); // Бинарный алфавит для текста из 100000 символов.
    four_small_alphabet = std::vector<int>(4); // Алфавит из 4 букв для текста из 10000 символов.
    four_big_alphabet = std::vector<int>(4); // Алфавит из 4 букв для текста из 100000 символов.
}

/*
 * Создание текста из 10 000 символов на основе 2 букв, сгенерированных случайным образом.
 */
void DataGenerator::getBinarySmaller() {
    srand(time(0));
    std::vector<int> alphabet(2);
    alphabet[0] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[1] = (rand() % (122 - 97 + 1)) + 97;
    binary_small_alphabet = alphabet;
    for (int i = 0; i < 10000; ++i) {
        int index = (rand() % (2 - 1 + 1)) + 1;
        binary_smaller[i] = (char) alphabet[index - 1];
    }
}

/*
 * Создание текста из 100 000 символов на основе 2 букв, сгенерированных случайным образом.
 */
void DataGenerator::getBinaryBigger() {
    srand(time(0));
    std::vector<int> alphabet(2);
    alphabet[0] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[1] = (rand() % (122 - 97 + 1)) + 97;
    binary_big_alphabet = alphabet;
    for (int i = 0; i < 100000; ++i) {
        int index = (rand() % (2 - 1 + 1)) + 1;
        binary_bigger[i] = (char) alphabet[index - 1];
    }
}

/*
 * Создание текста из 10 000 символов на основе 4 букв, сгенерированных случайным образом.
 */
void DataGenerator::getFourSmaller() {
    srand(time(0));
    std::vector<int> alphabet(4);
    alphabet[0] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[1] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[2] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[3] = (rand() % (122 - 97 + 1)) + 97;
    four_small_alphabet = alphabet;
    for (int i = 0; i < 10000; ++i) {
        int index = (rand() % (4 - 1 + 1)) + 1;
        four_smaller[i] = (char) alphabet[index - 1];
    }
}

/*
 * Создание текста из 100 000 символов на основе 4 букв, сгенерированных случайным образом.
 */
void DataGenerator::getFourBigger() {
    srand(time(0));
    std::vector<int> alphabet(4);
    alphabet[0] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[1] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[2] = (rand() % (122 - 97 + 1)) + 97;
    alphabet[3] = (rand() % (122 - 97 + 1)) + 97;
    four_big_alphabet = alphabet;
    for (int i = 0; i < 100000; ++i) {
        int index = (rand() % (4 - 1 + 1)) + 1;
        four_bigger[i] = (char) alphabet[index - 1];
    }
}
