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
		CleanupArray(a1);
		CleanupArray(a2);
	}

	static bool CompareIntegers(void *a, void *b) {
		return *(int *)a == *(int *)b;
	}

	Array a1 = nullptr;
	Array a2 = nullptr;
};

TEST_F(ArrayTest, IsEmptyInitially) {
	EXPECT_EQ(Array_Length(a1), 0);
}

TEST_F(ArrayTest, HasLengthTen
) {
	EXPECT_EQ(Array_Length(a2), 10);
}

TEST_F(ArrayTest, InsertAndReadFromIndex
) {
	// Arrange
	ArrayResult result;
	int i = 16, j;
	result = Array_InsertAtIndex(a2, 5, &i);
	EXPECT_EQ(result, Success);

	// Act
	result = Array_GetDataFromIndex(a2, 5, &j);

	// Assert
	EXPECT_EQ(result, Success);
	EXPECT_EQ(j, i);
}

TEST_F(ArrayTest, WriteAtZeroIndexAndPopFront) {
	// Arrange
	ArrayResult result;
	int i = 21, j;
	result = Array_InsertAtIndex(a2, 0, &i);
	EXPECT_EQ(result, Success);

	// Act
	result = Array_PopFront(a2, &j);

	// Assert
	EXPECT_EQ(result, Success);
	EXPECT_EQ(i, j);
}

TEST_F(ArrayTest, WriteToIndexAndGetReference) {
	// Arrange
	ArrayResult result;
	int i = 31, j;
	int *ref;
	result = Array_InsertAtIndex(a2, 3, &i);
	EXPECT_EQ(result, Success);

	// Act
	result = Array_GetReference(a2, 3, (void **)(&ref));
	j = *ref;

	// Assert
	EXPECT_EQ(result, Success);
	EXPECT_EQ(i, j);
}

TEST_F(ArrayTest, GetReferenceAndAssignReferencedValue) {
	// Arrange
	ArrayResult result;
	int i = 31, j;
	int *ref;
	result = Array_GetReference(a2, 8, (void **)&ref);
	EXPECT_EQ(result, Success);

	// Act
	*ref = i;
	Array_GetDataFromIndex(a2, 8, &j);

	// Assert
	EXPECT_EQ(result, Success);
	EXPECT_EQ(i, j);
}

TEST_F(ArrayTest, PushBackIncreasesArraySizeAndAddsCorrectValueAtTheLastIndex) {
	// Arrange
	ArrayResult result;
	int i = 5234, initialLength = Array_Length(a1), j;

	// Act
	result = Array_PushBack(a1, &i);

	// Assert
	EXPECT_EQ(result, Success);
	EXPECT_EQ(initialLength + 1, Array_Length(a1));

	Array_GetDataFromIndex(a1, initialLength, &j);
	EXPECT_EQ(i, j);
	EXPECT_EQ(result, Success);
}

TEST_F(ArrayTest, GetIndexReturnsCorrectIndex) {
	// Arrange
	ArrayResult result;
	int i = 31, index = 6, j;
	result = Array_InsertAtIndex(a2, index, &i);
	EXPECT_EQ(result, Success);

	// Act
	result = Array_GetIndex(a2, CompareIntegers, &i, &j);

	// Assert
	EXPECT_EQ(result, Success);
	EXPECT_EQ(index, j);
}
