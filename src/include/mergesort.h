#ifndef MERGESORT_H
#define MERGESORT_H

#include "sortstrategy.h"


class MergeSort : public SortStrategy{
public:
    void sort(std::deque<std::string> lines) override;
};

#endif // MERGESORT_H
