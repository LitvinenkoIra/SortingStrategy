#include "include/mergesort.h"
#include <iostream>

void MergeSort::sort(std::vector<std::string> lines){
    std::cout << "Merge sort" << std::endl;
    for(int i = 0; i < lines.size(); i++) {
            std::cout << lines[i] << " ";
        }
}

