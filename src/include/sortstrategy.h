#ifndef SORTSTRATEGY_H
#define SORTSTRATEGY_H
#include <vector>
#include <string>

class SortStrategy{
public:
    virtual ~SortStrategy(){}
    virtual void sort(std::vector<std::string> lines) = 0;
};

#endif // SORTSTRATEGY_H
