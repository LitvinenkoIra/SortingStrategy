#include <string>
#include "limo/test_main.hpp"
#include <sorter.h>
#include <comparestrategyfactory.h>
#include <sortstrategyfactoryimpl.h>

bool operator >(std::string& lval, std::string& rval) {
    return lval.size() > rval.size();
}

template <typename T>
bool is_sorted(std::vector<T> data){
    if (data.size() == 0){
        return true;
    }
    for (typename std::vector<T>::iterator it = data.begin();
         it != data.end()-1; ++it){
        if (*it > *(it+1)){
            return false;
        }
    }
    return true;
}

LTEST(sorting_tests) {

    typedef std::vector<std::string> StrVec;

    LTEST(is_sorted_test){
        LTEST(is_sorted_int_test){

            EXPECT_TRUE(is_sorted(std::vector<int>({1,2,3})));
            EXPECT_FALSE(is_sorted(std::vector<int>({3,2,1})));
            EXPECT_TRUE(is_sorted(std::vector<int>({})));
            EXPECT_TRUE(is_sorted(std::vector<int>({1,1,1})));
            EXPECT_TRUE(is_sorted(std::vector<int>({1})));
            EXPECT_TRUE(is_sorted(std::vector<int>({1,1,1,2})));
            EXPECT_FALSE(is_sorted(std::vector<int>({2,1,1,1})));
            // TODO(AKutsan): Add negative values check;
        };
        LTEST(is_sorted_str_test){
            EXPECT_TRUE(is_sorted(StrVec({"a","ab","abc"})));
            EXPECT_FALSE(is_sorted(StrVec({"aaa","aa","a"})));
            EXPECT_TRUE(is_sorted(StrVec({})));
            EXPECT_TRUE(is_sorted(StrVec({"1","1","1"})));
            EXPECT_TRUE(is_sorted(StrVec({"1"})));
            EXPECT_TRUE(is_sorted(StrVec({"1","1","1","aa"})));
            EXPECT_FALSE(is_sorted(StrVec({"AA","1","A","1"})));
        };
    };

    LTEST(std_sort_test){
        CompareStrategyFactory cmp_strategy_factory;
        Sorter sorter(std::make_unique<SortStrategyFactoryImpl>(cmp_strategy_factory));
        sorter.set(kStdSort);
        LTEST(already_sorted) {
            StrVec data({"a","ab","abc"});
            sorter.sort(data, kCompareToSize);
            EXPECT_TRUE(is_sorted(data));
        };
        LTEST(regular_case) {
            StrVec data({"ab", "a", "abc"});
            sorter.sort(data, kCompareToSize);
            EXPECT_TRUE(is_sorted(data));
        };
    };
};
