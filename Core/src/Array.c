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
	if (startingLength < 0)
		return InvalidSize;

	Array result = malloc(sizeof(struct Array_t));

	if (result == NULL)
		return OutOfMemory;
	result->dataSize = dataSize;

	result->length = startingLength;
	size_t size = 8;
	while (startingLength >= size) {
		size *= 2;
	}
	result->size = size;
	result->data = calloc(result->size, result->dataSize);

	if (result->data == NULL) {
		free(result);
		return OutOfMemory;
	}

	*pArray = result;
	return Success;
}

void CleanupArray(Array array) {
	free(array->data);
	free(array);
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

ArrayResult GetReference(Array array, int index, void **reference) {
	if (array->length < index || index < 0) {
		return InvalidIndex;
	}

	*reference = array->data + index * array->dataSize;
	return Success;
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

ArrayResult PopFront(Array array, void *data) {
	ArrayResult result;
	if ((result = GetDataFromIndex(array, 0, data)) != Success) {
		return result;
	}

	memmove(data, array->data, array->dataSize);

	for (int i = 0; i < array->length - 1; ++i) {
		memmove(array->data + i * array->dataSize, array->data + (i + 1) * array->dataSize, array->dataSize);
	}

	array->length--;
	return Success;
}

int ArrayLength(Array array) {
	return (int)array->length;
}
