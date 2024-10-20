#ifndef S21_CONTAINERS_S21_QUEUE_H_
#define S21_CONTAINERS_S21_QUEUE_H_

#include "../list/s21_list.h"

namespace s21 {
template <typename T, class Container = list<T>>
class queue {
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

 public:
  queue() noexcept : list_() {}
  queue(std::initializer_list<value_type> const &items) : list_(items) {}
  queue(const queue &q) : list_(q.list_) {}
  queue(queue &&q) noexcept : list_(std::move(q.list_)) {}
  ~queue() noexcept {};
  queue &operator=(const queue &q) {
    list_ = q.list_;
    return *this;
  }
  queue operator=(queue &&q) noexcept {
    list_ = std::move(q.list_);
    return *this;
  }
  const_reference front() const noexcept { return list_.front(); }
  const_reference back() const noexcept { return list_.back(); }
  bool empty() const noexcept { return list_.empty(); }
  size_type size() const noexcept { return list_.size(); }
  void push(const_reference value) { list_.push_back(value); }
  void pop() noexcept { list_.pop_front(); }
  void swap(queue &other) noexcept { list_.swap(other.list_); };
  template <class... Args>
  void insert_many_back(Args &&...args) {
    list_.insert_many_back(std::forward<Args>(args)...);
  }

 private:
  Container list_;
};
}  // namespace s21

#endif  // S21_CONTAINERS_S21_QUEUE_H_