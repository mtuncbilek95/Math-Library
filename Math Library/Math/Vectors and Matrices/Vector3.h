// Copyright Metehan Tuncbilek, All Rights Reserved.

/*****************************************************************************************************
 *
 *  This is a standart 3 Dimensional Vector library which is created to use for mathematical, geometric calculations.
 *
 *  Current capabilities:
 *  -   All the operator functions including bool check which is defined as ==.
 *  -   Initialization without defining the elements. (Returns Zero Vector)
 *  -   Length, Normalize, Distance, DotProduct, CrossProduct.
 *  -   Num. (Returns the count of element which is 3 for Vector3)
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


#ifndef VECTOR3_H
#define VECTOR3_H

namespace Math
{

template <typename T = float>
class Vector3D
{
public:
    //	If it is not initialized, it is zero vector.
    Vector3D();

    //	Initialization constructor.
    Vector3D(T Tx, T Ty, T Tz);
    
    float X;
    float Y;
    float Z;
    
    //	Gives the distance from origin.
    float Length();

    //	Rates the current vector's each element in between 0 and 1.
    Vector3D Normalize();

    //	Gives the distance of 2 vector points.
    static float Distance(Vector3D& Vec1, Vector3D& Vec2);

    //	Scalar multiplication method called Dot Product. Returns float.
    static float DotProduct(Vector3D& Vec1, Vector3D& Vec2);

    //	2 Dimensional CrossProduct returns normal vector of given two vectors.
    static Vector3D CrossProduct(Vector3D& Vec1, Vector3D& Vec2);

    //	Gives the size of the Vector3 which is always equals 3.
    static constexpr unsigned Num();

    //	Vector3 + Vector3. Each element sums with the other vector's related element.
    Vector3D operator+(Vector3D& Other) const;

    //	Vector3 + float. Add each element the float parameter.
    Vector3D operator+(T& Other) const;

    //	Vector3 * float. Multiplies each element with the float parameter.
    Vector3D operator*(T& Other) const;

    //	Vector3 * float. Divides each element with the float parameter.
    Vector3D operator/(T& Other) const;

    //	Vector3 + Vector3. Each element sums with the other vector's related element and overwrites on related Vector2.
    Vector3D operator+=(Vector3D Other);

    //	Vector3 + float. Each element sums with the other vector's related element and overwrites on related Vector2.
    Vector3D operator+=(T Other);

    //	Vector3 - Vector3. Each element sums with the other vector's related element and overwrites on related Vector2.
    Vector3D operator-=(Vector3D Other);

    //	Vector3 - float. Each element subtract with the other vector's related element and overwrites on related Vector2.
    Vector3D operator-=(T Other);

    //	Vector3 * float. Each element multiplies with the other vector's related element and overwrites on related Vector2.
    Vector3D operator*=(T Other);

    //	Vector3 / float. Each element multiplies with the other vector's related element and overwrites on related Vector2.
    Vector3D operator/=(T Other);

    //	Boolean that checks if both 3 dimensional Vector
    bool operator==(Vector3D Other);
};

template <typename T>
constexpr unsigned Vector3D<T>::Num()
{
    return 3;
}

template <typename T>
Vector3D<T>::Vector3D()
{
    X = 0;
    Y = 0;
    Z = 0;
}

template <typename T>
Vector3D<T>::Vector3D(T Tx, T Ty, T Tz)
{
    X = (float)Tx;
    Y = (float)Ty;
    Z = (float)Tz;
}

template <typename T>
float Vector3D<T>::Length()
{
    return sqrt(pow(X, 2) + pow(Y, 2) + pow(Z, 2));
}

template <typename T>
Vector3D<T> Vector3D<T>::Normalize()
{
    return Vector3D(X / Length(), Y / Length(), Z / Length());
}

template <typename T>
float Vector3D<T>::Distance(Vector3D& Vec1, Vector3D& Vec2)
{
    return sqrt(pow((Vec2.X - Vec1.X), 2) + pow((Vec2.Y - Vec1.Y), 2) + pow((Vec2.Z - Vec1.Z), 2));
}

template <typename T>
float Vector3D<T>::DotProduct(Vector3D& Vec1, Vector3D& Vec2)
{
    return Vec1.X * Vec2.X + Vec1.Y * Vec2.Y + Vec1.Z * Vec1.Z;
}

template <typename T>
Vector3D<T> Vector3D<T>::CrossProduct(Vector3D& Vec1, Vector3D& Vec2)
{
    return Vector3D((Vec1.Y * Vec2.Z - Vec1.Z * Vec2.Y), (Vec1.X * Vec2.Z - Vec1.Z * Vec2.X),
                    (Vec1.X * Vec2.Y - Vec1.Y * Vec2.X));
}

template <typename T>
Vector3D<T> Vector3D<T>::operator+(Vector3D& Other) const
{
    return Vector3D((X + Other.X), (Y + Other.Y), (Z + Other.Z));
}

template <typename T>
Vector3D<T> Vector3D<T>::operator+(T& Other) const
{
    return Vector3D((X + Other), (Y + Other), (Z + Other));
}

template <typename T>
Vector3D<T> Vector3D<T>::operator*(T& Other) const
{
    return Vector3D((X * Other), (Y * Other), (Z + Other));
}

template <typename T>
Vector3D<T> Vector3D<T>::operator/(T& Other) const
{
    return Vector3D((X / Other), (Y / Other), (Z + Other));
}

template <typename T>
Vector3D<T> Vector3D<T>::operator+=(Vector3D Other)
{
    X += Other.X;
    Y += Other.Y;
    Z += Other.Z;
    return Vector3D(X, Y, Z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator+=(T Other)
{
    X += Other;
    Y += Other;
    Z += Other;
    return Vector3D(X, Y, Z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator-=(Vector3D Other)
{
    X -= Other.X;
    Y -= Other.Y;
    Z -= Other.Z;
    return Vector3D(X, Y, Z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator-=(T Other)
{
    X -= Other;
    Y -= Other;
    Z -= Other;
    return Vector3D(X, Y, Z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator*=(T Other)
{
    X *= Other;
    Y *= Other;
    Z *= Other;
    return Vector3D(X, Y, Z);
}

template <typename T>
Vector3D<T> Vector3D<T>::operator/=(T Other)
{
    X /= Other;
    Y /= Other;
    Z /= Other;
    return Vector3D(X, Y, Z);
}

template <typename T>
bool Vector3D<T>::operator==(Vector3D Other)
{
    return Other.X == X && Other.Y == Y && Other.Z ? true : false;
}
    
typedef Vector3D<> Vector3;
    
}
#endif // ! VECTOR3_H
