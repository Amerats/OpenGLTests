//
// Created by Amerats on 7/5/2022.
//

#ifndef OPENGLTESTS_VECTOR3_H
#define OPENGLTESTS_VECTOR3_H


struct Vector3 {

public:

    //member variables
    float x{}, y{}, z{};

    //constructors
    Vector3(); //default constructor
    Vector3(float x, float y, float z); //full constructor

    //operator overloads
    Vector3& operator *=(float s); //scalar multiplication
    Vector3& operator /=(float s); //scalar division
    Vector3& operator +=(const Vector3& v); //vector addition
    Vector3& operator -=(const Vector3& v); //vector subtraction

};


#endif //OPENGLTESTS_VECTOR3_H
