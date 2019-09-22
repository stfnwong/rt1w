/*
 * MATERIAL
 * 
 * Stefan Wong 2019
 */

#ifndef __RT_MATERIAL_HPP
#define __RT_MATERIAL_HPP

#include "Ray.hpp"
#include "Hittable.hpp"


/*
 * Material
 * Abstract base class for Materials. Materials contain information about how a Ray 
 * will interact with a surface.
 */
class Material
{
    public:
        virtual ~Material() {}
        virtual bool scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const = 0;
};


/*
 * Lambertian
 * Diffuse Material
 */
class Lambertian : public Material
{
    public:
        vec3 albedo;

    public:
        Lambertian(const vec3& a);
        virtual bool scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const;
};


/*
 * Metal
 * A reflective Material
 */
class Metal : public Material
{
    public:
        vec3 albedo;
        float fuzz;

    public:
        Metal(const vec3& a, float f);
        virtual bool scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const;
};


/*
 * Dielectric 
 * Material that splits incoming Ray into a reflected Ray and 
 * a refracted Ray.
 */
class Dielectric : public Material
{
    public:
        float ref_idx;

    public:
        Dielectric(float ri);
        virtual bool scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const;
};



/*
 * reflect()
 * Reflect a Ray
 */
vec3 reflect(const vec3& v, const vec3& n);

/*
 * refract()
 * Compute Snell's law for refraction. 
 */
bool refract(const vec3& v, const vec3& n, float ni_nt, vec3& refracted);


#endif /*__RT_MATERIAL_HPP*/
