#include "mergesort.h"
#include <stdbool.h>
#include <cstdlib>

void mergesortRange(int[], int, int);
void mergeRanges(int[], int, int, int);
bool needsSorting(int);

void mergesort(int size, int values[]) {
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  //
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.
  mergesortRange(values, 0, size);
  return;
}

void mergesortRange(int values[], int p, int r) {
	int range = r - p;
	if (needsSorting(range)) {
		int q = (p + r) / 2;
		mergesortRange(values, p, q);
		mergesortRange(values, q, r);
		mergeRanges(values, p, q, r);
	}
}

void mergeRanges(int values[], int p, int q, int r) {
	const int range = r - p;
	int sorted[range];
	int firstIndex = p;
	int secondIndex = q;
	int copyIndex = 0;	
	while (firstIndex < q && secondIndex < r) {
		if (values[firstIndex] < values[secondIndex]) {
			sorted[copyIndex] = values[firstIndex];
			++firstIndex;
		} else {
			sorted[copyIndex] = values[secondIndex];
			++secondIndex;
		}
		++copyIndex;
	}	
	while (firstIndex < q) {
		sorted[copyIndex] = values[firstIndex];
		++copyIndex;
		++firstIndex;
	}
	while (secondIndex < r) {
		sorted[copyIndex] = values[secondIndex];
		++copyIndex;
		++secondIndex;
	}
	for (int i = 0; i < range; i++) {
		values[i + p] = sorted[i];
	}
	// free((void*) range);
}

bool needsSorting(int range) {
	return range >= 2;
}
