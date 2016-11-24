#include "timecalculator.h"

TimeCalculator::TimeCalculator(TimeMeasure& timeMeasure):
    timeMeasure_(timeMeasure){
}

void TimeCalculator::onStarted(){
    timeMeasure_.onStarted();
}

void TimeCalculator::onFinished(){
    timeMeasure_.onFinished();
}

Time TimeCalculator::getStartTime(){
    return timeMeasure_.getStartTime();
}

Time TimeCalculator::getStopTime(){
    return timeMeasure_.getStopTime();
}



long TimeCalculator::getMeasuredTime(){
    return std::chrono::duration_cast<std::chrono::microseconds>(timeMeasure_.getStopTime() -
                                                                 timeMeasure_.getStartTime()).count();
}

