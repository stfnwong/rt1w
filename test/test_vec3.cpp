/*
 * TEST_VEC3 
 * Unit tests for vec3 class
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

class TestVec3 : public ::testing::Test
{
    virtual void SetUp() {}
    virtual void TearDown() {}
};

TEST_F(TestVec3, test_init)
{
    vec3 test_vec1;
    EXPECT_FLOAT_EQ(0.0, test_vec1[0]);
    EXPECT_FLOAT_EQ(0.0, test_vec1[1]);
    EXPECT_FLOAT_EQ(0.0, test_vec1[2]);

    vec3 test_vec2(1.0f, 2.2f, 2.3f);
    EXPECT_FLOAT_EQ(1.0, test_vec2[0]);
    EXPECT_FLOAT_EQ(2.2, test_vec2[1]);
    EXPECT_FLOAT_EQ(2.3, test_vec2[2]);
}


// Arithmetic tests 
TEST_F(TestVec3, test_add)
{
    vec3 v1(0.0, 0.0, 0.1);
    vec3 v2(0.0, 0.0, 0.1);
    vec3 v3;

    v3 = v1 + v2;
    EXPECT_FLOAT_EQ(0.0, v3[0]);
    EXPECT_FLOAT_EQ(0.0, v3[1]);
    EXPECT_FLOAT_EQ(0.2, v3[2]);
    
}

TEST_F(TestVec3, test_obj_add)
{
    vec3 v1(0.0, 0.0, 0.1);
    vec3 v2(0.0, 0.0, 0.1);

    EXPECT_FLOAT_EQ(0.0, v1[0]);
    EXPECT_FLOAT_EQ(0.0, v1[1]);
    EXPECT_FLOAT_EQ(0.1, v1[2]);

    EXPECT_FLOAT_EQ(0.0, v2[0]);
    EXPECT_FLOAT_EQ(0.0, v2[1]);
    EXPECT_FLOAT_EQ(0.1, v2[2]);

    v2 += v1;
    EXPECT_FLOAT_EQ(0.0, v2[0]);
    EXPECT_FLOAT_EQ(0.0, v2[1]);
    EXPECT_FLOAT_EQ(0.2, v2[2]);
}

TEST_F(TestVec3, test_sub)
{
    vec3 v1(0.0, 0.4, 0.2);
    vec3 v2(0.0, 0.2, 0.1);
    vec3 v3;

    v3 = v1 - v2;
    EXPECT_FLOAT_EQ(0.0, v3[0]);
    EXPECT_FLOAT_EQ(0.2, v3[1]);
    EXPECT_FLOAT_EQ(0.1, v3[2]);

}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
