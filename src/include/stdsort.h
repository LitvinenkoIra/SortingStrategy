#ifndef STDSORT_H
#define STDSORT_H

#include "sortstrategy.h"


class StdSort : public SortStrategy{
public:
    StdSort(CompareStrategyFactory& cmp_strategy_factory);
    void sort(std::vector<std::string> &lines, CompareType c) override;
private:
    CompareStrategyFactory& cmp_strategy_factory_;
};

#endif // STDSORT_H
