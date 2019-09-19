/*
 * TEST_SPHERE 
 * Unit tests for Sphere .
 *
 * Stefan Wong 2019
 */


#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <gtest/gtest.h>

// unit(s) under test
#include "Ray.hpp"
#include "Material.hpp"
#include "Sphere.hpp"



class TestSphere : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};


TEST_F(TestSphere, test_sphere_init)
{
    Metal *mat;
    Sphere* sphere_obj;
    vec3 center(0.0, 0.0, -0.1);
    float r = 2.1;

    vec3 metal_albedo(0.8, 0.2, 0.3);
    mat = new Metal(metal_albedo, 0.5);
    sphere_obj = new Sphere(center, r, mat);

    EXPECT_TRUE(sphere_obj->mat);        

    delete sphere_obj;
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
