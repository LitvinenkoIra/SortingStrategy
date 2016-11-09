#include "include/sorter.h"
#include "include/strategyfactory.h"

Sorter::Sorter(std::unique_ptr<StrategyFactory> factory):factory_(std::move(factory)){
    strategy_ = std::move(factory_->createStrategy(kMergeSort));
}

Sorter::~Sorter(){}

void Sorter::set(SortingType s){
    strategy_ = std::move(factory_->createStrategy(s));
}

void Sorter::sort(std::vector<std::string> lines){
    strategy_->sort(lines);
}

