#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "array_merge.h"

//Make sure the file strcuture stays the same so this is accessible!
#include "../mergesort/mergesort.c"

//This method determines whether an element is unique.
bool element_is_unique(int element, int size, int* values){
  for(int i = 1; i < size; i++){
    if(values[i] == element){
      return false;
    }
  }
  return true;
}

//The main method
int* array_merge(int num_arrays, int* sizes, int** values){

  //Generous estimate of size (will allocate space for doubles, which we don't need)
  int max_count = 0;
  for(int i = 0; i < num_arrays; i ++){
    max_count += sizes[i];
  }

  //Create space for results based on our estimate (this will almost always be too large)
  int* results = (int*) calloc(max_count + 1,sizeof(int));

  //Position represents a number of things: (We start at one since results[0] holds a special value)
  // - The current append-position in results
  // - The size of results
  int position = 1;

  //Build the results, removing non-unique elements and keeping track of size
  for(int i = 0; i < num_arrays; i++){

    //Loop over each element of each sub-array
    for(int j = 0; j < sizes[i]; j++){
      int v = values[i][j];

      //We only want to track unique elements
      if(element_is_unique(v,position,results)){
        results[position] = values[i][j];
        position++;
      }
    }
  }

  //Create an array of the proper size, which we will fill with results
  int* cleaned_results = (int*) calloc(position + 1, sizeof(int));

  //Fill with results
  for(int i = 1; i < position; i ++){
    cleaned_results[i] = results[i];
  }

  //Set the first elements of cleaned_results to the number of elements it contains
  cleaned_results[0] = (position-1);

  //Free memory
  if(results){
    free(results);
  }

  //Sort, as per the specifications
  mergesortRange(cleaned_results,1,position);

  //Return
  return(cleaned_results);
}



















//Comment
