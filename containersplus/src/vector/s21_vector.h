#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <algorithm>  // For std::copy, std::move, std::fill
#include <stdexcept>  // For std::out_of_range
#include <utility>    // For std::swap

namespace s21 {

template <typename T>
class s21_vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Конструкторы
  s21_vector();
  explicit s21_vector(size_type n);
  s21_vector(std::initializer_list<value_type> const &items);
  s21_vector(const s21_vector &v);
  s21_vector(s21_vector &&v) noexcept;
  ~s21_vector();

  // Операторы присваивания
  s21_vector &operator=(s21_vector &&v);

  // Методы доступа к элементам
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference front();
  const_reference back();
  T *data();

  // Итераторы
  iterator begin();
  iterator end();

  // Методы для работы с емкостью
  bool empty();
  size_type size();
  size_type max_size();
  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  // Модификаторы контейнера
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(s21_vector &other);

 private:
  T *elements;
  size_type num_elements;
  size_type array_capacity;

  void copy_elements(const s21_vector &other);
  void move_elements(s21_vector &&other);
  void destroy_elements();
  void reallocate(size_type new_capacity);
};

}  // namespace s21

#include "s21_vector.tpp"

#endif
