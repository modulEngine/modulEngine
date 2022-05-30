#ifndef BTREE_H_
#define BTREE_H_

#include "Result.h"

// std
#include <stdbool.h>
#include <stddef.h>

typedef struct BTree_t *BTree;

typedef bool (ComparisonFunction(void *, void *));

Result InitializeBTree(size_t dataSize, int order, BTree *pBTree);

void CleanupBTree(BTree btree);

bool BTreeIsEmpty(BTree btree);

#endif // BTREE_H_

