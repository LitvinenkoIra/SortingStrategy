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

void test_to_size_less(string_less less_func) {

}

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
    auto less1 = f.createCompareStrategy(kCompareToVal);
    std::cout << less1("dd", "ddd") << std::endl;
    std::cout << less1("ddddd", "cc") << std::endl;
    std::cout << less1("0xxx", "xxx") << std::endl;

    Sorter sorter(std::make_unique<SortStrategyFactoryImpl>(f));
    sorter.set(kMergeSort);
    sorter.sort(lines, kCompareToSize);

    return 0;
}
