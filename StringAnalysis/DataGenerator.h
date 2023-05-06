#include <cstdlib>
#include <iostream>
#include <vector>
#ifndef STRINGANALYSIS_DATAGENERATOR_H
#define STRINGANALYSIS_DATAGENERATOR_H


class DataGenerator {
public:
    std::vector<char> binary_smaller;
    std::vector<char> binary_bigger;
    std::vector<char> four_smaller;
    std::vector<char> four_bigger;
    std::vector<int> binary_small_alphabet;
    std::vector<int> binary_big_alphabet;
    std::vector<int> four_small_alphabet;
    std::vector<int> four_big_alphabet;

public:
    DataGenerator();
    void getBinarySmaller();
    void getBinaryBigger();
    void getFourSmaller();
    void getFourBigger();
};


#endif//STRINGANALYSIS_DATAGENERATOR_H
