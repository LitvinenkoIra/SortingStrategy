#include "include/quicksort.h"
#include <iostream>

void QuickSort::sort(std::vector<std::string> lines){
    std::cout << "Quick sort" << std::endl;
    for(int i = 0; i < lines.size(); i++) {
            std::cout << lines[i] << " ";
        }
}

