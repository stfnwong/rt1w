/*
 * SPHERE
 * Definition of a sphere in terms of a hittable
 *
 * Stefan Wong 2019
 */

#ifndef __RT_SPHERE_HPP
#define __RT_SPHERE_HPP

#include "hittable.hpp"


/*
 * sphere
 * Hittable sphere
 */
class sphere : public hittable
{
    public:
        vec3 center;
        float radius;

    public: 
        sphere();
        sphere(vec3 cent, float r);
        
        // hit
        virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
};


#endif /*__RT_SPHERE_HPP*/
