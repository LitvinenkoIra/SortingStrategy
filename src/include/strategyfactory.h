#ifndef STRATEGYFACTORY_H
#define STRATEGYFACTORY_H
#include <memory>
#include "sortstrategy.h"

enum SortingType{
    kMergeSort,
    kQuickSort,
    kSelectionSort,
};

class StrategyFactory
{
public:
    virtual std::unique_ptr<SortStrategy> createStrategy(SortingType s) = 0;
};

#endif // STRATEGYFACTORY_H
