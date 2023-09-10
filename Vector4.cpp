#include "Vector4.h"

Vector4::Vector4(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
{
}

Vector4::Vector4(const Vector4 &vect)
    :x(vect.x), y(vect.y), z(vect.z), w(vect.w)
{
}

Vector4 &Vector4::operator=(const Vector4 &vect)
{
    // TODO: insert return statement here
    this->x = vect.x;
    this->y = vect.y;
    this->z = vect.z;
    this->w = vect.w;
    return *this;
}

Vector4::~Vector4()
{
}

float Vector4::length() const
{
    return sqrt(
                (this->x * this->x) + 
                (this->y * this->y) +
                (this->z * this->z) +
                (this->w * this->w)
            );
}

void Vector4::add(const Vector4 &left, const Vector4 &right, Vector4 &dest)
{
    dest.x = left.x + right.x;
    dest.y = left.y + right.y;
    dest.z = left.z + right.z;
    dest.w = left.w + right.w;
}

void Vector4::sub(const Vector4 &left, const Vector4 &right, Vector4 &dest)
{
    dest.x = left.x - right.x;
    dest.y = left.y - right.y;
    dest.z = left.z - right.z;
    dest.w = left.w - right.w;
}

void Vector4::mul(const Vector4 &left, const Vector4 &right, Vector4 &dest)
{
    dest.x = left.x * right.x;
    dest.y = left.y * right.y;
    dest.z = left.z * right.z;
    dest.w = left.w * right.w;
}

float Vector4::dot(const Vector4 &a, const Vector4 &b)
{
    return ( (a.x * b.x) + (a.y * b.y) + (a.z * b.z)  + (a.w * b.w) );
}

float Vector4::dist(const Vector4 &a, const Vector4 &b)
{   
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;
    float w = a.w - b.w;

    return sqrt( (x * x) + (y * y) + (z * z) + (w * w) ); 
}

Vector4 Vector4::getNormalized(const Vector4 &vect)
{
    Vector4 ret(vect);

    ret.normalize();

    return ret;
}

void Vector4::scale(float s)
{
    this->x *= s;
    this->y *= s;
    this->z *= s;
    this->w *= s;
}

void Vector4::normalize()
{
    float mag = length();

    this->x /= mag;
    this->y /= mag;
    this->z /= mag;
    this->w /= mag;
}
