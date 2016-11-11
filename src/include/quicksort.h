#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sortstrategy.h"

class QuickSort : public SortStrategy{
public:
    QuickSort(CompareStrategyFactory& strategy_factory);
    void sort(std::vector<std::string>& lines, CompareType c) override;
    CompareStrategyFactory& cmp_strategy_factory_;
};

#endif // QUICKSORT_H
