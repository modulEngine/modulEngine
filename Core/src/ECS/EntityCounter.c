#include "EntityCounter.h"

// std
#include <stdbool.h>

static bool EntityCompareFunction(void *a, void *b);

EntityCounter CreateEntityCounter() {
	EntityCounter result;
	result.latestEntity = 1;
	InitializeArray(sizeof(uint64_t), &result.unusedEntities);
	return result;
}

void CleanupEntityCounter(EntityCounter entityCounter) {
	CleanupArray(entityCounter.unusedEntities);
}

Entity AddEntity(EntityCounter entityCounter) {
	if (Array_Length(entityCounter.unusedEntities) != 0) {
		Entity result;
		Array_PopFront(entityCounter.unusedEntities, &result);
		return result;
	}

	return entityCounter.latestEntity++;
}

void RemoveEntity(EntityCounter entityCounter, Entity entity) {
	if (entityCounter.latestEntity - 1 == entity) {
		entityCounter.latestEntity--;
		Entity e = entityCounter.latestEntity - 1;
		int index;
		while (Array_GetIndex(entityCounter.unusedEntities, EntityCompareFunction, &e, &index) == Success) {
			int z = 0;
			Array_InsertAtIndex(entityCounter.unusedEntities, index, &z);
			entityCounter.latestEntity--;
			e = entityCounter.latestEntity - 1;
		}
	} else {
		Array_PushBack(entityCounter.unusedEntities, &entity);
	}
}

bool EntityCompareFunction(void *a, void *b) {
	return *(uint64_t *) a == *(uint64_t *) b;
}
