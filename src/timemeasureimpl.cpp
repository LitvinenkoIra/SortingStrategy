#include "timemeasureimpl.h"

Time TimeMeasureImpl::getStartTime(){
    return startTime_;
}

Time TimeMeasureImpl::getStopTime(){
    return finishTime_;
}

void TimeMeasureImpl::onStarted(){
    startTime_ = std::chrono::system_clock::now();
}

void TimeMeasureImpl::onFinished(){
    finishTime_ = std::chrono::system_clock::now();
}
