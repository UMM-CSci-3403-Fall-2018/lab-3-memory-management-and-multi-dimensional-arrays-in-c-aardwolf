#include "mergesort.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//int main(int argc, char *argv[]){
  // int a[] = {1,2,3,4,5};
  // mergesort(5, a);
  //print_array(5,a);
// }
//
// void print_array(int length, int *array)
// {
//     for (int i = 0; i < length; i++) {
//         printf("%d, ",array[i]);
//     }
// }

bool needSorting(int rangeSize){
  return rangeSize >= 2;
}

void mergeRanges(int values[], int start, int mid, int end){
  int rangeSize = end- start;
  int* destination;
  destination = (int*) calloc(rangeSize, sizeof(int));
  int firstIndex = start;
  int secondIndex = mid;
  int copyIndex = 0;

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
  free(destination);
}

void mergesortRange(int values[], int start, int end){
  int rangeSize = end - start;
  //print_array(rangeSize, values);
  //printf("\n");

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
