#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sortstrategy.h"


class SelectionSort : public SortStrategy{
public:
    void sort(std::deque<std::string> lines) override;
};

#endif // SELECTIONSORT_H
