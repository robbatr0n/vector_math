#include <gtest/gtest.h>
#include <vector_math/vector3.hpp>

TEST(Vector3Test, CheckVectorInitilisation) {
    Vector3<float> v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);

    Vector3<float> v1(10, 20, 30);
    EXPECT_EQ(v1.x, 10);
    EXPECT_EQ(v1.y, 20);
    EXPECT_EQ(v1.z, 30);
}

TEST(Vector3Test, CheckVectorAddition) {
    Vector3<float> v1(10, 20, 30);
    Vector3<float> v2(10, 20, 30);
    Vector3<float> result = v1 + v2;
    EXPECT_EQ(result.x, 20);
    EXPECT_EQ(result.y, 40);
    EXPECT_EQ(result.z, 60);
}

TEST(Vector3Test, CheckVectorSubtraction) {
    Vector3<float> v1(10, 20, 30);
    Vector3<float> v2(5, 10, 20);
    Vector3<float> result = v1 - v2;
    EXPECT_EQ(result.x, 5);
    EXPECT_EQ(result.y, 10);
    EXPECT_EQ(result.z, 10);
}

TEST(Vector3Test, CheckVectorScalarMultiplication) {
    Vector3<float> v1(10, 20, 30);
    float s = 6;
    EXPECT_EQ(v1.x * s, 60);
    EXPECT_EQ(v1.y * s, 120);
    EXPECT_EQ(v1.z * s, 180);
}

TEST(Vector3Test, CheckVectorNormalisation) {
    Vector3<float> v1(10, 20, 30);
    v1.Normalize();
    ASSERT_NEAR(v1.Normalize().x, 0.267261f, .000001f);
    ASSERT_NEAR(v1.Normalize().y, 0.534522f, .000001f);
    ASSERT_NEAR(v1.Normalize().z, 0.801784f, .000001f);
}

TEST(Vector3Test, CheckVectorLength) {
    Vector3<float> v1(10, 20, 30);
    ASSERT_NEAR(v1.Length(), 37.4166, 0.0001);
}

TEST(Vector3Test, CheckDotProduct) {
    Vector3<float> v1(10, 20, 30);
    Vector3<float> v2(40, 30, 20);
    EXPECT_EQ(v1.Dot(v2), 1600);
}

TEST(Vector3Test, CheckCrossProduct) {
    Vector3<float> v1(10, 20, 30);
    Vector3<float> v2(40, 30, 20);
    Vector3<float> result = v1.Cross(v2);
    EXPECT_EQ(result.x, -500);
    EXPECT_EQ(result.y, 1000);
    EXPECT_EQ(result.z, -500);
}