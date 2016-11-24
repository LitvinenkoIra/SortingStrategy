#ifndef EVENTOBSERVABLEIMPL_H
#define EVENTOBSERVABLEIMPL_H
#include <vector>
#include <algorithm>
#include "eventobservable.h"
#include "observer.h"


class EventObservableImpl : public EventObservable{
public:
     void add(Observer& observer);
     void remove(Observer& observer);
     void notifyStart();
     void notifyStop();
private:
     std::vector<Observer*> observers_;

};

#endif // EVENTOBSERVABLEIMPL_H
