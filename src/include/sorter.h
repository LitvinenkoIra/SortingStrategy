#ifndef SORTER_H
#define SORTER_H

#include "sortstrategy.h"
#include "sortstrategyfactory.h"
#include "eventobservableimpl.h"


class Sorter : public EventObservableImpl{
public:
    Sorter(std::unique_ptr<SortStrategyFactory> factory_);
    ~Sorter();
    void set(SortingType s);
    void sort(std::vector<std::string>& lines, CompareType cmp_type);
private:
    std::unique_ptr<SortStrategyFactory> factory_;
    std::unique_ptr<SortStrategy> strategy_;
};

#endif // SORTER_H
