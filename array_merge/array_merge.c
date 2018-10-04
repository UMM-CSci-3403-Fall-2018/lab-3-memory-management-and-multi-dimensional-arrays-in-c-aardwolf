#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "array_merge.h"
#include "../mergesort/merge_sort.h"
//Helper function to printint arrays
void print_array(int size, int* array){
  printf("\nSize: %d\nElements: ", array[0]);
  for (int i = 1; i < size + 1; i += 1){
    printf( "%d, ", array[i]);
  }
  printf("\n");
}

//Include a main method for easier testing
// int main(void)
// {
//   //printf("Program started!\n");
//
//   //Test data pulled from array_merge_test.cpp
//   int num_arrays = 9;
//   int sizes[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10 };
//   int a0[] = { 3, 2, 0, 5, 8, 9, 6, 3, 2, 0 };
//   int a1[] = { 5, 8, 9, 3, 2, 0, 6, 3, 2, 0 };
//   int a2[] = { 8, 5, 0, 2, 3, 0, 2, 3, 6, 9 };
//   int* a[] = { a0, a1, a2, a0, a1, a2, a0, a1, a2 };
//
//   //printf("Preparing to merge...!\n");
//   int* result = array_merge(num_arrays, sizes, a);
//   int count = result[0];
//
//
//   //printf("\nOutput:");
//   print_array(count, result);
//   return 0;
// }

bool element_is_unique(int element, int size, int* values){
  for(int i = 1; i < size; i++){
    if(values[i] == element){
      return false;
    }
  }
  //printf("Element is not unique...\n");
  return true;
}

int* array_merge(int num_arrays, int* sizes, int** values){
  //printf("Starting merge...\n");

  //Estimate of size
  int max_count;
  for(int i = 1; i < num_arrays; i ++){
    max_count += sizes[i];
  }

  //Create results based on count (estimate)
  int* results = (int*) malloc((max_count * sizeof(int))+1);

  //Position is the current append pprint_arrosition in results
  int position = 1;

  //Count as the first position -Remember that we still need to optimize this

  //Loop over each sub-array
  for(int i = 0; i < num_arrays; i++){

    //print
    //print_array(sizes[i],results);

    //Loop over each element of each sub-array]);
    for(int j = 0; j < sizes[i]; j++){
      int v = values[i][j];
      if(element_is_unique(v,position,results)){
        results[position] = values[i][j];
        //printf("%d\n", values[i][j]);
        position++;
      }
    }
  }
  int* cleaned_results = (int*) malloc((position*sizeof(int)));
  for(int i = 1; i < position; i ++){
    cleaned_results[i] = results[i];
  }
  cleaned_results[0] = (position-1);
  free(results);
  mergesortRange(cleaned_results,1,position-1)
  return(cleaned_results);
}



















//Comment
