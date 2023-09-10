#ifndef INCLUDE_Vector4_H
#define INCLUDE_Vector4_H

#include <math.h>

class Vector4
{
    public:
        float x, y, z, w;
    protected:
    private:

    public:
        Vector4(float x = 0, float y = 0, float z = 0, float w = 0);
        Vector4(const Vector4 &vect);
        Vector4 &operator = (const Vector4 &vect);
        virtual ~Vector4();

        float length() const;

        static void add(const Vector4 &left, const Vector4 &right, Vector4 &dest);
        static void sub(const Vector4 &left, const Vector4 &right, Vector4 &dest);
        static void mul(const Vector4 &left, const Vector4 &right, Vector4 &dest);

        static float dot(const Vector4 &a, const Vector4 &b);
        static float dist(const Vector4 &a, const Vector4 &b);
        static Vector4 getNormalized(const Vector4 &vect);

        void scale(float s);
        void normalize();

    protected:
    private:
};

#endif