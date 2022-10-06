#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

// Put all helper functions at the top so they can be used in array_merge
int valueNumber(int, int*);
int uniqueNumbers(int, int*);
int* createCorrectArray(int, int, int*);

int* array_merge(int num_arrays, int* sizes, int** values) {

  int index = 0;
  // Call valueNumber function to grab the amount of values there are in total
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

  // Call uniqueNumbers() to get the amount of unique numebrs there are in the temporary array
  int unique = uniqueNumbers(valueAmount, temp);

  // Call createCorrectArray() to create the preferred array in result
  int *result = createCorrectArray(unique, valueAmount, temp);

  // Free the temporary array, as we no longer use it
  free((int*) temp);

  // Return the preferred array
  return result;
}

// Finds the amount of values there are in the 2D array
int valueNumber(int num_arrays, int* sizes) {
  int a = 0;
  for (int i = 0; i < num_arrays; i++) {
    a += sizes[i];
  }
  return a;
}

// Finds the amount of unique integers there are in the given array
int uniqueNumbers(int valueAmount, int* temp) {
  // If there are no integers, ) is returned
  if (valueAmount == 0) {
    return 0;
  }

  int count = 1;
  int LastNumber = temp[0];

  // Every time a new number is found in the array, the count is increased
  for (int i = 1; i < valueAmount; i++) {
    if (temp[i] != LastNumber) {
      count++;
      LastNumber = temp[i];
    }
  }
  return count;
}

// Creates the prefered array
int* createCorrectArray(int unique, int valueAmount, int* temp) {
  int *result = (int*) calloc(unique + 1, sizeof(int));
  result[0] = unique;
  // If there are no integers, return 0
  if (valueAmount == 0) {
    return result;
  }

  result[1] = temp[0];
  int LastNumber = temp[0];
  int index = 2;

  // For each unique number, put it into the new array
  for (int i = 1; i < valueAmount; i++) {
    if (temp[i] != LastNumber) {
      result[index] = temp[i];
      LastNumber = temp[i];
      index++;
    }
  }
  return result;
}
