#include <gtest/gtest.h>

extern "C" {
#include "modulEngine/Core/BTree.h"
}

class BTreeTest : public ::testing::Test {
  protected:
	void SetUp() override {
		BTreeResult result = InitializeBTree(sizeof(int), 3, &b1);
		ASSERT_EQ(result, Success);
	}

	void TearDown() override {
		CleanupBTree(b1);
	}

	BTree b1 = nullptr;
}

