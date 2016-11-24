#include "include/stdsort.h"
#include <algorithm>


StdSort::StdSort(CompareStrategyFactory &cmp_strategy_factory):
    cmp_strategy_factory_(cmp_strategy_factory){
}

void StdSort::sort(std::vector<std::string> &lines, CompareType cmp_type){
    std::sort(lines.begin(), lines.end(),
              cmp_strategy_factory_.createCompareStrategy(cmp_type));
}

