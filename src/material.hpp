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
        virtual ~material() {}
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


/*
 * metal
 * A reflective material
 */
class metal : public material
{
    public:
        vec3 albedo;
        float fuzz;

    public:
        metal(const vec3& a, float f);
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const;
};


/*
 * dielectric 
 * Material that splits incoming ray into a reflected ray and 
 * a refracted ray.
 */
class dielectric : public material
{
    public:
        float ref_idx;

    public:
        dielectric(float ri);
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const;
};



/*
 * reflect()
 * Reflect a ray
 */
vec3 reflect(const vec3& v, const vec3& n);

/*
 * refract()
 * Compute Snell's law for refraction. 
 */
bool refract(const vec3& v, const vec3& n, float ni_nt, vec3& refracted);


#endif /*__RT_MATERIAL_HPP*/
