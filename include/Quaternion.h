#ifndef INCLUDE_QUATERNION_H
#define INCLUDE_QUATERNION_H

#include "defs.h"

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix44.h"

#include <math.h>

class Vector2;
class Vector3;
class Vector4;
class Matrix44;

class Quaternion
{
    public:
        float x, y, z, w;
    protected:
    private:

    public:
        Quaternion(float x = 0, float y = 0, float z = 0, float w = 0);
        Quaternion(const Vector3 &axis, float angle);
        Quaternion(const Quaternion &q);

        Quaternion& setIdentity();
        float length() const; 
        Quaternion& normalize();
        Quaternion& negate();

        Quaternion operator*(const Quaternion& right);
        Quaternion& operator*=(const Quaternion& right);
        Vector3 operator*(const Vector3& right);
        Vector4 operator*(const Vector4& right); 

        Matrix44 toMatrix() const;
        Quaternion& setToAxisAngle(const Vector3& axis, float angle);
        static Quaternion slerp(const Quaternion& a, const Quaternion& b, float blend);
        Quaternion& lookRotation(const Vector3& forward, const Vector3& up);
        Quaternion& setMatrix(const Matrix44& matrix);

    protected:
    private:

};



#endif