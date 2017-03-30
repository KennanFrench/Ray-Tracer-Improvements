#ifndef RAYGENERATOR_H
#define RAYGENERATOR_H

#include "Ray.h"
#include "Camera.h"

class RayGenerator {

public:

	RayGenerator() {
		this->camera = Camera();
		this->resx = -1;
		this->resy = -1;
	}

	RayGenerator(Camera &camera, int resx, int resy) {
		this->camera = camera;
		this->resx = resx;
		this->resy = resy;
	}

	Ray getRayFromPixelLocation(int x, int y) {
		float midToLeft = -((float) resx) / 2;
		float midToRight = ((float) resx) / 2;
		float midToBottom = -((float) resy) / 2;
		float midToTop = ((float) resy) / 2;

		float u = midToLeft + (midToRight - midToLeft) * (x + 0.5) / resx;
		float v = midToBottom + (midToTop - midToBottom) * (y + 0.5) / resy;

		float distance = (1 / tan(camera.getFOV() / 2)) * (resx / 2);
		
		Vector3 pixelLocation = camera.getPos() + u * camera.getU() + v * camera.getV() - distance * camera.getW();

		Vector3 rayDir = (pixelLocation - camera.getPos()).normalize();

		return Ray(camera.getPos(), rayDir);
	}

private:

	Camera camera;
	int resx;
	int resy;

};
#endif