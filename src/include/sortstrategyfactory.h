#ifndef SORTSTRATEGYFACTORY_H
#define SORTSTRATEGYFACTORY_H
#include <memory>
#include "sortstrategy.h"
#include "comparestrategyfactory.h"

enum SortingType{
    kMergeSort,
    kQuickSort,
    kSelectionSort,
};

class SortStrategyFactory{
public:
    virtual ~SortStrategyFactory(){}
    virtual std::unique_ptr<SortStrategy> createSortStrategy(SortingType s) = 0;

};

#endif // SORTSTRATEGYFACTORY_H
