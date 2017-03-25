#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Triangle.h"
#include "../Ray-Tracer-Improvements/src/Material.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vector3 v1 = Vector3(1.0f, 2.0f, 3.0f);
			Triangle t = Triangle(v1, v1, v1, 0, Material(1.0f, 2.0f, 3.0f, 0.0f, 0.0f));
			Assert::AreEqual(v1[0], t.getCenter()[0]);
		}

	};
}