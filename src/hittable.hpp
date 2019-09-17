/*
 * HITTABLE
 * Defined things that a ray can intersect.
 *
 * Stefan Wong 2019
 */

#ifndef __RT_HITTABLE_HPP
#define __RT_HITTABLE_HPP

#include "ray.hpp"


class material;


struct hit_record
{
    float t;
    vec3 p;
    vec3 normal;
    material* mat;
};


// Base class for all hittable objects
class hittable
{
    public:
        // check if a ray between t_mix < t < t_max hit something
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};


#endif /*__RT_HITTABLE_HPP*/
