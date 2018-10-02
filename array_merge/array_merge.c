#include<stdio.h>
#include<stdlib.h>

#include "array_merge.h"

//Include a main method for easier testing
int main(void)
{
  printf("Program started!\n");

  //Test data pulled from array_merge_test.cpp
  int num_arrays = 10;
  int sizes[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
  int a0[] = { 3, 2, 0, 5, 8, 9, 6, 3, 2, 0 };
  int* a[] = { a0, a0, a0, a0, a0, a0, a0, a0, a0, a0 };
  int expected[] = { 7, 0, 2, 3, 5, 6, 8, 9 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  return 0;
}

//Helper function to pritn arrays
void print_array(int* array){
  for (i = 0; i < 10; i += 2){
    printf( "%d, ", array[i]);
  }
}

int* array_merge(int num_arrays, int* sizes, int** values){

  //Determine size of the results (note that this is currently estimating)
  int count;
  for(int i = 0; i < num_arrays; i ++){
    count += sizes[i];
  }

  //Create results based on count
  int* results = malloc(count*sizeof(int));

  //Position is the current append position in results
  int position = 0;

  //Loop over each sub-array
  for(int i = 0; i < num_arrays; i++){

    //Loop over each element of each sub-array
    for(int j = 0; j < sizes[i]; j++){
      results[position] = values[i][j];
      position++;
    }
  }
  return sizes;
}
