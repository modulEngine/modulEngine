#include "Array.h"

#include <stdlib.h>
#include <string.h>

struct Array_t {
	void *data;
	size_t dataSize;
	uint32_t length;
	uint32_t size;
};

ArrayResult InitializeArray(size_t dataSize, Array *pArray) {
	return InitializeArrayWithSize(dataSize, 0, pArray);
}

ArrayResult InitializeArrayWithSize(size_t dataSize, int startingLength, Array *pArray) {
	Array result = malloc(sizeof(struct Array_t));
	if (result == NULL)
		return OutOfMemory;
	result->dataSize = dataSize;
	if (startingLength < 0)
		return InvalidSize;
	result->length = startingLength;
	size_t size = 8;
	while (startingLength < size) {
		size *= 2;
	}
	result->size = size;
	result->data = calloc(result->size, result->dataSize);
	if (result->data == NULL)
		return OutOfMemory;
	*pArray = result;
	return Success;
}

ArrayResult GetDataFromIndex(Array array, int index, void *data) {
	if (data == NULL) {
		return InvalidReference;
	}
	if (array->length < index || index < 0) {
		return InvalidIndex;
	}
	memcpy(data, array->data + index * array->dataSize, array->dataSize);
	return Success;
}

int ArrayLength(Array array) {
	return (int)array->length;
}

ArrayResult InsertAtIndex(Array array, int index, void *data) {
	if (data == NULL) {
		return InvalidReference;
	}
	if (array->length < index || index < 0) {
		return InvalidIndex;
	}
	memcpy(array->data + index * array->dataSize, data, array->dataSize);
	return Success;
}
