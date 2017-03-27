#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Camera.h"
#include "../Ray-Tracer-Improvements/src/RayGenerator.h"
#include "../Ray-Tracer-Improvements/src/Ray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{
	TEST_CLASS(RayGeneratorTest)
	{
	public:

		TEST_METHOD(testGetRay)
		{
			Vector3 origin = Vector3(0.0f, 0.0f, 0.0f);
			Camera c = Camera(origin, Vector3(0.0f, 0.0f, 1.0f), Vector3(0.0f, 1.0f, 0.0f));

			RayGenerator rg = RayGenerator(c, 101, 101);
			Ray r1 = rg.getRay(0, 0);
			Ray r2 = rg.getRay(0, 99);
			Ray r3 = rg.getRay(99, 0);
			Ray r4 = rg.getRay(99, 99);
			Ray r5 = rg.getRay(50, 50);
		}
	};
}