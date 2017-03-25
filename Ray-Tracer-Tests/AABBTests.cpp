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

	};
}