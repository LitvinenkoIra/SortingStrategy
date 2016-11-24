#ifndef SORTSTRATEGYFACTORYIMPL_H
#define SORTSTRATEGYFACTORYIMPL_H
#include <memory>
#include "sortstrategyfactory.h"

class SortStrategyFactoryImpl : public SortStrategyFactory {
public:
    SortStrategyFactoryImpl(CompareStrategyFactory& cmp_strategy_factory);
    std::unique_ptr<SortStrategy> createSortStrategy(SortingType srt_type);
private:
    CompareStrategyFactory& cmp_strategy_factory_;
};

#endif // SORTSTRATEGYFACTORYIMPL_H
