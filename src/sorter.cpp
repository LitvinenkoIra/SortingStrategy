#include "include/sorter.h"

Sorter::Sorter(SortStrategy *sort):p(sort){}

Sorter::~Sorter(){
    delete p;
}

void Sorter::sort(std::deque<std::string> lines){
    p->sort(lines);
}

