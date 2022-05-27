#ifndef ECS_H_
#define ECS_H_

#include <stdint.h>

typedef struct ECS_t *ECS;
typedef uint64_t Entity;
typedef uint32_t ComponentType;
typedef struct System_t *System;

typedef enum {
	Update,
	FixedUpdate
} SystemMethodType;

typedef struct {
	SystemMethodType type;

	union {
		void (*Update)(void **components);
		void (*FixedUpdate)(void **components, float deltaTime);
	};
} SystemMethod;

void InitializeECS(ECS *pEcs);

void AddEntity(ECS ecs, Entity *pEntity);
void AddComponentType(ECS ecs, ComponentType *pComponentType);
void AddComponent(ECS ecs, ComponentType componentType, void *ComponentData);
void AddSystem(ECS ecs, uint32_t componentTypeCount, ComponentType componentTypes[], SystemMethod method, System *pSystem);

#endif //ECS_H_
