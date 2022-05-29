#ifndef BTREE_H_
#define BTREE_H_

// std
#include <stdbool.h>
#include <stddef.h>

typedef struct BTree_t *BTree;

typedef enum {
	Success,
} BTreeResult;

typedef bool (ComparisonFunction(void *, void *));

BTreeResult InitializeBTree(size_t dataSize, int keyCount, BTree *pBTree);
void CleanupBTree(BTree btree);

#endif // BTREE_H_

