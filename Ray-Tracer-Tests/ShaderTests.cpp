#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/Shader.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/Material.h"
#include "../Ray-Tracer-Improvements/src/Light.h"
#include "../Ray-Tracer-Improvements/src/Hitpoint.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayGeneratorTests
{
	TEST_CLASS(ShaderTest) {
	public:

		TEST_METHOD(testCalculateSpecular) {
			Shader s = Shader();
			Vector3 v1 = Vector3(1.0f, 2.0f, 3.0f);
			Vector3 v2 = Vector3(2.0f, 3.0f, 4.0f);
			Material mat = Material(v1, v2, v1, 2.0f, 3.0f);
			Light light = Light(mat, v1);
			Hitpoint hp = Hitpoint(1.0f, 1, v1);
			Assert::IsTrue(Vector3(2744, 0, 0) == s.calculateSpecular(mat, light, v1, v1));
		}
	};
}