#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include "sortstrategy.h"

class SelectionSort : public SortStrategy{
public:
    SelectionSort(CompareStrategyFactory& cmp_strategy_factory);
    void sort(std::vector<std::string>& lines, CompareType c) override;
    CompareStrategyFactory& cmp_strategy_factory_;
};

#endif // SELECTIONSORT_H
