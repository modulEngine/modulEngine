#include "ComponentStorage.h"

ComponentStorage CreateComponentStorage() {
	ComponentStorage result;
	InitializeArray(sizeof(ComponentArray), &result.componentArrays);
	return result;
}

ComponentType RegisterComponentType(ComponentStorage componentStorage, size_t componentSize) {
	ComponentArray a;
	a.type = Array_Length(componentStorage.componentArrays);
	InitializeArray(componentSize, &a.components);

	Array_PushBack(componentStorage.componentArrays, &a);

	return a.type;
}

