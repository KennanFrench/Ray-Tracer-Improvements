#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Ray.h"
#include "../Ray-Tracer-Improvements/src/Triangle.h"
#include "../Ray-Tracer-Improvements/src/Material.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{
	TEST_CLASS(TriangleTest)
	{
	public:

		TEST_METHOD(TriangleIntersect)
		{
			Vector3 origin = Vector3(0.0f, 0.0f, 0.0f);
			Vector3 v1 = Vector3(1.0f, 1.0f, 1.0f);
			Vector3 v2 = Vector3(2.0f, 5.0f, 1.0f);
			Vector3 v3 = Vector3(3.0f, 1.0f, 1.0f);
			Triangle t = Triangle(v1, v2, v3, 0, Material(1.0f, 2.0f, 3.0f, 0.0f, 0.0f));

			Vector3 hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Hitpoint hp = Hitpoint(0, -1, hpNorm);
			Ray rayHit = Ray(origin, Vector3(2.0f, 3.0f, 1.0f));
			Ray rayMiss = Ray(origin, Vector3(1.0f, 0.0f, 0.0f));

			Assert::IsTrue(t.intersect(rayHit, hp));
			hp = Hitpoint(0, -1, hpNorm);
			hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Assert::IsFalse(t.intersect(rayMiss, hp));
		}
	};
}