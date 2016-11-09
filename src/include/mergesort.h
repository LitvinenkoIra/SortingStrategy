#ifndef MERGESORT_H
#define MERGESORT_H

#include "sortstrategy.h"


class MergeSort : public SortStrategy{
public:
    void sort(std::vector<std::string> lines) override;
};

#endif // MERGESORT_H
