#include "Matrix22.h"

Matrix22::Matrix22()
    : m00(1), m01(0),
      m10(0), m11(1)
{
}

Matrix22::Matrix22(const Matrix22 &matrix)
    : m00(matrix.m00), m01(matrix.m01),
      m10(matrix.m10), m11(matrix.m11)
{
}

Matrix22 &Matrix22::operator=(const Matrix22 &matrix)
{
    // TODO: insert return statement here
    this->m00 = matrix.m00;
    this->m01 = matrix.m01;
    this->m10 = matrix.m10;
    this->m11 = matrix.m11;

    return *this;
}

Matrix22::~Matrix22()
{
}

void Matrix22::add(const Matrix22 &left, const Matrix22 &right, Matrix22 &dest)
{
    dest.m00 = left.m00 + right.m00;
    dest.m01 = left.m01 + right.m01;
    dest.m10 = left.m10 + right.m10;
    dest.m11 = left.m11 + right.m11;
}

void Matrix22::sub(const Matrix22 &left, const Matrix22 &right, Matrix22 &dest)
{
    dest.m00 = left.m00 - right.m00;
    dest.m01 = left.m01 - right.m01;
    dest.m10 = left.m10 - right.m10;
    dest.m11 = left.m11 - right.m11;
}

void Matrix22::mul(const Matrix22 &left, const Matrix22 &right, Matrix22 &dest)
{
    float m00 = left.m00 * right.m00 + left.m10 * right.m01;
    float m01 = left.m01 * right.m00 + left.m11 * right.m01;
    float m10 = left.m00 * right.m10 + left.m10 * right.m11;
    float m11 = left.m01 * right.m10 + left.m11 * right.m11;

    dest.m00 = m00;
    dest.m01 = m01;
    dest.m10 = m10;
    dest.m11 = m11;
}

void Matrix22::trans(const Matrix22 &left, const Vector2 &right, Vector2 &dest)
{
    float x = left.m00 * right.x + left.m10 * right.y;
    float y = left.m01 * right.x + left.m11 * right.y;

    dest.x = x;
    dest.y = y;
}

Matrix22& Matrix22::operator+=(const Matrix22& right){
    Matrix22::add(*this, right, *this);
    return *this;
}

Matrix22& Matrix22::operator-=(const Matrix22& right){
    Matrix22::sub(*this, right, *this);
    return *this;
}

Matrix22& Matrix22::operator*=(const Matrix22& right){
    Matrix22::mul(*this, right, *this);
    return *this;
}

Matrix22 Matrix22::operator+(const Matrix22& right){
    Matrix22 ret;
    Matrix22::add(*this, right, ret);
    return ret;
}

Matrix22 Matrix22::operator-(const Matrix22& right){
    Matrix22 ret;
    Matrix22::sub(*this, right, ret);
    return ret;
}

Matrix22 Matrix22::operator*(const Matrix22& right){
    Matrix22 ret;
    Matrix22::mul(*this, right, ret);
    return ret;
}

Vector2 Matrix22::operator*(const Vector2& vec){
    Vector2 ret;
    Matrix22::trans(*this, vec, ret);
    return ret;
}

void Matrix22::setIdentity()
{
    this->m00 = 1;
    this->m01 = 1;
    this->m10 = 0;
    this->m11 = 0;    
}

void Matrix22::setZero()
{
    this->m00 = 0;
    this->m01 = 0;
    this->m10 = 0;
    this->m11 = 0;
}

void Matrix22::transpose()
{
    float temp = this->m01;
    this->m01 = this->m10;
    this->m10 = temp;
}

void Matrix22::invert()
{
    float determinant = this->det();
    
    if (determinant != 0)
    {
        float determinant_inv = 1/(float) determinant;
        float t00 = this->m11 * determinant_inv;
        float t01 = this->m01 * determinant_inv;
        float t10 = this->m10 * determinant_inv;
        float t11 = this->m00 * determinant_inv;

        this->m00 = t00;
        this->m01 = t01;
        this->m10 = t10;
        this->m11 = t11;

    }
}

void Matrix22::negate()
{
    this->m00 = - this->m00;
    this->m01 = - this->m01;
    this->m10 = - this->m10;
    this->m11 = - this->m11;
}

float Matrix22::det() const
{
    return this->m00 * this->m11 - this->m01 * this->m10;
}
