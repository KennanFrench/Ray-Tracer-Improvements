#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Ray-Tracer-Improvements\src\GenVector.h"
#include "..\Ray-Tracer-Improvements\src\Triangle.h"
#include "..\Ray-Tracer-Improvements\src\Material.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			//Can create triangles
			Vector3 v1 = Vector3(1.0f, 2.0f, 3.0f);
			Vector3 v2 = Vector3(1.0f, 2.0f, 3.0f);
			Vector3 v3 = Vector3(1.0f, 2.0f, 3.0f);
			Material m = Material(v1, v2, v3, 0.5f, 0.5f);
			Triangle t = Triangle(v1, v2, v3, 0, m);

			Vector3 expected = Vector3(1.0f, 2.0f, 3.0f);
			Assert::AreEqual(expected[0], t.getCenter()[0]);
			Assert::AreEqual(expected[1], t.getCenter()[1]);
			Assert::AreEqual(expected[2], t.getCenter()[2]);
		}

	};
}