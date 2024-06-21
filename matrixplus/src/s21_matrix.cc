#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool checking = true;
  if (rows_ != other.rows_ || cols_ != other.cols_ || matrix_ == nullptr ||
      other.matrix_ == nullptr)
    checking = false;
  for (int i = 0; i < rows_ && checking; ++i) {
    for (int j = 0; j < cols_ && checking; ++j) {
      if (fabs(other.matrix_[i][j] - matrix_[i][j]) >= 1e-8) {
        checking = false;
      }
    }
  }
  return checking;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_ || matrix_ == nullptr ||
      other.matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.rows_ || cols_ != other.cols_ || matrix_ == nullptr ||
      other.matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] *= num;
    }
  }
}
void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.rows_ || matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }
  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.cols_; ++j) {
      for (int d = 0; d < other.rows_; d++) {
        res.matrix_[i][j] += matrix_[i][d] * other.matrix_[d][j];
      }
    }
  }
  *this = res;
}

S21Matrix S21Matrix::Transpose() {
  if (matrix_ == nullptr) {
    throw std::invalid_argument("Invalid matrix");
  }
  S21Matrix res(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      res.matrix_[j][i] = matrix_[i][j];
    }
  }
  return res;
}

S21Matrix S21Matrix::CalcComplements() {
  validateMatrix();

  S21Matrix result_m(rows_, cols_);
  if (rows_ == 1) {
    result_m.matrix_[0][0] = matrix_[0][0];
  } else {
    S21Matrix M(rows_ - 1, cols_ - 1);
    double d;
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        M.MinorMatrix(*this, i, j);
        d = M.Determinant();
        result_m.matrix_[i][j] = d * std::pow(-1, i + j);
      }
    }
  }
  return result_m;
}

double S21Matrix::Determinant() {
  validateMatrix();

  double result = 0;
  if (rows_ == 1)
    result = matrix_[0][0];
  else if (rows_ == 2)
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  else if (rows_ > 2) {
    S21Matrix M(rows_ - 1, cols_ - 1);
    for (int i = 0; i < cols_; ++i) {
      M.MinorMatrix(*this, 0, i);
      double temp = M.Determinant();
      result += std::pow((-1), i) * temp * matrix_[0][i];
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  validateMatrix();
  double d = Determinant();

  if (d == 0) {
    throw std::invalid_argument("Zero determinant");
  }

  S21Matrix G(CalcComplements());
  S21Matrix G_transp(G.Transpose());
  S21Matrix result = G_transp;
  result.MulNumber(1.0 / d);
  return result;
}