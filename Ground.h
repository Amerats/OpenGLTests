//
// Created by Amerats on 7/4/2022.
//

#ifndef OPENGLTESTS_GROUND_H
#define OPENGLTESTS_GROUND_H
#include "Vector3.h"


class Ground {

public:

    //member variables
    Vector3 pos; //position of corner
    Vector3 norm; //vector normal to the plane
    float w{},l{}; //w-size in the x direction; l-size in the z direction

    //constructors
    Ground(); //default constructor
    Ground(Vector3& position, Vector3& normal, float width, float length); //crates a ground plane with position with a normal

    //render function
    void render() const;

};


#endif //OPENGLTESTS_GROUND_H
