/*
 * HITTABLE
 * Defined things that a Ray can intersect.
 *
 * Stefan Wong 2019
 */

#ifndef __RT_HITTABLE_HPP
#define __RT_HITTABLE_HPP

#include "Ray.hpp"

// forward-declare the material class
class Material;


struct hit_record
{
    float t;
    vec3 p;
    vec3 normal;
    Material* mat;
};


// Base class for all Hittable objects
class Hittable
{
    public:
        virtual ~Hittable() {} 
        // check if a Ray between t_mix < t < t_max hit something
        virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};


#endif /*__RT_HITTABLE_HPP*/
