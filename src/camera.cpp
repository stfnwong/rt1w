/*
 * CAMERA
 * A simple camera object
 *
 * Stefan Wong 2019
 */

#include <cmath>
#include "camera.hpp"


camera::camera(float vfov, float aspect)
{
    float theta;
    float half_height;
    float half_width;

    theta = vfov * M_PI / 180;
    half_height = tan(theta / 2);
    half_width  = aspect * half_height;

    this->origin = vec3(0.0, 0.0, 0.0);
    this->lower_left_corner = vec3(-half_width, -half_height, -1.0);
    this->horizontal = vec3(2.0 * half_width, 0.0, 0.0);
    this->vertical = vec3(0.0, 2.0 * half_height, 0.0);
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

