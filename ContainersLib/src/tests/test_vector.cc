#include "test_main.h"

// Test for default constructor
TEST(s21VectorTest, DefaultConstructor) {
  s21::s21_vector<int> v;
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_TRUE(v.empty());
}

// Test for parameterized constructor
TEST(s21VectorTest, ParameterizedConstructor) {
  s21::s21_vector<int> v(5);
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v.capacity(), 5);
  EXPECT_FALSE(v.empty());
}

// Test for initializer list constructor
TEST(s21VectorTest, InitializerListConstructor) {
  s21::s21_vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v.capacity(), 5);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(v[4], 5);
}

// Test for copy constructor
TEST(s21VectorTest, CopyConstructor) {
  s21::s21_vector<int> original = {1, 2, 3, 4, 5};
  s21::s21_vector<int> copy(original);
  EXPECT_EQ(copy.size(), 5);
  EXPECT_EQ(copy.capacity(), 5);
  EXPECT_FALSE(copy.empty());
  for (size_t i = 0; i < original.size(); ++i) {
    EXPECT_EQ(original[i], copy[i]);
  }
}

// Test for move constructor
TEST(s21VectorTest, MoveConstructor) {
  s21::s21_vector<int> original = {1, 2, 3, 4, 5};
  s21::s21_vector<int> temp(original);  // Make a copy to avoid destruction
  s21::s21_vector<int> moved(std::move(temp));
  EXPECT_EQ(moved.size(), 5);
  EXPECT_EQ(moved.capacity(), 5);
  EXPECT_FALSE(moved.empty());
  for (size_t i = 0; i < original.size(); ++i) {
    EXPECT_EQ(original[i], moved[i]);
  }
  EXPECT_EQ(temp.size(), 0);  // Moved from, should be empty
  EXPECT_EQ(temp.capacity(), 0);
  EXPECT_TRUE(temp.empty());
}

// Test for destructor
TEST(s21VectorTest, Destructor) {
  s21::s21_vector<int>* v = new s21::s21_vector<int>(5);
  delete v;
  // Destructor called, no specific checks needed
}

// Test for move assignment operator
TEST(s21VectorTest, MoveAssignmentOperator) {
  s21::s21_vector<int> v1 = {1, 2, 3, 4, 5};
  s21::s21_vector<int> v2(10);
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 5);
  EXPECT_EQ(v2.capacity(), 5);
  EXPECT_FALSE(v2.empty());
  for (size_t i = 0; i < v2.size(); ++i) {
    EXPECT_EQ(v2[i], i + 1);
  }
  EXPECT_EQ(v1.size(), 0);  // Moved from, should be empty
  EXPECT_EQ(v1.capacity(), 0);
  EXPECT_TRUE(v1.empty());
}

// Test for data method
TEST(s21VectorTest, DataMethod) {
  s21::s21_vector<int> v = {1, 2, 3, 4, 5};
  int* ptr = v.data();
  for (size_t i = 0; i < v.size(); ++i) {
    EXPECT_EQ(ptr[i], v[i]);
  }
}

// Test for begin and end methods
TEST(s21VectorTest, BeginEndMethods) {
  s21::s21_vector<int> v = {1, 2, 3, 4, 5};
  size_t i = 1;
  for (auto it = v.begin(); it != v.end(); ++it) {
    EXPECT_EQ(*it, i++);
  }
}

// Test for empty method
TEST(s21VectorTest, EmptyMethod) {
  s21::s21_vector<int> v;
  EXPECT_TRUE(v.empty());
  v.push_back(1);
  EXPECT_FALSE(v.empty());
}

// Test for size method
TEST(s21VectorTest, SizeMethod) {
  s21::s21_vector<int> v;
  EXPECT_EQ(v.size(), 0);
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  v.pop_back();
  EXPECT_EQ(v.size(), 0);
}

// Test for max_size method
TEST(s21VectorTest, MaxSizeMethod) {
  s21::s21_vector<int> v;
  // Expecting std::numeric_limits<size_t>::max()
  EXPECT_EQ(v.max_size(), std::numeric_limits<size_t>::max());
}

// Test for reserve method
TEST(s21VectorTest, ReserveMethod) {
  s21::s21_vector<int> v;
  v.reserve(10);
  EXPECT_EQ(v.capacity(), 10);
  EXPECT_GE(v.max_size(), v.capacity());
}

// Test for capacity method
TEST(s21VectorTest, CapacityMethod) {
  s21::s21_vector<int> v;
  EXPECT_EQ(v.capacity(), 0);
  v.push_back(1);
  EXPECT_EQ(v.capacity(), 1);
}

// Test for shrink_to_fit method
TEST(s21VectorTest, ShrinkToFitMethod) {
  s21::s21_vector<int> v(10);
  v.push_back(1);
  EXPECT_EQ(v.capacity(), 20);
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
}

// Test for clear method
TEST(s21VectorTest, ClearMethod) {
  s21::s21_vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.capacity(), 0);
  EXPECT_TRUE(v.empty());
}

// Test for insert method
TEST(s21VectorTest, InsertMethod) {
  s21::s21_vector<int> v = {1, 2, 3, 6, 7};
  auto it = v.insert(v.begin() + 3, 4);
  EXPECT_EQ(v.size(), 6);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

// Test for erase method
TEST(s21VectorTest, EraseMethod) {
  s21::s21_vector<int> v = {1, 2, 3, 4, 5};
  v.erase(v.begin() + 2);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[2], 4);
}

// Test for push_back method
TEST(s21VectorTest, PushBackMethod) {
  s21::s21_vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v.back(), 4);
}

// Test for pop_back method
TEST(s21VectorTest, PopBackMethod) {
  s21::s21_vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

// Test for swap method
TEST(s21VectorTest, SwapMethod) {
  s21::s21_vector<int> v1 = {1, 2, 3};
  s21::s21_vector<int> v2 = {4, 5};
  v1.swap(v2);
  EXPECT_EQ(v1.size(), 2);
  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_EQ(v2[0], 1);
}
