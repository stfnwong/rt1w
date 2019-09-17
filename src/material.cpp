/*
 * MATERIAL
 * 
 * Stefan Wong 2019
 */


#include "material.hpp"
#include "sphere.hpp"


lambertian::lambertian(const vec3& a) : albedo(a) {}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const
{
    vec3 target;

    target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = ray(rec.p, target - rec.p);
    atten = this->albedo;

    return true;
}
