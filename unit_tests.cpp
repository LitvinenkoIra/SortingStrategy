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

template <typename Tit>
void print_arr(Tit begin, Tit end){
    for(; begin != end; ++begin){
        std::cout << *begin << " ";
    }
    std::cout << std::endl;
}


typedef std::vector<std::string> StrVec;
CompareStrategyFactory cmp_strategy_factory;
Sorter sorter(std::make_unique<SortStrategyFactoryImpl>(cmp_strategy_factory));
StrVec already_sorted({"a","ab","abc"});
StrVec empty_arr({});
StrVec unsorted_arr({"abc","ab","a"});
StrVec regular_case({"ab","a","abc"});
StrVec mixed_arr({"AA", "1", "A", "1"});
StrVec same_values({"a", "a", "a"});


LTEST(is_sorted_test){
    LTEST(is_sorted_int_test){

        EXPECT_TRUE(is_sorted(std::vector<int>({1,2,3})));
        EXPECT_FALSE(is_sorted(std::vector<int>({3,2,1})));
        EXPECT_TRUE(is_sorted(std::vector<int>({})));
        EXPECT_TRUE(is_sorted(std::vector<int>({1,1,1})));
        EXPECT_TRUE(is_sorted(std::vector<int>({1})));
        EXPECT_TRUE(is_sorted(std::vector<int>({1,1,1,2})));
        EXPECT_FALSE(is_sorted(std::vector<int>({2,1,1,1})));
        EXPECT_TRUE(is_sorted (std::vector<int>({-3,-2,-1})));
        EXPECT_FALSE(is_sorted (std::vector<int>({-3,-1,-2})));
        EXPECT_FALSE(is_sorted(std::vector<int>({-1, -2, -3})));
        EXPECT_TRUE(is_sorted(std::vector<int>({-1})));
        EXPECT_TRUE(is_sorted(std::vector<int>({-1, -1, -1})));

        // TODO(AKutsan): Add negative values check;
    };
    LTEST(is_sorted_str_test){
        EXPECT_TRUE(is_sorted(already_sorted));
        EXPECT_TRUE(is_sorted(empty_arr));
        EXPECT_FALSE(is_sorted(unsorted_arr));
        EXPECT_FALSE(is_sorted(regular_case));
        EXPECT_FALSE(is_sorted(mixed_arr));
        EXPECT_TRUE(is_sorted(same_values));
    };
};


LTEST(compare_to_size_tests) {

    LTEST(std_sort_test){

        sorter.set(kStdSort);

        LTEST(already_sorted) {
            StrVec to_sort = already_sorted;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(empty_arr) {
            StrVec to_sort = empty_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(unsorted_arr) {
            StrVec to_sort = unsorted_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(regular_case) {
            StrVec to_sort = regular_case;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(mixed_arr) {
            StrVec to_sort = mixed_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(same_values) {
            StrVec to_sort = same_values;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };

    };

    LTEST(merge_sort_test){

        sorter.set(kMergeSort);

        LTEST(already_sorted) {
            StrVec to_sort = already_sorted;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(empty_arr) {
            StrVec to_sort = empty_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(unsorted_arr) {
            StrVec to_sort = unsorted_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(regular_case) {
            StrVec to_sort = regular_case;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(mixed_arr) {
            StrVec to_sort = mixed_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(same_values) {
            StrVec to_sort = same_values;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };

    };


//    LTEST(quick_sort_test){

//        sorter.set(kQuickSort);

//        LTEST(already_sorted) {
//            StrVec to_sort = already_sorted;
//            sorter.sort(to_sort, kCompareToSize);
//            EXPECT_TRUE(is_sorted(to_sort));
//        };
//        LTEST(empty_arr) {
//            StrVec to_sort = empty_arr;
//            sorter.sort(to_sort, kCompareToSize);
//            EXPECT_TRUE(is_sorted(to_sort));
//        };
//        LTEST(unsorted_arr) {
//            StrVec to_sort = unsorted_arr;
//            sorter.sort(to_sort, kCompareToSize);
//            EXPECT_TRUE(is_sorted(to_sort));
//        };
//        LTEST(regular_case) {
//            StrVec to_sort = regular_case;
//            sorter.sort(to_sort, kCompareToSize);
//            EXPECT_TRUE(is_sorted(to_sort));
//        };
//        LTEST(mixed_arr) {
//            StrVec to_sort = mixed_arr;
//            sorter.sort(to_sort, kCompareToSize);
//            EXPECT_TRUE(is_sorted(to_sort));
//        };
//        LTEST(same_values) {
//            StrVec to_sort = same_values;
//            sorter.sort(to_sort, kCompareToSize);
//            EXPECT_TRUE(is_sorted(to_sort));
//        };

//    };


    LTEST(selection_sort_test){

        sorter.set(kSelectionSort);

        LTEST(already_sorted) {
            StrVec to_sort = already_sorted;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(empty_arr) {
            StrVec to_sort = empty_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(unsorted_arr) {
            StrVec to_sort = unsorted_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(regular_case) {
            StrVec to_sort = regular_case;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(mixed_arr) {
            StrVec to_sort = mixed_arr;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };
        LTEST(same_values) {
            StrVec to_sort = same_values;
            sorter.sort(to_sort, kCompareToSize);
            EXPECT_TRUE(is_sorted(to_sort));
        };

    };
};
