#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sortstrategy.h"


class SelectionSort : public SortStrategy{
public:
    void sort(std::vector<std::string> lines) override;
};

#endif // SELECTIONSORT_H
