#ifndef ARRAY_H_
#define ARRAY_H_

#include "Result.h"

// std
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Array_t *Array;

typedef bool (compareFunction(void *, void *));

Result InitializeArray(size_t dataSize, Array *pArray);

Result InitializeArrayWithSize(size_t dataSize, int startingLength, Array *pArray);

void CleanupArray(Array array);

Result Array_GetDataFromIndex(Array array, int index, void *data);

Result Array_GetReference(Array array, int index, void **reference);

Result Array_InsertAtIndex(Array array, int index, void *data);

Result Array_PopFront(Array array, void *data);

Result Array_PushBack(Array array, void *data);

Result Array_GetIndex(Array array, compareFunction compareFunction, void *searchData, int *pIndex);

int Array_Length(Array array);

#endif //ARRAY_H_
