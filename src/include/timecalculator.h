#ifndef TIMECALCULATOR_H
#define TIMECALCULATOR_H
#include "timemeasure.h"


class TimeCalculator : public TimeMeasure {
public:
    long getMeasuredTime();
    TimeCalculator(TimeMeasure& timeMeasure);

private:
    TimeMeasure &timeMeasure_;

    // Observer interface
public:
    void onStarted();
    void onFinished();

    // TimeMeasure interface
public:
    Time getStartTime();
    Time getStopTime();
};

#endif // TIMECALCULATOR_H
