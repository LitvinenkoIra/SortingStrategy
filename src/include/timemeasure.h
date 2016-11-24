#ifndef TIMEMEASURE
#define TIMEMEASURE
#include <chrono>
#include "observer.h"

typedef std::chrono::system_clock::time_point Time;

class TimeMeasure : public Observer{
public:
    virtual Time getStartTime() = 0;
    virtual Time getStopTime() = 0;
};

#endif // TIMEMEASURE

