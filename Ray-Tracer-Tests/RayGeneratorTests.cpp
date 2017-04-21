#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Camera.h"
#include "../Ray-Tracer-Improvements/src/RayGenerator.h"
#include "../Ray-Tracer-Improvements/src/Ray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define _USE_MATH_DEFINES
#include <Math.h>

namespace RayTracerTests
{
	TEST_CLASS(RayGeneratorTest)
	{
	public:

		TEST_METHOD(testGetRay)
		{
			Vector3 origin = Vector3(0.0f, 0.0f, 0.0f);
			Camera c = Camera(origin, Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f), M_PI / 2);

			RayGenerator rg = RayGenerator(c, 101, 101);
			Ray r1 = rg.getRayFromPixelLocation(0, 0);
			Ray r2 = rg.getRayFromPixelLocation(0, 99);
			Ray r3 = rg.getRayFromPixelLocation(99, 0);
			Ray r4 = rg.getRayFromPixelLocation(99, 99);
			Ray r5 = rg.getRayFromPixelLocation(50, 50);
		}

		TEST_METHOD(testGetPixelInWorldCoordinates)
		{
			Vector3 expected = Vector3();
			Vector3 origin = Vector3(0.0f, 0.0f, 0.0f);
			Camera c = Camera(origin, Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f), M_PI / 2);
			float u = 1.0f;
			float v = 1.0f;
			float distanceToCamera = 5.0f;

			RayGenerator rg = RayGenerator(c, 101, 101);
		}
	};
}