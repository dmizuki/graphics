// Matrix.h

#ifndef _MATRIX_H_
#define _MATRIX_H_

// This is a class that represents a matrix structure and includes methods 
// The matrix is represented in column major format.
template <typename T>
class Matrix
{
  public:
    // Constructor using an array of size columns * rows.
    Matrix(unsigned int nColumns, unsigned int nRows, const T elements[]);
    // Copy constructor.
    explicit Matrix(const Matrix<T>& matrix);
    ~Matrix();
    T* elements();
    const T* elements() const;
    Matrix<T> transpose();
    Matrix<T> invert();
    // The operator T* functions allows for explicit and implicit type casting
    // from Matrix<T> to T*.  When called, a pointer to the first element in the
    // matrix is returned. 
    operator T*();
    operator const T*() const;
    // The operator() functions act as the access operators.
    T& operator()(unsigned int column, unsigned int row);
    T operator()(unsigned int column, unsigned int row) const;
    Matrix<T> operator+(const Matrix<T>& otherMatrix) const;
    Matrix<T> operator-(const Matrix<T>& otherMatrix) const;
    Matrix<T> operator*(const Matrix<T>& otherMatrix) const;
  private:
    T* _elements;
    int _nColumns;
    int _nRows;
    Matrix<T> matrixAddition(const Matrix<T>& otherMatrix) const;
    Matrix<T> matrixSubtraction(const Matrix<T>& otherMatrix) const;
    Matrix<T> matrixMultiply(const Matrix<T>& otherMatrix) const; 
};

template <typename T>
class SquareMatrix : public Matrix
{
  public:
    // Constructor using an array of size dimention * dimention.
    SquareMatrix(unsigned int dimention, const T elements[])
    // Copy constructor
    explicit SquareMatrix(const SquareMatrix& matrix);
    float determinant() const;
}

template <typename T>
class Matrix3x3 : public SquareMatrix
{
  public:
    // Constructor using individual elements.
    //        row 0       row 1       row 2
    Matrix3x3(T element0, T element1, T element2,  // column 0
              T element3, T element4, T element5,  // column 1
              T element6, T element7, T element8); // column 2
    // Constructor using an array of size 9.
    explicit Matrix3x3(T elements[9]);
    // Copy constructor.
    explicit Matrix3x3(const Matrix3x3& matrix);
};

template <typename T>
class Matrix4x4 : public SquareMatrix
{
  public:
    // Constructor using individual elements.
    //        row 0        row 1        row 2        row 3
    Matrix4x4(T element0,  T element1,  T element2,  T element3,   // column 0
              T element4,  T element5,  T element6,  T element7,   // column 1
              T element8,  T element9,  T element10, T element11,  // column 2
              T element12, T element13, T element14, T element15); // column 3
    // Constructor using an array of size 16.
    explicit Matrix4x4(T elements[16]);
    // Copy constructor.
    explicit Matrix4x4(const Matrix4x4& matrix);
};


// Functions and operators for matrix-scalar arithmetic.

template <typename T>
Matrix<T> scalarMultiply(const Matrix<T>& matrix, T scalar);
template <typename T>
Matrix<T> scalarMultiply(T scalar, const Matrix<T>& matrix);
template <typename T>
Matrix<T> scalarDivide(const Matrix<T>& matrix, T scalar);

template <typename T>
Matrix<T> operator*(const Matrix<T>& matrix, T scalar);
template <typename T>
Matrix<T> operator*(T scalar, const Matrix<T>& matrix);
template <typenaem T>
Matrix<T> operator/(const Matrix<T>& matrix, T scalar);

#endif