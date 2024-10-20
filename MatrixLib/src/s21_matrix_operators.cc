#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  RemoveMatrix();
  CopyMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) {
  RemoveMatrix();
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result = *this;
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result = *this;
  result.MulNumber(num);
  return result;
}

void S21Matrix::operator+=(const S21Matrix &other) { SumMatrix(other); }
void S21Matrix::operator-=(const S21Matrix &other) { SubMatrix(other); }
void S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); }
void S21Matrix::operator*=(const double num) { MulNumber(num); }
double &S21Matrix::operator()(int i, int j) {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0 || matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }
  return matrix_[i][j];
}
double &S21Matrix::operator()(int i, int j) const {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0 || matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }
  return matrix_[i][j];
}