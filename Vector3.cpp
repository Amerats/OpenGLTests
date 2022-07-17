//
// Created by Amerats on 7/5/2022.
//

#include "Vector3.h"
#include <cmath>

Vector3::Vector3() = default;
Vector3::Vector3(float a, float b, float c) {
    x=a;
    y=b;
    z=c;
}

Vector3 &Vector3::operator*=(float s) {
    x*=s;
    y*=s;
    z*=s;
    return (*this);
}

Vector3 &Vector3::operator/=(float s) {
    s=1.0f/s;
    x*=s;
    y*=s;
    z*=s;
    return (*this);
}

Vector3 &Vector3::operator+=(const Vector3 &v) {
    x+=v.x;
    y+=v.y;
    z+=v.z;
    return (*this);
}

Vector3 &Vector3::operator-=(const Vector3 &v) {
    x-=v.x;
    y-=v.y;
    z-=v.z;
    return (*this);
}

//inlines
//scalar multiplication
inline Vector3 operator *(const Vector3& v, float s) {
    return {v.x*s, v.y*s, v.z*s};
}
//scalar division
inline Vector3 operator /(const Vector3& v, float s) {
    return {v.x/s, v.y/s, v.z/s};
}
//vector inverse
inline Vector3 operator -(const Vector3& v) {
    return {-v.x, -v.y, -v.z};
}
//calculate magnitude of vector
inline float Magnitude(const Vector3& v) {
    return std::sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}
//find normal vector
inline Vector3 Normalize(const Vector3 v) {
    return v/ Magnitude(v);
}
//vector addition
inline Vector3 operator +(const Vector3& a, const Vector3& b) {
    return {a.x+b.x,a.y+b.y,a.z+b.z};
}
//vector subtraction
inline Vector3 operator -(const Vector3& a, const Vector3& b) {
    return {a.x-b.x,a.y-b.y,a.z-b.z};
}
//dot product
inline float Dot(const Vector3& a, const Vector3& b) {
    return (a.x*b.x+a.y*b.y+a.z*b.z);
}
//cross product
inline Vector3 Cross(const Vector3& a, const Vector3& b) {
    return {a.y*b.z-a.z*b.y,
            a.z*b.x-a.x*b.z,
            a.x*b.y-a.y*b.x};
}
//vector projection
inline Vector3 Project(const Vector3& a, const Vector3& b) {
    return (b*(Dot(a,b)/Dot(b,b)));
}
//vector rejection
inline Vector3 Reject(const Vector3& a, const Vector3& b) {
    return (a-b*(Dot(a,b)/Dot(b,b)));
}