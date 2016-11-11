#include "include/selectionsort.h"
#include <iostream>

SelectionSort::SelectionSort(CompareStrategyFactory &cmp_strategy_factory):cmp_strategy_factory_(cmp_strategy_factory){
}
void SelectionSort::sort(std::vector<std::string>& lines, CompareType c){
    std::cout << "Selection sort" << std::endl;
    for(int i = 0; i < lines.size(); i++) {
            std::cout << lines[i] << " ";
        }
}

