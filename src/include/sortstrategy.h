#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include <deque>
#include <string>

class SortStrategy{
public:
    virtual ~SortStrategy(){}
    virtual void sort(std::deque<std::string> lines) = 0;
};

#endif // SORTSTRATEGY_H
