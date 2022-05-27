#include <gtest/gtest.h>

extern "C" {
#include "modulEngine/Core/Array.h"
}

class ArrayTest : public ::testing::Test {
  protected:
	void SetUp() override {
		ArrayResult result = InitializeArray(sizeof(int), &a1);
		ASSERT_EQ(result, Success);
		result = InitializeArrayWithSize(sizeof(int), 10, &a2);
		ASSERT_EQ(result, Success);
	}

	void TearDown() override {
	}

	Array a1;
	Array a2;
};

TEST_F(ArrayTest, IsEmptyInitially) {
	EXPECT_EQ(ArrayLength(a1),
	          0);
}

TEST_F(ArrayTest, HasLengthTen
) {
	EXPECT_EQ(ArrayLength(a2),
	          10);
}

TEST_F(ArrayTest, InsertAndReadFromIndex
) {
	// Arrange
	ArrayResult result;
	int i = 16;
	result = InsertAtIndex(a2, 5, &i);
	EXPECT_EQ(result, Success
	);
	int j;

	// Act
	result = GetDataFromIndex(a2, 5, &j);

	// Assert
	EXPECT_EQ(result, Success
	);
	EXPECT_EQ(j, i
	);
}
