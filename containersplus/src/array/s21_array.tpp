#ifndef S21_ARRAY_TPP
#define S21_ARRAY_TPP

#include "s21_array.h"

namespace s21 {

// Element access
template <typename T, std::size_t N>
typename s21_array<T, N>::reference s21_array<T, N>::at(size_type pos) {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return elements[pos];
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_reference s21_array<T, N>::at(
    size_type pos) const {
  if (pos >= N) {
    throw std::out_of_range("Index out of range");
  }
  return elements[pos];
}

template <typename T, std::size_t N>
typename s21_array<T, N>::reference s21_array<T, N>::operator[](size_type pos) {
  return elements[pos];
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_reference s21_array<T, N>::operator[](
    size_type pos) const {
  return elements[pos];
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_reference s21_array<T, N>::front() const {
  return elements[0];
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_reference s21_array<T, N>::back() const {
  return elements[N - 1];
}

// Iterators
template <typename T, std::size_t N>
typename s21_array<T, N>::iterator s21_array<T, N>::data() {
  return elements;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_iterator s21_array<T, N>::data() const {
  return elements;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::iterator s21_array<T, N>::begin() {
  return elements;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::iterator s21_array<T, N>::end() {
  return elements + N;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_iterator s21_array<T, N>::begin() const {
  return elements;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::const_iterator s21_array<T, N>::end() const {
  return elements + N;
}

// Capacity
template <typename T, std::size_t N>
bool s21_array<T, N>::empty() const {
  return N == 0;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::size_type s21_array<T, N>::size() const {
  return N;
}

template <typename T, std::size_t N>
typename s21_array<T, N>::size_type s21_array<T, N>::max_size() const {
  return N;
}

// Default constructor with initializer list
template <typename T, std::size_t N>
s21_array<T, N>::s21_array(std::initializer_list<value_type> const& items)
    : elements{} {
  if (items.size() > N) {
    throw std::out_of_range("Initializer list size exceeds array capacity");
  }

  auto iter = items.begin();
  for (std::size_t i = 0; i < N && iter != items.end(); ++i, ++iter) {
    elements[i] = *iter;
  }
}

// Copy constructor
template <typename T, std::size_t N>
s21_array<T, N>::s21_array(const s21_array& other) : elements{} {
  std::copy(other.elements, other.elements + N, elements);
}

//  Move constructor
template <typename T, std::size_t N>
s21_array<T, N>::s21_array(s21_array&& other) : elements{} {
  std::move(other.elements, other.elements + N, elements);
  std::fill(other.elements, other.elements + N, value_type());
}

// Destructor

template <typename T, std::size_t N>
s21_array<T, N>::~s21_array() {
  for (std::size_t i = 0; i < N; ++i) {
    elements[i] = T();
  }
}

// Copy assignment operator
template <typename T, std::size_t N>
s21_array<T, N>& s21_array<T, N>::operator=(const s21_array& other) {
  if (this != &other) {
    std::copy(other.elements, other.elements + N, elements);
  }
  return *this;
}

// Move assignment operator

template <typename T, std::size_t N>
s21_array<T, N>& s21_array<T, N>::operator=(s21_array&& other) {
  if (this != &other) {
    std::move(other.elements, other.elements + N, elements);
    std::fill(other.elements, other.elements + N, value_type());
  }
  return *this;
}

// Modifiers
template <typename T, std::size_t N>
void s21_array<T, N>::fill(const_reference value) {
  std::fill(elements, elements + N, value);
}

template <typename T, std::size_t N>
void s21_array<T, N>::swap(s21_array& other) {
  std::swap_ranges(elements, elements + N, other.elements);
}

// Non-member function
template <typename T, std::size_t N>
void swap(s21_array<T, N>& lhs, s21_array<T, N>& rhs) {
  lhs.swap(rhs);
}

}  // namespace s21

#endif  // S21_ARRAY_TPP
