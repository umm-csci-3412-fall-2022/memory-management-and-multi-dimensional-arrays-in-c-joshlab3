#include "array_merge.h"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  
  int index = 0;
  int valueAmount = sizeof(values)/4;
  int *result = (int*) calloc(valueAmount + 1, sizeof(int));
  int *temp = (int*) calloc(valueAmount, sizeof(int));

  // Put all numbers from the values 2D-array into the temporary array list
  for (int i = 0; i < num_arrays; i++) {
    for (int j = 0; j < sizes[i]; j++) {
      temp[index] = values[i][j];
      index++;
    }
  }

  // Sort the values in the temporary array list
  mergesort(valueAmount, temp);

  int LastNumber = temp[0]; 
  for (int i = 1; i < valueAmount; i++) {
    if (temp[i] == LastNumber) {
      temp[i] = '\0';
    } else {
      LastNumber = temp[i];
    }
  }



 	

  return sizes;
}
