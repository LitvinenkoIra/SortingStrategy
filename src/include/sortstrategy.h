#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include <vector>
#include <string>
#include "comparestrategyfactory.h"

class SortStrategy{
public:
    virtual ~SortStrategy(){}
    virtual void sort(std::vector<std::string>& lines, CompareType c) = 0;
};

#endif // SORTSTRATEGY_H
