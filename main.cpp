#include <iostream>
#include <deque>
#include <fstream>
#include "sortstrategy.h"
#include "sorter.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"

int main(){

    const std::string inputfile("/home/ira/SorterWithStrategy/input.txt");
    std::ifstream ifs(inputfile.c_str());
    if(!ifs){
    std::cerr << "Can't open \'" << inputfile << "\' for input" << std::endl;
    return EXIT_FAILURE;
    }
    std::string line;
    std::deque<std::string> lines;
    while(std::getline(ifs, line)){
        if(!ifs){
            std::cerr << "Can't read from \'" << inputfile << "\'" << std::endl;
            return EXIT_FAILURE;
        }
        lines.push_back(line);
    }

    Sorter* m = new Sorter(new MergeSort);
    m->sort(lines);
    delete m;




    return 0;
}
