#include "array_merge.h"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  
  int index = 0;
  int *result = (int*) calloc(sizeof(values)/4 + 1, sizeof(int));
  int *temp = (int*) calloc(sizeof(values)/4, sizeof(int));

  // Put all numbers from the values 2D-array into the temporary array list
  for (int i = 0; i < num_arrays; i++) {
    for (int j = 0; j < sizes[i]; j++) {
      temp[index] = values[i][j];
      index++;
    }
  }

  // Sort the values in the temporary array list
  mergesort(sizeof(values)/4, temp);




 	

  return sizes;
}
