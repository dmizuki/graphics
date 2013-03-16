// Vector.h

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdarg>

#include "Matrix.h"

class Vector : public Matrix
{
  public:
    Vector(int dimention, const float elements[])
    : Matrix(dimention, 1, elements);
    // Constructor using an array of size dimention.
    Vector(const Vector& vector)
    : Matrix(vector);
    // Copy constructor.
    ~Vector();
    float length();
  private:
    int _dimention;
};

class Vector2D : public Vector
{
  public:
    Vector2D(float x, float y)
    : Vector(2, x, y);
};

class Vector3D : public Vector
{
  public:
    Vector3D(float x, float y, float z)
    : Vector(3, x, y, z);
};

class Vector4D : public Vector
{
  public:
    Vector4D(float x, float y, float z, float w)
    : Vector(4, x, y, z, w);
};

float dotProduct(const Vector& vector1, const Vector& vector2);
float crossProduct(const Vector& vector1, const Vector& vector2);
Vector& negation(const Vector& vector);

Vector& operator-(const Vector& vector);

#endif