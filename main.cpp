#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include "sortstrategy.h"
#include "strategyfactory.h"
#include "strategyfactoryimpl.h"
#include "sorter.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"

bool compareToSize(const std::string& lvalue, const std::string& rvalue){

    return lvalue.size() < rvalue.size();
}

bool compareToVal(const std::string& lvalue, const std::string& rvalue){

    for(int i = 0; i < std::min(lvalue.size(), rvalue.size()); i++){
        if(lvalue[i] != rvalue[i])
            return lvalue[i] < rvalue[i];
    }
    return lvalue.size() < rvalue.size();
}

int main(){

    const std::string inputfile("/home/ira/SorterWithStrategy/input.txt");
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

    Sorter sorter(std::make_unique<StrategyFactoryImpl>());
    sorter.set(kMergeSort);
    sorter.sort(lines);

    return 0;
}
