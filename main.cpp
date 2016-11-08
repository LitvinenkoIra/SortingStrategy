#include <iostream>
#include "sorterstrategy.h"
#include "sorting.h"
#include "selectionsort.h"
#include "mergesort.h"
#include "quicksort.h"

int main(){

    SorterStrategy* m = new SorterStrategy(new MergeSort);
    m->sort();
    delete m;


    return 0;
}

