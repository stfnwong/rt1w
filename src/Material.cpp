/*
 * MATERIAL
 * 
 * Stefan Wong 2019
 */

#include <cmath>
#include "Material.hpp"
#include "Sphere.hpp"


/*
 * Lambertian::Lambertian
 * Lambertian constructor
 */
Lambertian::Lambertian(const vec3& a) : albedo(a) {}

/*
 * Lambertian::scatter()
 */
bool Lambertian::scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const
{
    vec3 target;

    target = rec.p + rec.normal + random_in_unit_sphere();
    scattered = Ray(rec.p, target - rec.p);
    atten = this->albedo;

    return true;
}


/*
 * Metal::Metal
 * Metal constructor
 */
Metal::Metal(const vec3& a, float f) : albedo(a)
{
    if(f < 1)
        this->fuzz = f;
    else
        this->fuzz = 1.0f;
}

/*
 * Metal::scatter()
 */
bool Metal::scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const
{
    vec3 reflected;

    reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + this->fuzz * random_in_unit_sphere());
    atten = this->albedo;

    return (dot(scattered.direction(), rec.normal) > 0) ? true : false;
}


/*
 * Dielectric::scatter()
 */
bool Dielectric::scatter(const Ray& r_in, const hit_record& rec, vec3& atten, Ray& scattered) const
{
    vec3 outward_normal;
    vec3 reflected;
    vec3 refracted;
    float ni_nt;

    atten = vec3(1.0, 1.0, 0.0);
    reflected = reflect(r_in.direction(), rec.normal);

    if(dot(r_in.direction(), rec.normal) > 0)
    {
        outward_normal = -rec.normal;
        ni_nt = this->ref_idx;
    }
    else
    {
        outward_normal = rec.normal;
        ni_nt = 1.0 / this->ref_idx;
    }
    
    if(refract(r_in.direction(), outward_normal, ni_nt, refracted))
        scattered = Ray(rec.p, refracted);
    else
    {
        scattered = Ray(rec.p, reflected);
        return true;
    }
    
    return true;
}


/*
 * Dielectric::Dielectric
 * Dielectric constructor
 */
Dielectric::Dielectric(float ri) : ref_idx(ri) {}



/*
 * reflect()
 */
vec3 reflect(const vec3& v, const vec3& n)
{
    return v - 2 * dot(v, n) * n;
}


/*
 * refract()
 */
bool refract(const vec3& v, const vec3& n, float ni_nt, vec3& refracted)
{
    vec3 uv;
    float dt;
    float disc;

    uv = unit_vector(v);
    dt = dot(uv, n);
    disc = 1.0 - ni_nt * ni_nt * (1 - dt * dt);

    if(disc > 0)
    {
        refracted = ni_nt * (uv - n * dt) - n * sqrt(disc);
        return true;
    }
   
    return false;
}
