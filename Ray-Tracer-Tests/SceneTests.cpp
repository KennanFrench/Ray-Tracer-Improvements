#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ray-Tracer-Improvements/src/GenVector.h"
#include "../Ray-Tracer-Improvements/src/objLoader.hpp"
#include "../Ray-Tracer-Improvements/src/Scene.h"
#include "../Ray-Tracer-Improvements/src/Sphere.h"
#include "../Ray-Tracer-Improvements/src/Primative.h"
#include "../Ray-Tracer-Improvements/src/Material.h"
#include "../Ray-Tracer-Improvements/src/AABB.h"

#define _USE_MATH_DEFINES
#include <Math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RayTracerTests
{
	TEST_CLASS(SceneTest)
	{
	public:

		TEST_METHOD(ConstructorObjLoad)
		{
			objLoader oL = objLoader();
			oL.load("../spheres.obj");

			Scene scene = Scene(oL, M_PI / 2);
			Assert::AreEqual((int)(scene.getPrimatives().size()), 4);
			Assert::AreEqual((int)(scene.getLights().size()), 3);
			Assert::IsNotNull(&scene.getCamera());
		}

		TEST_METHOD(initializeCamera) {

		}
	};
}