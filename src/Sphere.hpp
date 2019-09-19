/*
 * SPHERE
 * Definition of a Sphere in terms of a hittable
 *
 * Stefan Wong 2019
 */

#ifndef __RT_SPHERE_HPP
#define __RT_SPHERE_HPP

#include "Hittable.hpp"
#include "Material.hpp"

// get a random vector that lies within a unit Sphere
vec3 random_in_unit_sphere(void);

/*
 * Sphere
 * Hittable Sphere
 */
class Sphere : public Hittable
{
    public:
        vec3 center;
        float radius;
        Material* mat;

    public: 
        Sphere();
        virtual ~Sphere();
        Sphere(vec3 cent, float r, Material* m);
        
        // hit
        virtual bool hit(const Ray& r, float t_min, float t_max, hit_record& rec) const;
};




#endif /*__RT_SPHERE_HPP*/
