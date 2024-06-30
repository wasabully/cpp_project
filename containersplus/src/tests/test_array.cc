#include <gtest/gtest.h>

#include "test_main.h"

TEST(S21ArrayTest, Data) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test obtaining a non-const pointer to the first element
  int* data_ptr = arr.data();
  EXPECT_EQ(*data_ptr, 1);

  // Modify the first element using the pointer
  *data_ptr = 100;
  EXPECT_EQ(arr[0], 100);
}

TEST(S21ArrayTest, ConstData) {
  const s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test obtaining a const pointer to the first element
  const int* data_ptr = arr.data();
  EXPECT_EQ(*data_ptr, 1);
}

TEST(S21ArrayTest, BeginEnd) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test iterators
  auto it_begin = arr.begin();
  auto it_end = arr.end();

  EXPECT_EQ(*it_begin, 1);
  EXPECT_EQ(*(it_end - 1), 3);

  // Modify the first element using the iterator
  *it_begin = 100;
  EXPECT_EQ(arr[0], 100);
}

TEST(S21ArrayTest, ConstBeginEnd) {
  const s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test const iterators
  auto it_begin = arr.begin();
  auto it_end = arr.end();

  EXPECT_EQ(*it_begin, 1);
  EXPECT_EQ(*(it_end - 1), 3);
}

TEST(S21ArrayTest, FrontAt) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test accessing the first element
  EXPECT_EQ(arr.front(), 1);
}

TEST(S21ArrayTest, OperatorBracket) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test accessing valid index
  EXPECT_EQ(arr[0], 1);
  EXPECT_EQ(arr[1], 2);
  EXPECT_EQ(arr[2], 3);
}

// Test case for s21_array::front method
TEST(S21ArrayTest, Front) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test accessing first element
  EXPECT_EQ(arr.front(), 1);
}

// Test case for s21_array::back method
TEST(S21ArrayTest, Back) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Test accessing last element
  EXPECT_EQ(arr.back(), 3);
}

TEST(S21ArrayTest, CopyConstructor) {
  s21::s21_array<int, 3> arr = {1, 2, 3};
  s21::s21_array<int, 3> copy_arr(arr);

  // Проверяем, что значения скопированы правильно
  EXPECT_EQ(copy_arr[0], arr[0]);
  EXPECT_EQ(copy_arr[1], arr[1]);
  EXPECT_EQ(copy_arr[2], arr[2]);
}

TEST(S21ArrayTest, MoveConstructor) {
  s21::s21_array<int, 3> arr = {1, 2, 3};
  s21::s21_array<int, 3> move_arr(std::move(arr));

  // Проверяем, что значения скопированы правильно
  EXPECT_EQ(move_arr[0], 1);
  EXPECT_EQ(move_arr[1], 2);
  EXPECT_EQ(move_arr[2], 3);

  // Проверяем, что исходный массив пуст
  EXPECT_EQ(arr[0], 0);
  EXPECT_EQ(arr[1], 0);
  EXPECT_EQ(arr[2], 0);
}

TEST(S21ArrayTest, Fill) {
  s21::s21_array<int, 3> arr = {1, 2, 3};

  // Fill array with value 5
  arr.fill(5);

  // Check if all elements are set to 5
  EXPECT_EQ(arr[0], 5);
  EXPECT_EQ(arr[1], 5);
  EXPECT_EQ(arr[2], 5);
}

TEST(S21ArrayTest, Swap) {
  s21::s21_array<int, 3> arr1 = {1, 2, 3};
  s21::s21_array<int, 3> arr2 = {4, 5, 6};

  // Swap arrays
  swap(arr1, arr2);

  // Check if elements are swapped correctly
  EXPECT_EQ(arr1[0], 4);
  EXPECT_EQ(arr1[1], 5);
  EXPECT_EQ(arr1[2], 6);

  EXPECT_EQ(arr2[0], 1);
  EXPECT_EQ(arr2[1], 2);
  EXPECT_EQ(arr2[2], 3);
}

TEST(S21ArrayTest, AssignmentOperators) {
  s21::s21_array<int, 3> arr1 = {1, 2, 3};
  s21::s21_array<int, 3> arr2;

  // Copy assignment
  arr2 = arr1;

  // Check if arr2 contains the same elements as arr1
  EXPECT_EQ(arr2[0], arr1[0]);
  EXPECT_EQ(arr2[1], arr1[1]);
  EXPECT_EQ(arr2[2], arr1[2]);

  // Move assignment
  arr2 = std::move(arr1);

  // Check if arr2 now contains the elements of arr1 after move
  EXPECT_EQ(arr2[0], 1);
  EXPECT_EQ(arr2[1], 2);
  EXPECT_EQ(arr2[2], 3);
}
