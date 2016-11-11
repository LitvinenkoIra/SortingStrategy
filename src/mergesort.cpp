#include "include/mergesort.h"
#include <iostream>

MergeSort::MergeSort(CompareStrategyFactory &cmp_strategy_factory):
    cmp_strategy_factory_(cmp_strategy_factory){
}

void MergeSort::sort(std::vector<std::string> &lines, CompareType c){
    std::cout << "Merge sort" << std::endl;
    for(int i = 0; i < lines.size(); i++) {
            std::cout << lines[i] << c << " ";
        }
}

