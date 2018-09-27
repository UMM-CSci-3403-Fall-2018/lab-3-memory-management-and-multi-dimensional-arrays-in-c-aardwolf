#include "mergesort.h"
#include <stdbool.h>

void mergesort(int size, int values[]){

}

void mergesortRange(int values[], int start, int end){
  int rangeSize = end - start;
  if(needSorting(rangeSize)){
    int midPoint = (star + end) / 2;
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}

void mergeRanges(int values[], int start, int mid, int end){
  int rangeSize = end- start;
  int destination [];
  int firstIndex = start;
  int secondIndex = mid;
  int copyIndex = 0;
}

bool needSorting(int rangeSize){
  return rangeSize >= 2;
}
