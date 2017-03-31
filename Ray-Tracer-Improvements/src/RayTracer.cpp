#ifndef RAY_TRACER_CPP
#define	RAY_TRACER_CPP

#include "RayTracer.h"

RayTracer::RayTracer() {

}

RayTracer::RayTracer(char* fileIn, int resx, int resy, float fieldOfView) {
	objLoader objData = objLoader();
	objData.load(fileIn);
	this->scene = Scene(objData, fieldOfView);
	this->shader = Shader(scene);
	this->generator = RayGenerator(scene.getCamera(), resx, resy);
	this->highestColorValue = -1;
	this->resx = resx;
	this->resy = resy;
}

Buffer<Vector3> RayTracer::getAllShadeValues() {
	Buffer<Vector3> buffer = Buffer<Vector3>(this->resx, this->resy);
	for (int y = 0; y<this->resy; y++) {
		for (int x = 0; x<this->resx; x++) {
			getShadeValue(x, y, buffer);
			updateHighestValue(x, y, buffer);
		}
	}
	return buffer;
}

void RayTracer::getShadeValue(int x, int y, Buffer<Vector3> &buffer) {
	Ray r = generator.getRayFromPixelLocation(x, y);
	Hitpoint hp = scene.intersectWithScene(r);
	buffer.at(x, this->resy - y - 1) = shader.shade(r, hp, 1.0);
}

void RayTracer::updateHighestValue(int x, int y, Buffer<Vector3> buffer) {
	for (int i = 0; i < 3; i++) {
		if (buffer.at(x, this->resy - 1 - y)[i] > highestColorValue) {
			highestColorValue = buffer.at(x, this->resy - y - 1)[i];
		}
	}
}

Buffer<Color> RayTracer::convertVec3sToRGBColors(Buffer<Vector3> buffer) {
	Buffer<Color> cbuffer = Buffer<Color>(this->resx, this->resy);
	for (int y = 0; y < this->resy; y++) {
		for (int x = 0; x < this->resx; x++) {
			cbuffer.at(x, this->resy - y - 1) = Color(
				buffer.at(x, this->resy - y - 1)[0] / highestColorValue * 255,
				buffer.at(x, this->resy - y - 1)[1] / highestColorValue * 255,
				buffer.at(x, this->resy - y - 1)[2] / highestColorValue * 255);
		}
	}
	return cbuffer;
}
#endif