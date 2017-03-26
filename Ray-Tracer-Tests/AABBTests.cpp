#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Triangle.h"
#include "../Ray-Tracer-Improvements/src/Primative.h"
#include "../Ray-Tracer-Improvements/src/Material.h"
#include "../Ray-Tracer-Improvements/src/AABB.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{		
	TEST_CLASS(AABBTest)
	{
	public:
		
		TEST_METHOD(ConstructorGetMinGetMax)
		{
			Vector3 v1 = Vector3(1.0f, 2.0f, 3.0f);
			Triangle t = Triangle(v1, v1, v1, 0, Material(1.0f, 2.0f, 3.0f, 0.0f, 0.0f));
			Assert::AreEqual(v1[0], t.getCenter()[0]);
			vector<Primative*> primList1 = vector<Primative*>();
			primList1.push_back(&t);
			vector<Primative*> primList2 = vector<Primative*>();
			primList2.push_back(&t);
			primList2.push_back(&t);
			vector<Primative*> emptyPrimList = vector<Primative*>();
			AABB aabb1 = AABB(primList1);
			AABB aabb2 = AABB(primList2);
			try {
				AABB errorTree = AABB(emptyPrimList);
			}
			catch (const std::logic_error& e) {
				return;
			}

			Assert::AreEqual(v1[0], aabb1.getMin()[0]);
			Assert::AreEqual(v1[1], aabb1.getMin()[1]);
			Assert::AreEqual(v1[2], aabb1.getMin()[2]);

			Assert::AreEqual(v1[0], aabb2.getMax()[0]);
			Assert::AreEqual(v1[1], aabb2.getMax()[1]);
			Assert::AreEqual(v1[2], aabb2.getMax()[2]);
		}

		TEST_METHOD(AABBIntersect)
		{
			Vector3 v1 = Vector3(1.0f, 2.0f, 3.0f);
			Vector3 v2 = Vector3(4.0f, 5.0f, 6.0f);
			Vector3 v3 = Vector3(7.0f, 8.0f, 9.0f);
			Triangle t = Triangle(v1, v2, v3, 0, Material(1.0f, 2.0f, 3.0f, 0.0f, 0.0f));

			vector<Primative*> primList1 = vector<Primative*>();
			primList1.push_back(&t);
			AABB aabb1 = AABB(primList1);

			Vector3 hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Hitpoint hp = Hitpoint(0, -1, hpNorm);
			Vector3 origin = Vector3(0.0f, 0.0f, 0.0f);

			Vector3 hitRayDir = Vector3(5.0f, 5.0f, 5.0f);
			Ray hitRay = Ray(origin, hitRayDir);
			Assert::IsTrue(aabb1.intersect(hitRay, hp));

			Vector3 missRay1Dir = Vector3(1.0f, 1.0f, 10.0f);
			Ray missRay1 = Ray(origin, missRay1Dir);
			hp = Hitpoint(0, -1, hpNorm);
			hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Assert::IsFalse(aabb1.intersect(missRay1, hp));

			Vector3 missRay2Dir = Vector3(-1.0f, -1.0f, -1.0f);
			Ray missRay2 = Ray(origin, missRay2Dir);
			hp = Hitpoint(0, -1, hpNorm);
			hpNorm = Vector3(0.0f, 0.0f, 0.0f);
			Assert::IsFalse(aabb1.intersect(missRay2, hp));
		}

	};
}