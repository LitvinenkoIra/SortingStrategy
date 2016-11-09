#include "include/strategyfactoryimpl.h"
#include "include/mergesort.h"
#include "include/selectionsort.h"
#include "include/quicksort.h"

std::unique_ptr<SortStrategy> StrategyFactoryImpl::createStrategy(SortingType s){
    switch (s) {
    case kMergeSort:
        return std::make_unique<MergeSort>();
    case kQuickSort:
        return std::make_unique<QuickSort>();
    case kSelectionSort:
        return std::make_unique<SelectionSort>();
    default:
        abort();

    }
}

