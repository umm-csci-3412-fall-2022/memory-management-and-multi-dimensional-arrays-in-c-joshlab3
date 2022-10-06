#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int valueNumber(int, int*);

int uniqueNumbers(int, int*);

int* array_merge(int num_arrays, int* sizes, int** values) {

  int index = 0;
  int valueAmount = valueNumber(num_arrays, sizes);
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

  uniqueNumbers(valueAmount, temp);

  int *result = (int*) calloc(index, sizeof(int));

  result[0] = index - 1;


  index = 1;
  for (int i = 0; i < valueAmount; i++) {
    if (temp[i] != '\0') {
      result[index] = temp[i];
      index++;
    }
  }

  return sizes;
}

int valueNumber(int num_arrays, int* sizes) {
  int a = 0;
  for (int i = 0; i < num_arrays; i++) {
    a += sizes[i];
  }
  return a;
}

int uniqueNumbers(int valueAmount, int* temp) {
  if (valueAmount == 0) {
    return 0;
  }

  int index = 1;
  int LastNumber = temp[0];
  
  for (int i = 1; i < valueAmount; i++) {
    if (temp[i] != LastNumber) {
      index++;
      LastNumber = temp[i];
    }
  }
  return index;
}
