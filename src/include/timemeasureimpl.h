#ifndef TIMEMEASUREIMPL_H
#define TIMEMEASUREIMPL_H
#include "timemeasure.h"

class TimeMeasureImpl : public TimeMeasure{
public:
    Time getStartTime();
    Time getStopTime();
    void onStarted() override;
    void onFinished() override;

private:
    Time startTime_;
    Time finishTime_;

};

#endif // TIMEMEASUREIMPL_H
