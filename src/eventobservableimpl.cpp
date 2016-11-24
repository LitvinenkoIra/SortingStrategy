#include "eventobservableimpl.h"

void EventObservableImpl::add(Observer& observer){
    observers_.push_back(&observer);
}

void EventObservableImpl::remove(Observer &observer){
    observers_.erase(std::find(observers_.begin(), observers_.end(), &observer));
}

void EventObservableImpl::notifyStart(){
    for (auto itr: observers_){
        itr->onStarted();
    }
}

void EventObservableImpl::notifyStop(){
    for (auto itr: observers_){
        itr->onFinished();
    }
}

