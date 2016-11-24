#include "include/selectionsort.h"
#include <iostream>
#include <functional>

template<typename TIter, typename Tval>
TIter get_min(TIter begin, TIter end, std::function<bool(const Tval&, const Tval&)> less){
    TIter min = begin;
    for (; begin != end; ++begin){
        if (less(*begin, *min)){
            min = begin;
        }
    }
    return min;
}

SelectionSort::SelectionSort(CompareStrategyFactory &cmp_strategy_factory):
    cmp_strategy_factory_(cmp_strategy_factory){
}


void SelectionSort::sort(std::vector<std::string>& lines, CompareType cmp_type){
    auto less = cmp_strategy_factory_.createCompareStrategy(cmp_type);
    for (auto i_it = lines.begin(); i_it != lines.end(); ++i_it ){
        auto min = get_min(i_it, lines.end(), less);
        if (min != i_it){
            std::swap(*i_it, *min);
        }
    }
}

