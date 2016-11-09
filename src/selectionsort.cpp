#include "include/selectionsort.h"
#include <iostream>

void SelectionSort::sort(std::vector<std::string> lines){
    std::cout << "Selection sort" << std::endl;
    for(int i = 0; i < lines.size(); i++) {
            std::cout << lines[i] << " ";
        }
}

