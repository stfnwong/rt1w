/*
 * COLOR
 * Different coloring methods for spheres
 *
 * Stefan Wong 2019
 */

#define MAX_RECURSE_DEPTH 50

#include "Color.hpp"
#include "Sphere.hpp"


/*
 * color_normal()
 */
vec3 color_normal(const Ray& r, Hittable* world)
{
    float t;
    vec3 unit_direction;
    hit_record rec;

    if(world->hit(r, 0.0001, MAXFLOAT, rec))
    {
        return 0.5 * vec3(
                rec.normal.x() + 1,
                rec.normal.y() + 1,
                rec.normal.z() + 1
        );
    }
    else
    {
        unit_direction = unit_vector(r.direction());
        t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}


/*
 * color_diffuse()
 */
vec3 color_diffuse(const Ray& r, Hittable* world)
{
    float t;
    vec3 target;
    vec3 unit_direction;
    hit_record rec;

    if(world->hit(r, 0.0001, MAXFLOAT, rec))
    {
        target = rec.p + rec.normal + random_in_unit_sphere();
        return 0.5 * color_diffuse(Ray(rec.p, target - rec.p), world);
    }
    else
    {
        unit_direction = unit_vector(r.direction());
        t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}


/*
 * color_metal()
 */
vec3 color_metal(const Ray& r, Hittable* world, int depth)
{
    float t;
    vec3 target;
    vec3 atten;
    vec3 unit_direction;
    Ray scattered;
    hit_record rec;

    if(world->hit(r, 000.1, MAXFLOAT, rec))
    {
        if((depth < 50) && (rec.mat->scatter(r, rec, atten, scattered)))
            return atten * color_metal(scattered, world, depth+1);
        else
            return vec3(0, 0, 0);
    }
    else
    {
        unit_direction = unit_vector(r.direction());
        t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
    }
}
