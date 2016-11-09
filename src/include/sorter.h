#ifndef SORTER_H
#define SORTER_H

#include "sortstrategy.h"
#include "strategyfactory.h"
#include "sortstrategy.h"


class Sorter{
public:
    Sorter(std::unique_ptr<StrategyFactory> factory_);
    ~Sorter();
    void set(SortingType s);
    void sort(std::vector<std::string> lines);
private:
    std::unique_ptr<StrategyFactory> factory_;
    std::unique_ptr<SortStrategy> strategy_;
};

#endif // SORTER_H
