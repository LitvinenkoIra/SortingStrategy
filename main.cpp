#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include "sortstrategy.h"
#include "sortstrategyfactory.h"
#include "sortstrategyfactoryimpl.h"
#include "sorter.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"
#include "comparestrategyfactory.h"


int main(){

    const std::string inputfile("/home/ira/pro/SortingStrategy/input.txt");
    std::ifstream ifs(inputfile.c_str());
    if(!ifs){
    std::cerr << "Can't open \'" << inputfile << "\' for input" << std::endl;
    return EXIT_FAILURE;
    }
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(ifs, line)){
        if(!ifs){
            std::cerr << "Can't read from \'" << inputfile << "\'" << std::endl;
            return EXIT_FAILURE;
        }
        lines.push_back(line);
    }

    CompareStrategyFactory f;
    Sorter sorter(std::make_unique<SortStrategyFactoryImpl>(f));
    sorter.set(kQuickSort);
    sorter.sort(lines, kCompareToSize);
    return 0;
}
