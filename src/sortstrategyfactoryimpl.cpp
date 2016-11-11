#include "include/sortstrategyfactoryimpl.h"
#include "include/mergesort.h"
#include "include/selectionsort.h"
#include "include/quicksort.h"
#include "include/stdsort.h"

SortStrategyFactoryImpl::SortStrategyFactoryImpl(CompareStrategyFactory &cmp_strategy_factory)
    :cmp_strategy_factory_(cmp_strategy_factory){
}

std::unique_ptr<SortStrategy> SortStrategyFactoryImpl::createSortStrategy(SortingType s){
    switch (s) {
    case kMergeSort:
        return std::make_unique<MergeSort>(cmp_strategy_factory_);
    case kQuickSort:
        return std::make_unique<QuickSort>(cmp_strategy_factory_);
    case kSelectionSort:
        return std::make_unique<SelectionSort>(cmp_strategy_factory_);
    case kStdSort:
        return std::make_unique<StdSort>(cmp_strategy_factory_);
    default:
        abort();
    }
}



