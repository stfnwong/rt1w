/*
 * CAMERA
 * A simple camera object
 *
 * Stefan Wong 2019
 */

#ifndef __RT_CAMERA_HPP
#define __RT_CAMERA_HPP

#include "ray.hpp"


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

    public:
        camera(float vfov, float aspect);
        ray get_ray(float u, float v);
};


#endif /*__RT_CAMERA_HPP*/
