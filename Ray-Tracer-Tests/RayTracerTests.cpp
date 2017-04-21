#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Triangle.h"
#include "../Ray-Tracer-Improvements/src/Sphere.h"
#include "../Ray-Tracer-Improvements/src/Primative.h"
#include "../Ray-Tracer-Improvements/src/Material.h"
#include "../Ray-Tracer-Improvements/src/AABB.h"
#include "../Ray-Tracer-Improvements/src/RayTracer.cpp"
#include "../Ray-Tracer-Improvements/src/Buffer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{
	TEST_CLASS(RayTracerTests)
	{
	public:

		TEST_METHOD(TestScaleByHighestColorValue) {
			RayTracer rt = RayTracer();
			Buffer<Vector3> buf = Buffer<Vector3>(5, 5);
			rt.setHighestValue(1);
			rt.setResolution(5, 5);
			buf.at(0, 0) = Vector3(1, 1, 1);
			buf.at(0, 4) = Vector3(1, 1, 1);
			Color r = rt.scaleByHighestColorValue(0, 0, buf);
			Assert::IsTrue(r[0] - 255 < 0.01);
			Assert::IsTrue(r[0] - 255 > -0.01);
			Assert::IsTrue(r[1] - 255 < 0.01);
			Assert::IsTrue(r[1] - 255 > -0.01);
			Assert::IsTrue(r[2] - 255 < 0.01);
			Assert::IsTrue(r[2] - 255 > -0.01);

			rt.setHighestValue(10);
			r = rt.scaleByHighestColorValue(0, 0, buf);
			Assert::IsTrue(r[0] - 25 < 0.01);
			Assert::IsTrue(r[0] - 25 > -0.01);
			Assert::IsTrue(r[1] - 25 < 0.01);
			Assert::IsTrue(r[1] - 25 > -0.01);
			Assert::IsTrue(r[2] - 25 < 0.01);
			Assert::IsTrue(r[2] - 25 > -0.01);
		}

		TEST_METHOD(TestBuffer) {
			RayTracer rt = RayTracer("../cornell_box.obj", 5, 5, M_PI / 2.0f);
			Buffer<Vector3> expected = Buffer<Vector3>(5, 5);
			expected.at(0, 4) = Vector3(0, 0, 0);
			expected.at(1, 4) = Vector3(0, 0, 0);
			expected.at(2, 4) = Vector3(0, 0, 0);
			expected.at(3, 4) = Vector3(0, 0, 0);
			expected.at(4, 4) = Vector3(0, 0, 0);
			expected.at(0, 3) = Vector3(0, 0, 0);
			expected.at(1, 3) = Vector3(0.9, 0.225, 0.135);
			expected.at(2, 3) = Vector3(1.08, 0.9, 0.54);
			expected.at(3, 3) = Vector3(1.814671, 3.948428, 0.907335);
			expected.at(4, 3) = Vector3(0, 0, 0);
			expected.at(0, 2) = Vector3(0, 0, 0);
			expected.at(1, 2) = Vector3(7.016964, 0, 0);
			expected.at(2, 2) = Vector3(1.390910, 1.159091, 0.695455);
			expected.at(3, 2) = Vector3(0, 5.004099, 0);
			expected.at(4, 2) = Vector3(0, 0, 0);
			expected.at(0, 1) = Vector3(0, 0, 0);
			expected.at(1, 1) = Vector3(0.906233, 0.755194, 0.453117);
			expected.at(2, 1) = Vector3(0.961929, 0.801608, 0.480965);
			expected.at(3, 1) = Vector3(0.906233, 0.755194, 0.453117);
			expected.at(4, 1) = Vector3(0, 0, 0);
			expected.at(0, 0) = Vector3(0, 0, 0);
			expected.at(1, 0) = Vector3(0, 0, 0);
			expected.at(2, 0) = Vector3(0, 0, 0);
			expected.at(3, 0) = Vector3(0, 0, 0);
			expected.at(4, 0) = Vector3(0, 0, 0);

			Buffer<Vector3> result = rt.getAllShadeValues();

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					Vector3 val = result.at(i, j);
					Assert::IsTrue(result.at(i, j)[0] - expected.at(i, j)[0] < 0.01);
					Assert::IsTrue(result.at(i, j)[0] - expected.at(i, j)[0] > -0.01);
					Assert::IsTrue(result.at(i, j)[1] - expected.at(i, j)[1] < 0.01);
					Assert::IsTrue(result.at(i, j)[1] - expected.at(i, j)[1] > -0.01);
					Assert::IsTrue(result.at(i, j)[2] - expected.at(i, j)[2] < 0.01);
					Assert::IsTrue(result.at(i, j)[2] - expected.at(i, j)[2] > -0.01);
				}
			}
		}

	};
}