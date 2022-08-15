// Copyright Metehan Tuncbilek, All Rights Reserved.

/*****************************************************************************************************
 *
 *  This is a standart 2 Dimensional Vector library which is created to use for mathematical, geometric calculations.
 *
 *  Current capabilities:
 *  -   All the operator functions including bool check which is defined as ==.
 *  -   Initialization without defining the elements. (Returns Zero Vector)
 *  -   Length, Normalize, Distance, DotProduct, CrossProduct.
 *  -   Num. (Returns the count of element which is 2 for Vector2)
 *
 *  W.I.P Features:
 *  -   Vector4
 *  -   More Mathematical calculations.
 *  
 *****************************************************************************************************/

#ifndef MATH_H
#define MATH_H

#include <cmath>

#endif  //  ! MATH_H

#ifndef VECTOR2_H
#define VECTOR2_H

namespace MathLib
{
    template <typename T = float>
    class Vector2D
    {
    public:
        //	If it is not initialized, it is zero vector.
        Vector2D();
        //	Initialization constructor.
        Vector2D(T Tx, T Ty);

        float X;
        float Y;

        //	Gives the distance from origin.
        float Length();

        //	Rates the current vector's each element in between 0 and 1.
        Vector2D Normalize();

        //	Gives the distance of 2 vector points.
        static float Distance(Vector2D& Vec1, Vector2D& Vec2);

        //	Scalar multiplication method called Dot Product. Returns float.
        static float DotProduct(Vector2D& Vec1, Vector2D& Vec2);

        //	2 Dimensional CrossProduct returns the Z value.
        static float CrossProduct(Vector2D& Vec1, Vector2D& Vec2);

        //	Gives the size of the Vector2 which is always equals 2.
        static constexpr unsigned Num();

        //	Vector2 + Vector2. Each element sums with the other vector's related element and creates whole new Vector2.
        Vector2D operator+(Vector2D Other) const;

        //	Vector2 + float. Add each element the float parameter.
        Vector2D operator+(T Other) const;

        //	Vector2 * float. Multiplies each element with the float parameter.
        Vector2D operator*(T Other) const;

        //	Vector2 * float. Divides each element with the float parameter.
        Vector2D operator/(T Other) const;

        //	Vector2 + Vector2. Each element sums with the other vector's related element and overwrites on related Vector2.
        Vector2D operator+=(Vector2D Other);

        //	Vector + float. Each element sums with the other vector's related element and overwrites on related Vector2.
        Vector2D operator +=(T Other);

        //	Vector2 - Vector2. Each element sums with the other vector's related element and overwrites on related Vector2.
        Vector2D operator-=(Vector2D Other);

        //	Vector - float. Each element subtract with the other vector's related element and overwrites on related Vector2.
        Vector2D operator -=(T Other);

        //	Vector + float. Each element multiplies with the other vector's related element and overwrites on related Vector2.
        Vector2D operator *=(T Other);

        //	Vector / float. Each element multiplies with the other vector's related element and overwrites on related Vector2.
        Vector2D operator /=(T Other);

        //	Boolean that checks if both 2 dimensional Vector
        bool operator ==(Vector2D Other);
    };

    template <typename T>
    constexpr unsigned Vector2D<T>::Num()
    {
        return 2;
    }

    template <typename T>
    Vector2D<T>::Vector2D()
    {
        X = 0;
        Y = 0;
    }

    template <typename T>
    Vector2D<T>::Vector2D(T Tx, T Ty)
    {
        X = (float)Tx;
        Y = (float)Ty;
    }

    template <typename T>
    float Vector2D<T>::Length()
    {
        return sqrt(pow(X, 2) + pow(Y, 2));
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::Normalize()
    {
        return Vector2D(X / Length(), Y / Length());
    }

    template <typename T>
    float Vector2D<T>::Distance(Vector2D& Vec1, Vector2D& Vec2)
    {
        return sqrt(pow((Vec2.X - Vec1.X), 2) + pow((Vec2.Y - Vec1.Y), 2));
    }

    template <typename T>
    float Vector2D<T>::DotProduct(Vector2D& Vec1, Vector2D& Vec2)
    {
        return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y;
    }

    template <typename T>
    float Vector2D<T>::CrossProduct(Vector2D& Vec1, Vector2D& Vec2)
    {
        return Vec1.X * Vec2.Y - Vec1.Y * Vec2.X;
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator+(Vector2D Other) const
    {
        return Vector2D((X + Other.X), (Y + Other.Y));
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator+(T Other) const
    {
        return Vector2D((X + Other), (Y + Other));
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator*(T Other) const
    {
        return Vector2D((X * Other), (Y * Other));
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator/(T Other) const
    {
        return Vector2D((X / Other), (Y / Other));
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator+=(Vector2D Other)
    {
        X += Other.X;
        Y += Other.Y;
        return Vector2D(X, Y);
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator+=(T Other)
    {
        X += Other;
        Y += Other;
        return Vector2D(X, Y);
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator-=(Vector2D Other)
    {
        X -= Other.X;
        Y -= Other.Y;
        return Vector2D(X, Y);
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator-=(T Other)
    {
        X -= Other;
        Y -= Other;
        return Vector2D(X, Y);
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator*=(T Other)
    {
        X *= Other;
        Y *= Other;
        return Vector2D(X, Y);
    }

    template <typename T>
    Vector2D<T> Vector2D<T>::operator/=(T Other)
    {
        X /= Other;
        Y /= Other;
        return Vector2D(X, Y);
    }

    template <typename T>
    bool Vector2D<T>::operator==(Vector2D Other)
    {
        return Other.X == X && Other.Y == Y ? true : false;
    }
}

typedef MathLib::Vector2D<> Vector2;

#endif  //  ! VVECTOR2_H