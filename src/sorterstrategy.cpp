#include "include/sorterstrategy.h"

SorterStrategy::SorterStrategy(Sorting *sort):p(sort){}

SorterStrategy::~SorterStrategy(){
    delete p;
}

void SorterStrategy::sort(){
    p->sort();
}

