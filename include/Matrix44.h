#ifndef INCLUDE_Matrix44_H
#define INCLUDE_Matrix44_H

#include <math.h>

#include "Vector3.h"
#include "Vector4.h"

#define DET33(t00, t01, t02, t10, t11, t12, t20, t21, t22) (((t00) * ((t11) * (t22) - (t12) * (t21))) + ((t01) * ((t12) * (t20) - (t10) * (t22))) + ((t02) * ((t10) * (t21) - (t11) * (t20))))


class Vector3;
class Vector4;

class Matrix44
{
    public:
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    protected:
    private:

    public:
        Matrix44();
        Matrix44(const Matrix44 &matrix);
        Matrix44 &operator = (const Matrix44 &matrix);

        virtual ~Matrix44();

        static void add(const Matrix44 &left, const Matrix44 &right, Matrix44 &dest);
        static void sub(const Matrix44 &left, const Matrix44 &right, Matrix44 &dest);
        static void mul(const Matrix44 &left, const Matrix44 &right, Matrix44 &dest);
        static void trans(const Matrix44 &left, const Vector4 &right, Vector4 &dest);

        Matrix44& operator+=(const Matrix44& right);
        Matrix44& operator-=(const Matrix44& right);
        Matrix44& operator*=(const Matrix44& right);
        Matrix44 operator+(const Matrix44& right);
        Matrix44 operator-(const Matrix44& right);
        Matrix44 operator*(const Matrix44& right);
        Vector4 operator*(const Vector4& vec);

        void setIdentity();
        void setZero();
        void transpose();
        void invert();
        void negate();

        void scale(const Vector3 &scale);
        void rotate(const Vector3 &eulerAxis, float angle);
        void translate(const Vector3 &vector);

        float det() const;
                
    protected:
    private:

};



#endif