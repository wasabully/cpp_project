#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int rows, int cols) {
  if ((rows && cols < 1) || (rows < 1 && cols)) {
    throw std::invalid_argument("Invalid matrix");
  }
  rows_ = rows;
  cols_ = cols;
  AllocateMemory();
}

S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  AllocateMemory();
  CopyFrom(other);
}

S21Matrix::S21Matrix(S21Matrix &&other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.rows_ = other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { RemoveMatrix(); }

int S21Matrix::GetCols() const { return cols_; }
int S21Matrix::GetRows() const { return rows_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) {
    throw std::invalid_argument("Invalid rows");
  }

  ResizeMatrix(rows, cols_);
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) {
    throw std::invalid_argument("Invalid cols");
  }

  ResizeMatrix(rows_, cols);
}

void S21Matrix::ResizeMatrix(int newRows, int newCols) {
  S21Matrix temp(newRows, newCols);

  for (int i = 0; i < std::min(rows_, newRows); ++i) {
    std::copy(matrix_[i], matrix_[i] + std::min(cols_, newCols),
              temp.matrix_[i]);
  }

  *this = temp;
}
