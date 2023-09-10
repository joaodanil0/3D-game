#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

Vector3::Vector3(const Vector3 &vect)
    :x(vect.x), y(vect.y), z(vect.z)
{
}

Vector3 &Vector3::operator=(const Vector3 &vect)
{
    // TODO: insert return statement here
    this->x = vect.x;
    this->y = vect.y;
    this->z = vect.z;
    return *this;
}

Vector3::~Vector3()
{
}

float Vector3::length() const
{
    return sqrt(
                (this->x * this->x) + 
                (this->y * this->y) +
                (this->z * this->z)
            );
}

void Vector3::add(const Vector3 &left, const Vector3 &right, Vector3 &dest)
{
    dest.x = left.x + right.x;
    dest.y = left.y + right.y;
    dest.z = left.z + right.z;
}

void Vector3::sub(const Vector3 &left, const Vector3 &right, Vector3 &dest)
{
    dest.x = left.x - right.x;
    dest.y = left.y - right.y;
    dest.z = left.z - right.z;
}

void Vector3::mul(const Vector3 &left, const Vector3 &right, Vector3 &dest)
{
    dest.x = left.x * right.x;
    dest.y = left.y * right.y;
    dest.z = left.z * right.z;
}

void Vector3::cross(const Vector3 &one, const Vector3 &two, Vector3 &dest)
{
    dest.x = (one.y * two.z) - (one.z * two.y);
    dest.y = (one.z * two.x) - (one.x * two.z);
    dest.z = (one.x * two.y) - (one.y * two.x);
}

float Vector3::dot(const Vector3 &a, const Vector3 &b)
{
    return ( (a.x * b.x) + (a.y * b.y) + (a.z * b.z) );
}

float Vector3::dist(const Vector3 &a, const Vector3 &b)
{   
    float x = a.x - b.x;
    float y = a.y - b.y;
    float z = a.z - b.z;

    return sqrt( (x * x) + (y * y) + (z * z) ); 
}

float Vector3::angle(const Vector3 &a, const Vector3 &b)
{   
    float dot = Vector3::dot(a, b);
    return acos(dot/(a.length() * b.length()));
}

Vector3 Vector3::getNormalized(const Vector3 &vect)
{
    Vector3 ret(vect);

    ret.normalize();

    return ret;
}

void Vector3::scale(float s)
{
    this->x *= s;
    this->y *= s;
    this->z *= s;
}

void Vector3::normalize()
{
    float mag = length();

    this->x /= mag;
    this->y /= mag;
    this->z /= mag;
}
