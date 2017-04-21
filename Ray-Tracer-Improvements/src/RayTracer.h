#ifndef RAY_TRACER_H
#define	RAY_TRACER_H

#include "Buffer.h"
#include "GenVector.h"
#include "obj_parser.h"
#include "objLoader.hpp"
#include "Scene.h"
#include "Shader.h"
#include "RayGenerator.h"
#include "Camera.h"
#include "Ray.h"
#include "Hitpoint.h"
#include "simplePNG.h"

class RayTracer {

private:

	Scene scene;
	Shader shader;
	RayGenerator generator;
	double highestColorValue;
	int resx;
	int resy;

public:

	RayTracer();
	RayTracer(char* fileIn, int resx, int resy, float fieldOfView);
	Buffer<Vector3> getAllShadeValues();
	void getShadeValue(int x, int y, Buffer<Vector3> &buffer);
	void updateHighestValue(int x, int y, Buffer<Vector3> buffer);
	Buffer<Color> convertVec3sToRGBColors(Buffer<Vector3> buffer);
	Color scaleByHighestColorValue(int x, int y, Buffer<Vector3> buffer);
	void setHighestValue(double val);
	void setResolution(int x, int y);

};

#endif