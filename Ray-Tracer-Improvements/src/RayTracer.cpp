#ifndef RAY_TRACER_CPP
#define	RAY_TRACER_CPP

#include "RayTracer.h"
#define RES 300

RayTracer::RayTracer() {

}

RayTracer::RayTracer(char* fileIn) {
	objLoader objData = objLoader();
	objData.load(fileIn);
	this->scene = Scene(objData);
	this->shader = Shader(scene);
	this->generator = RayGenerator(scene.getCamera(), RES, RES);
}

Buffer<Vector3> RayTracer::getAllShadeValues() {
	Buffer<Vector3> buffer = Buffer<Vector3>(RES, RES);
	for (int y = 0; y<RES; y++) {
		for (int x = 0; x<RES; x++) {
			getShadeValue(x, y, buffer);
			updateHighestValue(x, y, buffer);
		}
	}
	return buffer;
}

void RayTracer::getShadeValue(int x, int y, Buffer<Vector3> &buffer) {
	Ray r = generator.getRayFromPixelLocation(x, y);
	Hitpoint hp = scene.intersectWithScene(r);
	buffer.at(x, RES - y - 1) = shader.shade(r, hp, 1.0);
}

void RayTracer::updateHighestValue(int x, int y, Buffer<Vector3> buffer) {
	for (int i = 0; i < 3; i++) {
		if (buffer.at(x, RES - 1 - y)[i] > highestColorValue) {
			highestColorValue = buffer.at(x, RES - y - 1)[i];
		}
	}
}

Buffer<Color> RayTracer::convertVec3sToRGBColors(Buffer<Vector3> buffer) {
	Buffer<Color> cbuffer = Buffer<Color>(RES, RES);
	for (int y = 0; y < RES; y++) {
		for (int x = 0; x < RES; x++) {
			cbuffer.at(x, RES - y - 1) = Color(
				buffer.at(x, RES - y - 1)[0] / highestColorValue * 255,
				buffer.at(x, RES - y - 1)[1] / highestColorValue * 255,
				buffer.at(x, RES - y - 1)[2] / highestColorValue * 255);
		}
	}
	return cbuffer;
}
#endif