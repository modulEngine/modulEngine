#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Array_t *Array;

typedef enum {
	Success,
	InvalidSize,
	InvalidIndex,
	InvalidReference,
	OutOfMemory,
	NotFound
} ArrayResult;

typedef bool (compareFunction(void *, void *));

ArrayResult InitializeArray(size_t dataSize, Array *pArray);
ArrayResult InitializeArrayWithSize(size_t dataSize, int startingLength, Array *pArray);
void CleanupArray(Array array);
ArrayResult Array_GetDataFromIndex(Array array, int index, void *data);
ArrayResult Array_GetReference(Array array, int index, void **reference);
ArrayResult Array_InsertAtIndex(Array array, int index, void *data);
ArrayResult Array_PopFront(Array array, void *data);
ArrayResult Array_PushBack(Array array, void *data);
ArrayResult Array_GetIndex(Array array, compareFunction compareFunction, void *searchData, int *pIndex);
int Array_Length(Array array);

#endif //ARRAY_H_
