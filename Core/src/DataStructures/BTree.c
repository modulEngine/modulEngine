#include "BTree.h"

// std
#include <stdlib.h>

typedef struct node_t {
	int *value;
	int count;
	struct node_t **link;
} Node;

struct BTree_t {
	Node *root;
	int order, minInternal;
};

static Node *createNode(BTree bTree, int value, Node *child) {
	Node *newNode = malloc(sizeof(Node));
	newNode->value[0] = value;
	newNode->count = 1;
	newNode->link[0] = bTree->root;
	newNode->link[1] = child;
	return newNode;
}

static void insertNode(int value, int position, Node *node, Node *child) {
	int j = node->count;
	while (j > position) {
		node->value[j + 1] = node->value[j];
		node->link[j + 1] = node->link[j];
		j--;
	}
	node->value[j + 1] = value;
	node->link[j + 1] = child;
	node->count++;
}

static void splitNode(BTree bTree, int value, int *pValue, int position, Node *node, Node *child, Node **newNode) {
	int median;
	if (position > bTree->minInternal)
		median = bTree->minInternal + 1;
	else
		median = bTree->minInternal;

	*newNode = malloc(sizeof(Node));
	int j = median + 1;
	while (j <= bTree->order) {
		(*newNode)->value[j - median] = node->value[j];
		(*newNode)->link[j - median] = node->link[j];
		j++;
	}
	node->count = median;
	(*newNode)->count = bTree->order - median;

	if (position <= bTree->minInternal) {
		insertNode(value, position, node, child);
	} else {
		insertNode(value, position - median, *newNode, child);
	}
	*pValue = node->value[node->count];
	(*newNode)->link[0] = node->link[node->count];
	node->count--;
}

static bool setValue(BTree bTree, int value, int *pValue, Node *node, Node **child) {
	if (!node) {
		*pValue = value;
		*child = NULL;
		return true;
	}
	int pos;
	if (value < node->value[1]) {
		pos = 0;
	} else {
		for (pos = node->count; value < node->value[pos] && pos > 1; pos--);
		if (value == node->value[pos]) {
			return false;
		}
	}
	if (setValue(bTree, value, pValue, node->link[pos], child)) {
		if (node->count < bTree->order) {
			insertNode(*pValue, pos, node, *child);
		} else {
			splitNode(bTree, *pValue, pValue, pos, node, *child, child);
			return true;
		}
	}
	return false;
}

void BTree_Insert(BTree bTree, int value) {
	int i;
	Node *child;
	bool flag = setValue(bTree, value, &i, bTree->root, &child);
	if (flag) {
		bTree->root = createNode(bTree, i, child);
	}
}

static void search(BTree bTree, int value, int *pos, Node *myNode) {
	if (!myNode) {
		return;
	}

	if (value < myNode->value[1]) {
		*pos = 0;
	} else {
		for (*pos = myNode->count; value < myNode->value[*pos] && *pos > 1; *pos--);
		if (value == myNode->value[*pos]) {
			return;
		}
	}
	search(bTree, value, pos, myNode->link[*pos]);
	return;
}

static void traversal(Node *myNode) {
	if (myNode) {
		int i;
		for (i = 0; i < myNode->count; ++i) {
			traversal(myNode->link[i]);
			// value in myNode->value[i];
		}
		traversal(myNode->link[i]);
	}
}

Result InitializeBTree(size_t dataSize, int order, BTree *pBTree) {
	return Success;
}

void CleanupBTree(BTree bTree) {
}

bool BTreeIsEmpty(BTree bTree) {
	return true;
}
