#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "array_merge.h"
#include "../mergesort/mergesort.c"

bool element_is_unique(int element, int size, int* values){
  for(int i = 1; i < size; i++){
    if(values[i] == element){
      return false;
    }
  }
  return true;
}

int* array_merge(int num_arrays, int* sizes, int** values){

  //Estimate of size
  int max_count = 0;
  for(int i = 0; i < num_arrays; i ++){
    max_count += sizes[i];
  }

  //Create results based on count (estimate)
  int* results = (int*) calloc(max_count + 1,sizeof(int));

  //Position is the current append pprint_arrosition in results
  int position = 1;

  //Count as the first position -Remember that we still need to optimize this

  //Loop over each sub-array
  for(int i = 0; i < num_arrays; i++){

    //Loop over each element of each sub-array]);
    for(int j = 0; j < sizes[i]; j++){
      int v = values[i][j];
      if(element_is_unique(v,position,results)){
        results[position] = values[i][j];
        position++;
      }
    }
  }
  int* cleaned_results = (int*) calloc(position + 1, sizeof(int));
  for(int i = 1; i < position; i ++){
    cleaned_results[i] = results[i];
  }
  cleaned_results[0] = (position-1);
  if(results){
    free(results);
  }
  mergesortRange(cleaned_results,1,position);
  return(cleaned_results);
}



















//Comment
