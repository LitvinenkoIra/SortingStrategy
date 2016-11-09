#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sortstrategy.h"

class QuickSort : public SortStrategy{
public:
    void sort(std::deque<std::string> lines) override;
};

#endif // QUICKSORT_H
