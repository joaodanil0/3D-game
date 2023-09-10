#include "Vector2.h"

Vector2::Vector2(float x, float y)
    : x(x), y(y)
{
}

Vector2::Vector2(const Vector2 &vect)
    :x(vect.x), y(vect.y)
{
}

Vector2::~Vector2()
{
}

float Vector2::length() const
{
    return sqrt(
                (this->x * this->x) + 
                (this->y * this->y)
            );
}

void Vector2::add(const Vector2 &left, const Vector2 &right, Vector2 &dest)
{
    dest.x = left.x + right.x;
    dest.y = left.y + right.y;
}

void Vector2::sub(const Vector2 &left, const Vector2 &right, Vector2 &dest)
{
    dest.x = left.x - right.x;
    dest.y = left.y - right.y;
}

void Vector2::mul(const Vector2 &left, const Vector2 &right, Vector2 &dest)
{
    dest.x = left.x * right.x;
    dest.y = left.y * right.y;
}

void Vector2::lerp(const Vector2 &a, const Vector2 &b, float t, Vector2 &dest)
{
    dest.x = a.x + ( (b.x - a.x) * t);
    dest.y = a.y + ( (b.y - a.y) * t);
}

Vector2 &Vector2::operator=(const Vector2 &vect)
{
    this->x = vect.x;
    this->y = vect.y;
    return *this;
}

Vector2& Vector2::operator+=(const Vector2& right){
    Vector2::add(*this, right, *this);
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& right){
    Vector2::sub(*this, right, *this);
    return *this;
}

Vector2 Vector2::operator+(const Vector2& right){
    Vector2 ret;
    Vector2::add(*this, right, ret);
    return ret;
}

Vector2 Vector2::operator-(const Vector2& right){
    Vector2 ret;
    Vector2::sub(*this, right, ret);
    return ret;
}

float Vector2::operator*(const Vector2& b){
    return Vector2::dot(*this, b);
}


float Vector2::dot(const Vector2 &a, const Vector2 &b)
{
    return ( (a.x * b.x) + (a.y * b.y));
}

float Vector2::dist(const Vector2 &a, const Vector2 &b)
{   
    float x = a.x - b.x;
    float y = a.y - b.y;

    return sqrt( (x * x) +  (y * y)); 
}

float Vector2::angle(const Vector2 &a, const Vector2 &b)
{   
    float dot = Vector2::dot(a, b);
    return acos(dot/(a.length() * b.length()));
}

Vector2 Vector2::getNormalized(const Vector2 &vect)
{
    Vector2 ret(vect);

    ret.normalize();

    return ret;
}

void Vector2::scale(float s)
{
    this->x *= s;
    this->y *= s;
}

void Vector2::normalize()
{
    float mag = length();

    this->x /= mag;
    this->y /= mag;
}
