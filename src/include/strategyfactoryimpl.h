#ifndef STRATEGYFACTORYIMPL_H
#define STRATEGYFACTORYIMPL_H
#include <memory>
#include "strategyfactory.h"

class StrategyFactoryImpl : public StrategyFactory{
public:
    std::unique_ptr<SortStrategy> createStrategy(SortingType s);
};

#endif // STRATEGYFACTORYIMPL_H
