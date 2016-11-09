#ifndef SORTER_H
#define SORTER_H

#include "sortstrategy.h"


class Sorter{
public:
    Sorter( SortStrategy* sort);
    ~Sorter();
    void sort(std::deque<std::string> lines);
private:
    SortStrategy* p;
};

#endif // SORTER_H
