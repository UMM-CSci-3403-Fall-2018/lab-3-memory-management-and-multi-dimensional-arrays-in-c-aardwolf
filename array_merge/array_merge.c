#include<stdio.h>
#include "array_merge.h"

int main(void)
{
  printf("Program started!\n");

  int num_arrays = 10;
  int sizes[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
  int a0[] = { 3, 2, 0, 5, 8, 9, 6, 3, 2, 0 };
  int* a[] = { a0, a0, a0, a0, a0, a0, a0, a0, a0, a0 };
  int expected[] = { 7, 0, 2, 3, 5, 6, 8, 9 };
  int* result;

  result = array_merge(num_arrays, sizes, a);
  return 0;
}

int* array_merge(int num_arrays, int* sizes, int** values){
  int count;
  for(i = 0; i < num_arrays; i ++){
    count += sizes[i]
  }

  int* results = malloc(count*sizeof(int));
  int position = 0;

  for(i = 0; i < num_arrays; i++){
    for(j = 0; j < sizes[i]){
      results[position] = values[i][j];
      position += 1;
    }
  }
  return sizes;
}
