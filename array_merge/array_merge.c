#include<stdio.h>
#include<stdlib.h>

#include "array_merge.h"

//Include a main method for easier testing
int main(void)
{
  printf("Program started!\n");

  //Test data pulled from array_merge_test.cpp
  int num_arrays = 10;
  int sizes[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10 };
  int a0[] = { 3, 2, 0, 5, 8, 9, 6, 3, 2, 0 };
  int a1[] = { 5, 8, 9, 3, 2, 0, 6, 3, 2, 0 };
  int a2[] = { 8, 5, 0, 2, 3, 0, 2, 3, 6, 9 };
  int* a[] = { a0, a1, a2, a0, a1, a2, a0, a1, a2 };

  int* result;

  result = array_merge(num_arrays, sizes, a);
  int count = result[0];


  printf("Output:");
  print_array(count, result);
  return 0;
}

//Helper function to pritn arrays
void print_array(int size, int* array){
  for (int i = 0; i < size; i += 2){
    printf( "%d, ", array[i]);
  }
  printf("\n");
}

int* array_merge(int num_arrays, int* sizes, int** values){

  //Determine size of the results (note that this is currently estimating)
  int count;
  for(int i = 0; i < num_arrays; i ++){
    count += sizes[i];
  }

  //Create results based on count
  int* results = malloc((count*sizeof(int))+1);

  //Position is the current append position in results
  int position = 1;

  //Count as the first position -Remember that we still need to optimize this
  results[0] = count;

  //Loop over each sub-array
  for(int i = 0; i < num_arrays; i++){

    //print
    print_array(sizes[i],values[i]);

    //Loop over each element of each sub-array
    for(int j = 0; j < sizes[i]; j++){
      results[position] = values[i][j];
      printf(values[i][j] + "\n");
      position++;
    }
  }
  return sizes;
}



















//Comment
