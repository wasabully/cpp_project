#include "test_main.h"

TEST(queue, Constructor_Default) {
  s21::queue<int> queue;
  std::queue<int> queue_std;
  EXPECT_EQ(queue.empty(), queue_std.empty());
}

TEST(queue, Constructor_List) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  EXPECT_EQ(queue.front(), queue_std.front());
  EXPECT_EQ(queue.back(), queue_std.back());
  EXPECT_EQ(queue.size(), queue_std.size());
}

TEST(queue, Constructor_Copy) {
  s21::queue<int> queue = {1, 2, 3};
  s21::queue<int> queue_copy(queue);
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  std::queue<int> queue_std_copy(queue_std);
  EXPECT_EQ(queue.front(), queue_std.front());
  EXPECT_EQ(queue.back(), queue_std.back());
  EXPECT_EQ(queue_copy.size(), queue_std_copy.size());
}

TEST(queue, Constructor_Move) {
  s21::queue<int> queue = {1, 2, 3};
  s21::queue<int> queue_move(std::move(queue));
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  std::queue<int> queue_std_move(std::move(queue_std));
  EXPECT_EQ(queue.empty(), queue_std.empty());
}

TEST(queue, Operator_Copy) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  s21::queue<int> queue_copy;
  std::queue<int> queue_std_copy;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  queue_copy = queue;
  queue_std_copy = queue_std;
  EXPECT_EQ(queue.front(), queue_std.front());
  EXPECT_EQ(queue.back(), queue_std.back());
  EXPECT_EQ(queue_copy.size(), queue_std_copy.size());
  EXPECT_EQ(queue.empty(), queue_std.empty());
}

TEST(queue, Operator_Move) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  s21::queue<int> queue_move;
  std::queue<int> queue_std_move;
  queue_move = std::move(queue);
  queue_std_move = std::move(queue_std);
  EXPECT_EQ(queue.empty(), queue_std.empty());
}

TEST(queue, Front) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  EXPECT_EQ(queue.front(), queue_std.front());
}

TEST(queue, Back) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  EXPECT_EQ(queue.back(), queue_std.back());
}

TEST(queue, Empty) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  EXPECT_EQ(queue.empty(), queue_std.empty());
  s21::queue<int> queue_1;
  std::queue<int> queue_std_1;
  EXPECT_EQ(queue_1.empty(), queue_std_1.empty());
}

TEST(queue, Size) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  EXPECT_EQ(queue.size(), queue_std.size());
  s21::queue<int> queue_1;
  std::queue<int> queue_std_1;
  EXPECT_EQ(queue_1.size(), queue_std_1.size());
}

TEST(queue, Push) {
  s21::queue<int> queue;
  queue.push(1);
  queue.push(2);
  queue.push(3);
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  EXPECT_EQ(queue.front(), queue_std.front());
  EXPECT_EQ(queue.back(), queue_std.back());
  EXPECT_EQ(queue.size(), queue_std.size());
}

TEST(queue, Pop) {
  s21::queue<int> queue = {1, 2, 3};
  queue.pop();
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  queue_std.pop();
  EXPECT_EQ(queue.front(), queue_std.front());
  EXPECT_EQ(queue.back(), queue_std.back());
  EXPECT_EQ(queue.size(), queue_std.size());
  queue.pop();
  queue.pop();
  queue_std.pop();
  queue_std.pop();
  EXPECT_EQ(queue.empty(), queue_std.empty());
}

TEST(queue, Swap) {
  s21::queue<int> queue = {1, 2, 3};
  std::queue<int> queue_std;
  queue_std.push(1);
  queue_std.push(2);
  queue_std.push(3);
  s21::queue<int> queue_1;
  std::queue<int> queue_std_1;
  queue_1.swap(queue);
  queue_std_1.swap(queue_std);
  EXPECT_EQ(queue_1.front(), queue_std_1.front());
  EXPECT_EQ(queue_1.back(), queue_std_1.back());
  EXPECT_EQ(queue_1.size(), queue_std_1.size());
  EXPECT_EQ(queue_1.empty(), queue_std_1.empty());
}
