#ifndef EVENTOBSERVABLE
#define EVENTOBSERVABLE
#include <vector>
#include "observer.h"

class EventObservable{
public:
    virtual void add(Observer& observer) = 0;
    virtual void remove(Observer& observer) = 0;
    virtual ~EventObservable(){}

};

#endif // EVENTOBSERVABLE

