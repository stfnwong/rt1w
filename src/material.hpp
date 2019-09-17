/*
 * MATERIAL
 * 
 * Stefan Wong 2019
 */

#ifndef __RT_MATERIAL_HPP
#define __RT_MATERIAL_HPP

#include "ray.hpp"
#include "hittable.hpp"


/*
 * material
 * Abstract base class for materials. Materials contain information about how a ray 
 * will interact with a surface.
 */
class material
{
    public:
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const = 0;
};


/*
 * lambertian
 * Diffuse material
 */
class lambertian : public material
{
    public:
        vec3 albedo;

    public:
        lambertian(const vec3& a);
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const;
};



#endif /*__RT_MATERIAL_HPP*/
