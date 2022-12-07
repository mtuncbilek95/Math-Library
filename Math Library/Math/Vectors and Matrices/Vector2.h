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

#pragma once

#include <cmath>

namespace MathLib
{
    template <typename typeValue>
    class Vector2d
    {
    public:
        //	If it is not initialized, it is zero vector.
        Vector2d();
        //	Initialization constructor.
        Vector2d(typeValue Tx, typeValue Ty);

        typeValue X;
        typeValue Y;

        //	Gives the distance from origin.
        float length();

        //	Rates the current vector's each element in between 0 and 1.
        Vector2d normalize();

        //	Gives the distance of 2 vector points.
        static float distance(Vector2d& Vec1, Vector2d& Vec2);

        //	Scalar multiplication method called Dot Product. Returns float.
        static float dot_product(Vector2d& Vec1, Vector2d& Vec2);

        //	2 Dimensional cross_product returns the Z value.
        static float cross_product(Vector2d& Vec1, Vector2d& Vec2);

        //	Gives the size of the Vector2 which is always equals 2.
        constexpr unsigned size();

        //	Vector2 + Vector2. Each element sums with the other vector's related element and creates whole new Vector2.
        Vector2d operator+(Vector2d Other) const;

        //	Vector2 + float. Add each element the float parameter.
        Vector2d operator+(typeValue Other) const;

        //	Vector2 * float. Multiplies each element with the float parameter.
        Vector2d operator*(typeValue Other) const;

        //	Vector2 * float. Divides each element with the float parameter.
        Vector2d operator/(typeValue Other) const;

        //	Vector2 + Vector2. Each element sums with the other vector's related element and overwrites on related Vector2.
        Vector2d operator+=(Vector2d Other);

        //	Vector + float. Each element sums with the other vector's related element and overwrites on related Vector2.
        Vector2d operator +=(typeValue Other);

        //	Vector2 - Vector2. Each element sums with the other vector's related element and overwrites on related Vector2.
        Vector2d operator-=(Vector2d Other);

        //	Vector - float. Each element subtract with the other vector's related element and overwrites on related Vector2.
        Vector2d operator -=(typeValue Other);

        //	Vector + float. Each element multiplies with the other vector's related element and overwrites on related Vector2.
        Vector2d operator *=(typeValue Other);

        //	Vector / float. Each element multiplies with the other vector's related element and overwrites on related Vector2.
        Vector2d operator /=(typeValue Other);

        //	Boolean that checks if both 2 dimensional Vector
        bool operator ==(Vector2d Other);
    };

    template <typename typeValue>
    constexpr unsigned Vector2d<typeValue>::size()
    {
        return 2;
    }

    template <typename typeValue>
    Vector2d<typeValue>::Vector2d()
    {
        X = 0;
        Y = 0;
    }

    template <typename typeValue>
    Vector2d<typeValue>::Vector2d(typeValue Tx, typeValue Ty)
    {
        X = (float)Tx;
        Y = (float)Ty;
    }

    template <typename typeValue>
    float Vector2d<typeValue>::length()
    {
        return sqrt(pow(X, 2) + pow(Y, 2));
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::normalize()
    {
        return Vector2d(X / length(), Y / length());
    }

    template <typename typeValue>
    float Vector2d<typeValue>::distance(Vector2d& Vec1, Vector2d& Vec2)
    {
        return sqrt(pow((Vec2.X - Vec1.X), 2) + pow((Vec2.Y - Vec1.Y), 2));
    }

    template <typename typeValue>
    float Vector2d<typeValue>::dot_product(Vector2d& Vec1, Vector2d& Vec2)
    {
        return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y;
    }

    template <typename typeValue>
    float Vector2d<typeValue>::cross_product(Vector2d& Vec1, Vector2d& Vec2)
    {
        return Vec1.X * Vec2.Y - Vec1.Y * Vec2.X;
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator+(Vector2d Other) const
    {
        return Vector2d((X + Other.X), (Y + Other.Y));
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator+(typeValue Other) const
    {
        return Vector2d((X + Other), (Y + Other));
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator*(typeValue Other) const
    {
        return Vector2d((X * Other), (Y * Other));
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator/(typeValue Other) const
    {
        return Vector2d((X / Other), (Y / Other));
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator+=(Vector2d Other)
    {
        X += Other.X;
        Y += Other.Y;
        return Vector2d(X, Y);
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator+=(typeValue Other)
    {
        X += Other;
        Y += Other;
        return Vector2d(X, Y);
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator-=(Vector2d Other)
    {
        X -= Other.X;
        Y -= Other.Y;
        return Vector2d(X, Y);
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator-=(typeValue Other)
    {
        X -= Other;
        Y -= Other;
        return Vector2d(X, Y);
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator*=(typeValue Other)
    {
        X *= Other;
        Y *= Other;
        return Vector2d(X, Y);
    }

    template <typename typeValue>
    Vector2d<typeValue> Vector2d<typeValue>::operator/=(typeValue Other)
    {
        X /= Other;
        Y /= Other;
        return Vector2d(X, Y);
    }

    template <typename typeValue>
    bool Vector2d<typeValue>::operator==(Vector2d Other)
    {
        return Other.X == X && Other.Y == Y ? true : false;
    }
}