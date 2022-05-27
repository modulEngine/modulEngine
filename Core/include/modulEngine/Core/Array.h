#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdint.h>
#include <stddef.h>

typedef struct Array_t *Array;

typedef enum {
	Success,
	InvalidSize,
	InvalidIndex,
	InvalidReference,
	OutOfMemory
} ArrayResult;

ArrayResult InitializeArray(size_t dataSize, Array *pArray);
ArrayResult InitializeArrayWithSize(size_t dataSize, int startingLength, Array *pArray);
void CleanupArray(Array array);
ArrayResult GetDataFromIndex(Array array, int index, void *data);
ArrayResult GetReference(Array array, int index, void **reference);
ArrayResult InsertAtIndex(Array array, int index, void *data);
ArrayResult PopFront(Array array, void *data);
int ArrayLength(Array array);

#endif //ARRAY_H_
