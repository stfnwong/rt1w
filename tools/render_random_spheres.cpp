/*
 * RENDER_RANDOM_SPHERES
 * Render a variety of spheres to std::cout
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


Hittable* random_scene(int n)
{
    Hittable** list = new Hittable*[n+1];

    // make a single giant sphere for the 'ground'
    vec3 giant_sphere_pos(0, -1000, 0);
    list[0] = new Sphere(giant_sphere_pos, 1000, new Lambertian(vec3(0.5, 0.5, 0.5)));

    int i = 1;
    for(int a = -11; a < 11; ++a)
    {
        for(int b = -11; b < 11; ++b)
        {
            float choose_mat = drand48();
            vec3 center(a + 0.9 * drand48(), 0.2, 0.9 + b * drand48());
            if((center - vec3(4, 0.2, 0)).length() > 0.9)
            {
                // diffuse 
                if(choose_mat < 0.8)
                {
                    list[i++] = new Sphere(
                            center,
                            0.2,
                            new Lambertian(vec3(
                                    drand48() * drand48(), 
                                    drand48() * drand48(), 
                                    drand48() * drand48()
                            )
                        )
                    );
                }
                // metal  
                else if(choose_mat < 0.95)
                {
                    list[i++] = new Sphere(
                            center,
                            0.2,
                            new Metal(vec3(
                                    0.5 * (1 + drand48()),
                                    0.5 * (1 + drand48()),
                                    0.5 * (1 + drand48())
                                ), 0.5 * drand48()
                            )
                        );

                }
                // glass
                else
                {
                    list[i++] = new Sphere(
                            center,
                            0.2,
                            new Dielectric(1.5)
                    );

                }
            }
        }
    }

    // add some additional larger spheres to anchor the scene
    list[i++] = new Sphere(vec3(0, 1, 0), 1.0, new Dielectric(1.6));
    list[i++] = new Sphere(vec3(-4, 1, 0), 1.0, new Lambertian(vec3(0.4, 0.2, 0.1)));
    list[i++] = new Sphere(vec3(4, 1, 0), 1.0, new Metal(vec3(0.7, 0.6, 0.5), 0.0));

    return new HittableList(list, i);
}


// Actual rendering entry point
int main(void)
{
    int nx = 512;
    int ny = 256;
    int ns = 100;

    // frame-space co-ordinates?
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    // Hittables 
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

    // Camera params 
    vec3 cam_lookfrom(-2, -2, 1);
    vec3 cam_lookat(0, 0, -1);
    vec3 cam_vup(0, 1, 0);
    float cam_vfov = 60.0f;
    float cam_aspect = float(nx) / float(ny);
    float cam_aperture = 2.0;
    float cam_focus_dist = (cam_lookfrom - cam_lookat).length();

    // a Camera object
    Camera cam(
            cam_lookfrom,
            cam_lookat,
            cam_vup,
            cam_vfov,
            cam_aspect,
            cam_aperture,
            cam_focus_dist
    );

    float R = cos(M_PI / 2);

    // generate our world of Hittable things
    world = random_scene(500);

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
                //vec3 p = r.point_at_parameter(2.0);
                col += color_metal(r, world, 0);
            }
            col /= float(ns);

            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    // TODO: need to properly manage world memory...

    return 0;
}

