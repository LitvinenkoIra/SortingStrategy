#include "include/mergesort.h"
#include <iostream>
#include <vector>
template <typename Tit>
void print_arr(std::string key, Tit begin, Tit end){
    std::cout << key << ": ";
    for(; begin != end; ++begin){
        std::cout << *begin << " ";
    }
    std::cout << std::endl;
}

template<typename TIter, typename Cmp>
void merge (TIter lbegin, TIter lend, TIter rbegin, TIter rend, TIter out, Cmp comparator ){
    print_arr("merge left", lbegin, lend);
    print_arr("merge right", rbegin, rend);
    int length = (lend - lbegin) + (rend - rbegin);
    TIter bout = out;
    for (; lbegin != lend && rbegin != rend;){
        if (comparator(*lbegin,*rbegin)){
            *out++ = *lbegin++;
        }
        else {
            *out++ = *rbegin++;
        }
    }

    if(lbegin != lend){
        std::copy(lbegin, lend, out);
    }
    if(rbegin != rend){
        std::copy(rbegin, rend, out);
    }

    print_arr("merge out", bout, bout+length);
}

template<typename TIter, typename Cmp>
void merge_sort(TIter begin, TIter end, TIter buff, Cmp comparator){
    print_arr("merge sort ", begin, end);
    if (end - begin == 0)
        return;
    if (end - begin == 1){
        *buff = *begin;
        return;
    }

    int length = end - begin;
    TIter middle = begin + length/2;
    merge_sort(begin, middle, buff, comparator);
    merge_sort(middle, end, buff+length/2, comparator);
    merge(buff, buff+length/2, buff+length/2, buff+length, begin, comparator);
    std::copy(begin, end, buff);

}

MergeSort::MergeSort(CompareStrategyFactory &cmp_strategy_factory):
    cmp_strategy_factory_(cmp_strategy_factory){
}

void MergeSort::sort(std::vector<std::string> &lines, CompareType cmp_type){

    std::vector<std::string> buff (lines.size());
    merge_sort(lines.begin(), lines.end(), buff.begin(), cmp_strategy_factory_.createCompareStrategy(cmp_type));


}

