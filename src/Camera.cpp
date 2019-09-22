/*
 * CAMERA
 * A simple Camera object
 *
 * Stefan Wong 2019
 */

#include <cmath>
#include "Camera.hpp"

vec3 random_in_unit_disk(void)
{
    vec3 p;
    
    do
    {
        p = 2.0 * vec3(drand48(), drand48(), 0.0) - vec3(1,1,0);
    }while (dot(p,p) >= 1.0);

    return p;
}

/*
 * Camera ctor
 */
Camera::Camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist)
{
    float theta;
    float half_height;
    float half_width;

    theta = vfov * M_PI / 180;
    half_height = tan(theta / 2);
    half_width  = aspect * half_height;

    this->lens_radius = aperture / 2;

    this->w = unit_vector(lookfrom - lookat);
    this->u = unit_vector(cross(vup, this->w));
    this->v = cross(this->w, this->u);

    this->lower_left_corner = 
        this->origin - 
        half_width * focus_dist * this->u - 
        half_height * focus_dist * this->v - 
        focus_dist * this->w;
    this->horizontal = 2 * half_width * focus_dist * this->u;
    this->vertical   = 2 * half_height * focus_dist * this->v;
    this->origin     = lookfrom;
}

Ray Camera::get_ray(float u, float v)
{
    vec3 rd;
    vec3 offset;

    rd = this->lens_radius * random_in_unit_disk();
    offset = this->u * rd.x() + this->v * rd.y();

    return Ray(
            this->origin + offset,
            this->lower_left_corner + 
            u * this->horizontal +
            v * this->vertical -
            this->origin -
            offset
    );
}

