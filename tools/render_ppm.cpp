/*
 * RENDER_PPM
 * Render a scene out to a ppm file.
 *
 * Stefan Wong 2019
 */


#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstdlib>

#include "Camera.hpp"
#include "Color.hpp"
#include "Sphere.hpp"
#include "Material.hpp"
#include "HittableList.hpp"

// TODO : add arg parser



// Actual rendering entry point
int main(void)
{
    int nx = 512;
    int ny = 256;
    int ns = 100;

    // Hittables 
    Hittable* list[2];
    Hittable* world;
    // materials
    Metal* m1;
    Metal* m2;
    Lambertian* l1;
    Dielectric* d1;
    m1 = new Metal(vec3(0.7, 0.7, 0.6), 0.4);
    m2 = new Metal(vec3(0.8, 0.7, 0.65), 0.1);
    l1 = new Lambertian(vec3(0.6, 0.65, 0.4));
    d1 = new Dielectric(0.5);

    // camera params 
    //vec3 cam_lookfrom(2, 2, 1);
    vec3 cam_lookfrom(5, 5, 2);
    vec3 cam_lookat(0, 0, -1);
    vec3 cam_vup(0, 1, 0);
    float cam_vfov = 90.0f;
    float cam_aspect = float(nx) / float(ny);
    float cam_aperture = 0.4;
    //float cam_focus_dist = 1.0;
    float cam_focus_dist = (cam_lookfrom - cam_lookat).length() / 2;

    // a camera object
    Camera cam(
            cam_lookfrom,
            cam_lookat,
            cam_vup,
            cam_vfov,
            cam_aspect,
            cam_aperture,
            cam_focus_dist
    );

    // generate some spheres
    //float R = cos(M_PI / 4);
    //list[0] = new Sphere(vec3(-R, 0, -1), R, d1);
    //list[1] = new Sphere(vec3(R, 0, -1), R, m2);

    list[0] = new Sphere(vec3(0, 0, -1), 0.6, d1);
    list[1] = new Sphere(vec3(-1, 0, -1), 0.5, m2);
    list[2] = new Sphere(vec3(1, 0, -1), 0.7, m1);
    list[3] = new Sphere(vec3(0, -100.5, -1), 100, l1);
    
    // generate our world of Hittable things
    world   = new HittableList(list, 4);

    std::cout << "P3\n" << nx << " " << ny << "\n255\n";

    for(int j = ny-1; j >= 0; --j)
    {
        for(int i = 0; i < nx; ++i)
        {
            // anti-aliasing (blend with some random background pixels)
            vec3 col(0, 0, 0);
            for(int s = 0; s < ns; ++s)
            {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                Ray r = cam.get_ray(u, v);
                col += color_metal(r, world, 0);
            }
            col /= float(ns);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    delete world;

    return 0;
}
