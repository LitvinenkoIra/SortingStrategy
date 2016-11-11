#include "include/sorter.h"
#include "include/sortstrategyfactory.h"

Sorter::Sorter(std::unique_ptr<SortStrategyFactory> factory):
    factory_(std::move(factory)) {
    strategy_ = std::move(factory_->createSortStrategy(kMergeSort));
}

Sorter::~Sorter(){}

void Sorter::set(SortingType s){
    strategy_ = std::move(factory_->createSortStrategy(s));
}

void Sorter::sort(std::vector<std::string> lines, CompareType c){
    strategy_->sort(lines, c);
}

