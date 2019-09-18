/*
 * CAMERA
 * A simple camera object
 *
 * Stefan Wong 2019
 */

#include <cmath>
#include "camera.hpp"


camera::camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect)
{
    vec3 u, v, w;
    float theta;
    float half_height;
    float half_width;

    theta = vfov * M_PI / 180;
    half_height = tan(theta / 2);
    half_width  = aspect * half_height;

    w = unit_vector(lookfrom - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    this->lower_left_corner = vec3(-half_width, -half_height, -1.0);
    this->lower_left_corner = 
        this->origin - 
        half_width * u - 
        half_height * v - 
        w;
    this->horizontal = 2 * half_width * u;
    this->vertical   = 2 * half_height * v;
    this->origin     = lookfrom;
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

