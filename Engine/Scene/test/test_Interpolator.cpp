#include "Scene/Interpolator.hpp"

#include <gtest/gtest.h>

using namespace Stone::Scene;

TEST(Interpolator, IsEmpty) {
	Interpolator<int> interpolator;
	EXPECT_TRUE(interpolator.isEmpty());

	interpolator.addKeyValueAt(10, 0.0f);
	EXPECT_FALSE(interpolator.isEmpty());
}

TEST(Interpolator, Duration) {
	Interpolator<int> interpolator;
	EXPECT_EQ(interpolator.duration(), 0);

	interpolator.addKeyValueAt(10, 0.0f);
	interpolator.addKeyValueAt(20, 1.0f);
	EXPECT_EQ(interpolator.duration(), 1.0f);
}

TEST(Interpolator, AddKeyValueAt) {
	Interpolator<int> interpolator;
	interpolator.addKeyValueAt(10, 0.0f);
	interpolator.addKeyValueAt(20, 1.0f);

	EXPECT_EQ(interpolator.valueAt(0.5f), 15);
}

TEST(Interpolator, RemoveKeyValueAt) {
	Interpolator<int> interpolator;
	interpolator.addKeyValueAt(10, 0.0f);
	interpolator.addKeyValueAt(10, 1.0f);
	interpolator.addKeyValueAt(30, 2.0f);
	EXPECT_EQ(interpolator.valueAt(1.0f), 10);

	interpolator.removeKeyValueAt(1);
	EXPECT_EQ(interpolator.valueAt(1.0f), 20);

	interpolator.removeKeyValueAt(1.5f);
	EXPECT_EQ(interpolator.valueAt(1.5f), 10);
}

TEST(Interpolator, ValueAt) {
	Interpolator<int> interpolator;
	interpolator.addKeyValueAt(10, 0.0f);
	interpolator.addKeyValueAt(20, 1.0f);
	interpolator.addKeyValueAt(30, 2.0f);

	EXPECT_EQ(interpolator.valueAt(0.5f), 15);
	EXPECT_EQ(interpolator.valueAt(1.5f), 25);
	EXPECT_EQ(interpolator.valueAt(2.5f), 30);
}

TEST(Interpolator, FloatAddKeyValueAt) {
	Interpolator<float> interpolator;
	interpolator.addKeyValueAt(10.0f, 0.0f);
	interpolator.addKeyValueAt(20.0f, 1.0f);

	EXPECT_NEAR(interpolator.valueAt(0.5f), 15.0f, 0.001f);
}

TEST(Interpolator, FloatRemoveKeyValueAt) {
	Interpolator<float> interpolator;
	interpolator.addKeyValueAt(10.0f, 0.0f);
	interpolator.addKeyValueAt(10.0f, 1.0f);
	interpolator.addKeyValueAt(30.0f, 2.0f);
	EXPECT_EQ(interpolator.valueAt(1.0f), 10.0f);

	interpolator.removeKeyValueAt(1);
	EXPECT_EQ(interpolator.valueAt(1.0f), 20.0f);

	interpolator.removeKeyValueAt(1.5f);
	EXPECT_EQ(interpolator.valueAt(1.5f), 10.0f);
}

TEST(Interpolator, FloatValueAt) {
	Interpolator<float> interpolator;
	interpolator.addKeyValueAt(10.0f, 0.0f);
	interpolator.addKeyValueAt(20.0f, 1.0f);
	interpolator.addKeyValueAt(40.0f, 2.0f);

	EXPECT_EQ(interpolator.valueAt(0.5f), 15.0f);
	EXPECT_EQ(interpolator.valueAt(1.5f), 30.0f);
	EXPECT_EQ(interpolator.valueAt(2.5f), 40.0f);
}

TEST(Interpolator, Vec3ValueAt) {
	Interpolator<glm::vec3> interpolator;
	interpolator.addKeyValueAt(glm::vec3(10.0f, 0.0f, 50.0f), 0.0f);
	interpolator.addKeyValueAt(glm::vec3(20.0f, 100.0f, -50.0f), 1.0f);

	EXPECT_NEAR(interpolator.valueAt(0.5f).x, 15.0f, 0.001f);
	EXPECT_NEAR(interpolator.valueAt(0.5f).y, 50.0f, 0.001f);
	EXPECT_NEAR(interpolator.valueAt(0.5f).z, 0.0f, 0.001f);
}

TEST(Interpolator, QuatValueAt) {
	Interpolator<glm::quat> interpolator;
	interpolator.addKeyValueAt(glm::quat(1.0f, 3.0f, 0.5f, 1.0f), 0.0f);
	interpolator.addKeyValueAt(glm::quat(2.0f, 3.0f, 1.5f, 2.0f), 1.0f);

	EXPECT_NEAR(interpolator.valueAt(0.5f).x, 3.0f, 0.001f);
	EXPECT_NEAR(interpolator.valueAt(0.5f).y, 1.0f, 0.001f);
	EXPECT_NEAR(interpolator.valueAt(0.5f).z, 1.5f, 0.001f);
	EXPECT_NEAR(interpolator.valueAt(0.5f).w, 1.5f, 0.001f);
}
