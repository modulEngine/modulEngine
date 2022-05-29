#ifndef COMPONENTSTORAGE_H_
#define COMPONENTSTORAGE_H_

#include "Array.h"

// std
#include <stdint.h>
#include <stddef.h>

typedef uint32_t ComponentType;

typedef struct {
	Array components;
	ComponentType type;
} ComponentArray;

typedef struct {
	Array componentArrays;
} ComponentStorage;

ComponentStorage CreateComponentStorage();
ComponentType RegisterComponentType(ComponentStorage componentStorage, size_t componentSize);

#endif // COMPONENTSTORAGE_H_
