#include "comparestrategyfactory.h"

string_less CompareStrategyFactory::createCompareFactory(CompareType c) {
    switch (c) {
    case kCompareToSize:
        return [](const std::string& lvalue, const std::string& rvalue)->bool{
            return lvalue.size() < rvalue.size();
        };
    case kCompareToVal:
        return [](const std::string& lvalue, const std::string& rvalue)->bool{
            for(int i = 0; i < std::min(lvalue.size(), rvalue.size()); i++){
                if(lvalue[i] != rvalue[i])
                    return lvalue[i] < rvalue[i];
            }
            return lvalue.size() < rvalue.size();
        };
    default:
        abort();
    }
}

