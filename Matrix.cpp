// Matrix.cpp

#include "Matrix.h"

// Matrix function templates.

template <typename T>
Matrix<T>::Matrix(int nRows, int nColumns, const T elements[])
{
  _elements = new T[nRows * nColumns];
  for (int i = 0; i < nRows * nColumns; ++i){
    _elements[i] = elements[i];
  }
  _nRows = nRows;
  _nColumns = nColumns;
}

template <typename T>
explicit Matrix<T>::Matrix(const Matrix& matrix)
{
  
}

template <typename T>
Matrix<T>::~Matrix()
{
  delete[] _elements;
}

template <typename T>
Matrix<T> Matrix<T>::transpose()
{

}

template <typename T>
Matrix<T> Matrix<T>::invert()
{

}

template <typename T>
T* Matrix<T>::getElemtents()
{
  return _elements;
}

template <typename T>
const T* Matrix<T>::getElements() const
{
  return _elements;
}

template <typename T>
Matrix<T>::operator T*()
{
  return _elements;
}

template <typename T>
Matrix<T>::operator const T*() const
{
  return _elements;
}

template <typename T>
T& Matrix<T>::operator [](int index)
{
  return _elements[index];
}

template <typename T>
T Matrix<T>::operator [](int index) const
{
  return _elements[index];
}

