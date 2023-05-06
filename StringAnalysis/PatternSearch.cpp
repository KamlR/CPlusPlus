#include "PatternSearch.h"

/*
 * Стандартное сравнение каждого символа шаблона и текста.
 * Встроена проверка на символ ?
 * Возвращается кол-
 */
int standardAlgorithm(std::vector<char> &text, std::vector<char> &pattern) {
    int index_text;
    int count_patterns = 0;
    int count_equals;
    for (int i = 0; i < text.size(); ++i) {
        index_text = i;
        count_equals = 0;
        if (text.size() - index_text < pattern.size()) {
            break;
        }
        for (int j = 0; j < pattern.size(); ++j) {
            if (text[index_text] == pattern[j] || pattern[j] == '?') {
                index_text++;
                count_equals++;
            } else {
                break;
            }
        }
        if (count_equals == pattern.size()) {
            count_patterns++;
        }
    }
    return count_patterns;
}

/*
 * Стандартный КМП алгоритм без использования уточнения граней
 */
int kmpAlgorithm(std::vector<char> &text, std::vector<char> &pattern) {
    int count_patterns = 0;
    std::vector<int> prefixes(pattern.size());
    // Индексы для старта
    int j = 0, i = 1;
    // Идём пока не закончился наш шаблон и составляем вектор префиксов.
    while (i < pattern.size()) {
        if (pattern[i] == pattern[j]) {
            prefixes[i] = j + 1;
            j++;
            i++;
        } else if (j == 0) {
            prefixes[i] = 0;
            i++;
        } else {
            j = prefixes[j - 1];
        }
    }
    // Используя вектор префиксов, ищем вхождения нашей подстроки в строке.
    j = 0;
    for (i = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefixes[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == pattern.size()) {
            count_patterns++;
            j = 0;
        }
    }
    return count_patterns;
}

/*
 * Улучшенный алгоритм КМП c уточнением граней, который позволяет не совершать лишних сравнений.
 */
int kmpAlgorithmImproved(std::vector<char> &text, std::vector<char> &pattern) {
    int count_patterns = 0;
    std::vector<int> prefixes(pattern.size());
    std::vector<int> prefixes_improved(pattern.size());
    // Построение вектора префиксов.
    // Используется два вектора префиксов, один, как в прошлом алгоритме, другой, на основе которого будет совершаться поиск шаблона.
    // prefixes_improved заполняется в том случае, если наши элементы не совпали. Так мы храним только максимальные префиксы, равные суффиксам.
    int j = 0, i = 1;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[j]) {
            prefixes[i] = j + 1;
            j++;
            i++;
        } else if (j == 0) {
            prefixes[i] = 0;
            i++;
        } else {
            prefixes_improved[i - 1] = j;
            j = prefixes[j - 1];
        }
    }
    j = 0;
    for (i = 0; i < text.size(); ++i) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefixes[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == pattern.size()) {
            count_patterns++;
            j = 0;
        }
    }
    return count_patterns;
}