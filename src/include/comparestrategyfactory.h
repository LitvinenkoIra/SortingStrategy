#ifndef COMPARESTRATEGYFACTORY_H
#define COMPARESTRATEGYFACTORY_H
#include <functional>
#include <string>

typedef std::function<bool(const std::string&, const std::string&)> string_less;

enum CompareType{
    kCompareToSize,
    kCompareToVal,
};

class CompareStrategyFactory{
public:
    string_less createCompareStrategy(CompareType cmp_type);
};

#endif // COMPARESTRATEGYFACTORY_H
