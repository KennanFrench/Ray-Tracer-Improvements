#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Ray.h"
#include "../Ray-Tracer-Improvements/src/Sphere.h"
#include "../Ray-Tracer-Improvements/src/Material.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{
	TEST_CLASS(SphereTest)
	{
	public:

		TEST_METHOD(SphereIntersect)
		{
			Vector3 origin = Vector3(0.0f, 0.0f, 0.0f);
			Vector3 center = Vector3(1.0f, 1.0f, 1.0f);
			Sphere s = Sphere(center, 1.0f, 0, Material(1.0f, 2.0f, 3.0f, 0.0f, 0.0f));

			Vector3 hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Hitpoint hp = Hitpoint(0, -1, hpNorm);
			Ray rayHit = Ray(origin, center);
			Ray rayMiss = Ray(origin, Vector3(1.0f, 0.0f, 0.0f));

			Assert::IsTrue(s.intersect(rayHit, hp));
			hp = Hitpoint(0, -1, hpNorm);
			hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Assert::IsFalse(s.intersect(rayMiss, hp));
		}
	};
}