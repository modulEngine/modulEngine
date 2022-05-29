#ifndef COMPONENTSTORAGE_H_
#define COMPONENTSTORAGE_H_

#include "Array.h"
#include "BTree.h"
#include "EntityCounter.h"

// std
#include <stdint.h>
#include <stddef.h>

typedef uint32_t ComponentType;

typedef struct {
	Entity entity;
	void *componentData;
} Component;

typedef struct {
	BTree components;
	ComponentType type;
} ComponentArray;

typedef struct {
	Array componentArrays;
} ComponentStorage;

ComponentStorage CreateComponentStorage();
ComponentType RegisterComponentType(ComponentStorage componentStorage, size_t componentSize);
Component AddComponent(ComponentStorage componentStorage);

#endif // COMPONENTSTORAGE_H_
