#include "include/quicksort.h"
#include <iostream>

QuickSort::QuickSort(CompareStrategyFactory &cmp_strategy_factory):cmp_strategy_factory_(cmp_strategy_factory){
}
void QuickSort::sort(std::vector<std::string>& lines, CompareType c){
    std::cout << "Quick sort" << std::endl;
    for(int i = 0; i < lines.size(); i++) {
            std::cout << lines[i] << " ";
        }
}

