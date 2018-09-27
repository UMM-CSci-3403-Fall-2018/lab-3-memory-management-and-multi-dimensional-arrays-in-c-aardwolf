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
  while (firstIndex < mid && secondIndex < end){
    if(values[firstIndex]< values[secondIndex]){
      destination[copyIndex]= values[secondIndex];
      ++firstIndex;
    } else {
      destination[copyIndex]=values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex
  }

  while(firstIndex < mid){
    destination[copyIndex]= values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }

  while (secondIndex < end) {
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
  }

  for int i = 0; i < rangeSize; ++i){
    values[i + startIndex] = destination[i];
  }
}

bool needSorting(int rangeSize){
  return rangeSize >= 2;
}
