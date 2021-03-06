#include <gtest/gtest.h>

extern "C" {
#include "modulEngine/Core/BTree.h"
}

class BTreeTest : public ::testing::Test {
  protected:
	void SetUp() override {
		Result result = InitializeBTree(sizeof(int), 3, &b1);
		ASSERT_EQ(result, Success);
	}

	void TearDown() override {
		CleanupBTree(b1);
	}

	BTree b1 = nullptr;
};

TEST_F(BTreeTest, IsInitiallyEmpty) {
	EXPECT_TRUE(BTreeIsEmpty(b1));
}

TEST_F(BTreeTest, AfterInsertValueBTreeNotEmpty) {

	BTree_Insert(b1, )
}

