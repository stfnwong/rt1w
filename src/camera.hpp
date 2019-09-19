/*
 * CAMERA
 * A simple camera object
 *
 * Stefan Wong 2019
 */

#ifndef __RT_CAMERA_HPP
#define __RT_CAMERA_HPP

#include "ray.hpp"

vec3 random_in_unit_disk(void);

/*
 * Camera
 */
class camera
{
    public:
        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 u;
        vec3 v;
        vec3 w;
        
        // lens stuff
        float lens_radius;

    public:
        camera(vec3 lookfrom, vec3 lookat, vec3 vup, float vfov, float aspect, float aperture, float focus_dist);
        ray get_ray(float u, float v);
};


#endif /*__RT_CAMERA_HPP*/
