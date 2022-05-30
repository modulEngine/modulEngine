#ifndef ENTITYCOUNTER_H_
#define ENTITYCOUNTER_H_

#include "Array.h"

// std
#include <stdint.h>

typedef uint64_t Entity;
typedef struct {
	uint64_t latestEntity;
	Array unusedEntities;
} EntityCounter;

EntityCounter CreateEntityCounter();

void CleanupEntityCounter(EntityCounter entityCounter);

Entity AddEntity(EntityCounter entityCounter);

void RemoveEntity(EntityCounter entityCounter, Entity entity);

#endif //ENTITYCOUNTER_H_
