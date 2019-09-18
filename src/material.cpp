/*
 * MATERIAL
 * 
 * Stefan Wong 2019
 */


#include "material.hpp"
#include "sphere.hpp"


lambertian::lambertian(const vec3& a) : albedo(a) {}

/*
 * lambertian::scatter()
 */
bool lambertian::scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const
{
    vec3 target;

    target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = ray(rec.p, target - rec.p);
    atten = this->albedo;

    return true;
}


metal::metal(const vec3& a) : albedo(a) {} 

/*
 * metal::scatter()
 */
bool metal::scatter(const ray& r_in, const hit_record& rec, vec3& atten, ray& scattered) const
{
    vec3 reflected;

    reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected);
    atten = this->albedo;

    return (dot(scattered.direction(), rec.normal) > 0) ? true : false;
}


/*
 * reflect()
 */
vec3 reflect(const vec3& v, const vec3& n)
{
    return v - 2 * dot(v, n) * n;
}
