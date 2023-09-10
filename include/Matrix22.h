#ifndef INCLUDE_MATRIX22_H
#define INCLUDE_MATRIX22_H


#include "Vector2.h"

class Vector2;

class Matrix22
{
    public:
        float m00, m01, m10, m11;
    protected:
    private:

    public:
        Matrix22();
        Matrix22(const Matrix22 &matrix);
        
        virtual ~Matrix22();

        static void add(const Matrix22 &left, const Matrix22 &right, Matrix22 &dest);
        static void sub(const Matrix22 &left, const Matrix22 &right, Matrix22 &dest);
        static void mul(const Matrix22 &left, const Matrix22 &right, Matrix22 &dest);
        //! Part4 - 01:35 Esse metodo retorna Vector2 &
        static void trans(const Matrix22 &left, const Vector2 &right, Vector2 &dest);


        Matrix22 &operator =  (const Matrix22 &matrix);
        Matrix22 &operator += (const Matrix22 &matrix);
        Matrix22 &operator -= (const Matrix22 &matrix);
        Matrix22 &operator *= (const Matrix22 &matrix);
        Matrix22 operator +   (const Matrix22 &matrix);
        Matrix22 operator -   (const Matrix22 &matrix);
        Matrix22 operator *   (const Matrix22 &matrix);
        Vector2 operator *    (const Vector2 &vector);

        void setIdentity();
        void setZero();
        void transpose();
        void invert();
        void negate();

        float det() const;
                
    protected:
    private:

};



#endif