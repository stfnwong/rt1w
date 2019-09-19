/*
 * TEST_RAY 
 * Unit tests for ray class
 *
 * Stefan Wong 2019
 */


#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <gtest/gtest.h>

// unit(s) under test
#include "vec3.hpp"
#include "Ray.hpp"

class TestRay : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};


TEST_F(TestRay, test_ray_init)
{
    Ray test_ray;

    EXPECT_FLOAT_EQ(0.0, test_ray.A[0]);
    EXPECT_FLOAT_EQ(0.0, test_ray.A[1]);
    EXPECT_FLOAT_EQ(0.0, test_ray.A[2]);

    EXPECT_FLOAT_EQ(0.0, test_ray.B[0]);
    EXPECT_FLOAT_EQ(0.0, test_ray.B[1]);
    EXPECT_FLOAT_EQ(0.0, test_ray.B[2]);
}



int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
