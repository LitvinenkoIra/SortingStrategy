#ifndef OBSERVER
#define OBSERVER


class Observer{
public:
    virtual void onStarted() = 0;
    virtual void onFinished() = 0;
    virtual ~Observer(){}
};

#endif // OBSERVER

