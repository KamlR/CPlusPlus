#include <vector>

#ifndef STRINGANALYSIS_PATTERNSEARCH_H
#define STRINGANALYSIS_PATTERNSEARCH_H

int standardAlgorithm(std::vector<char> &text, std::vector<char> &pattern);
int kmpAlgorithm(std::vector<char> &text, std::vector<char> &pattern);
int kmpAlgorithmImproved(std::vector<char> &text, std::vector<char> &pattern);
#endif
