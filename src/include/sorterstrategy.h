#ifndef SORTERSTRATEGY_H
#define SORTERSTRATEGY_H

#include "sorting.h"


class SorterStrategy
{
public:
    SorterStrategy( Sorting* sort);
    ~SorterStrategy();
    void sort();
private:
    Sorting* p;
};

#endif // SORTERSTRATEGY_H
