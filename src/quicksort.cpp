#include "include/quicksort.h"
#include <iostream>

QuickSort::QuickSort(CompareStrategyFactory &cmp_strategy_factory):
    cmp_strategy_factory_(cmp_strategy_factory){
}

template<typename TIter, typename Tval>
void quickSort(TIter begin, TIter end, std::function<bool(const Tval&, const Tval&)> less){
    TIter m_it = begin + (end - begin)/2;
    TIter l_it = begin;
    TIter r_it = end;
    while (l_it < r_it){
        while (less(*l_it, *m_it)) ++l_it;
        while (less(*m_it, *r_it)) --r_it;
        if (l_it <= r_it){
            std::swap(*l_it, *r_it);
            ++l_it;
            --r_it;
        }
    }
    if(l_it < end)
        quickSort(l_it, end, less);
    if(begin < r_it)
        quickSort(begin, r_it, less);
}

void QuickSort::sort(std::vector<std::string>& lines, CompareType cmp_type){
    auto less = cmp_strategy_factory_.createCompareStrategy(cmp_type);
    quickSort(lines.begin(),lines.end(),less);
}

