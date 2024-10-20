#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <cstddef>  // For std::size_t
#include <initializer_list>
#include <stdexcept>  // For std::out_of_range

namespace s21 {

template <typename T, std::size_t N>
class s21_array {
 public:
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = std::size_t;

  // Constructors
  s21_array() = default;
  s21_array(std::initializer_list<value_type> const& items);
  s21_array(const s21_array& other);
  s21_array(s21_array&& other);

  // Destructor
  ~s21_array();

  // Assignment operators
  s21_array& operator=(const s21_array& other);
  s21_array& operator=(s21_array&& other);

  // Element access
  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator data();
  const_iterator data() const;

  // Iterators
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;

  // Capacity
  bool empty() const;
  size_type size() const;
  size_type max_size() const;

  // Modifiers
  void fill(const_reference value);
  void swap(s21_array& other);

 private:
  value_type elements[N];
};

// Non-member functions
template <typename T, std::size_t N>
void swap(s21_array<T, N>& lhs, s21_array<T, N>& rhs);

}  // namespace s21

#include "s21_array.tpp"

#endif  // S21_ARRAY_H
