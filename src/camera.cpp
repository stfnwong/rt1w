/*
 * CAMERA
 * A simple camera object
 *
 * Stefan Wong 2019
 */

#include "camera.hpp"


camera::camera()
{
    this->origin = vec3(0.0, 0.0, 0.0);
    this->lower_left_corner = vec3(-2.0, -1.0, -1.0);
    this->horizontal = vec3(4.0, 0.0, 0.0);
    this->vertical = vec3(0.0, 2.0, 0.0);
}

ray camera::get_ray(float u, float v)
{
    return ray(
            this->origin,
            this->lower_left_corner + 
            u * this->horizontal +
            v * this->vertical -
            this->origin
    );
}

