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

	};
}