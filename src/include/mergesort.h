#ifndef MERGESORT_H
#define MERGESORT_H

#include "sortstrategy.h"


class MergeSort : public SortStrategy{
public:
    MergeSort(CompareStrategyFactory& cmp_strategy_factory);
    void sort(std::vector<std::string>& lines, CompareType cmp_type) override;
private:
    CompareStrategyFactory& cmp_strategy_factory_;
};

#endif // MERGESORT_H
