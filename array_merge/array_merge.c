#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int valueNumber(int, int*);
int uniqueNumbers(int, int*);
int* createCorrectArray(int, int, int*);

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

  int unique = uniqueNumbers(valueAmount, temp);

  int *result = createCorrectArray(unique, valueAmount, temp);


  return result;
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

int* createCorrectArray(int unique, int valueAmount, int* temp) {
  int *result = (int*) calloc(unique + 1, sizeof(int));
  result[0] = unique;

  if (valueAmount == 0) {
    return result;
  }

  result[1] = temp[0];
  int LastNumber = temp[0];
  int index = 2;

  for (int i = 1; i < valueAmount; i++) {
    if (temp[i] != LastNumber) {
      result[index] = temp[i];
      index++;
    }
  }
  return result;
}
