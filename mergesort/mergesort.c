#include "mergesort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


// sorts the array if it has a size greater than 1
bool needSorting(int rangeSize){
  return rangeSize >= 2;
}
// a  method to merge the ranges
void mergeRanges(int values[], int start, int mid, int end){
  int rangeSize = end- start;
  int* destination;
  destination = (int*) calloc(rangeSize, sizeof(int));
  int firstIndex = start;
  int secondIndex = mid;
  int copyIndex = 0;

//goes through and sorts the array based on the location in the
//array

  while (firstIndex < mid && secondIndex < end){
    if(values[firstIndex]< values[secondIndex]){
      destination[copyIndex]= values[firstIndex];
      ++firstIndex;
    } else {
      destination[copyIndex]=values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
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

  for (int i = 0; i < rangeSize; ++i){
    values[i + start] = destination[i];
  }
  //eliminates any memory leaks
  free(destination);
}

void mergesortRange(int values[], int start, int end){
  int rangeSize = end - start;
//if it needs to be sorted, then it sorts the arrays and merges them together
  if(needSorting(rangeSize)){
    int midPoint = (start + end) / 2;
    mergesortRange(values, start, midPoint);
    mergesortRange(values, midPoint, end);
    mergeRanges(values, start, midPoint, end);
  }
}

void mergesort(int size, int values[]){
	mergesortRange(values,0,size);
}
