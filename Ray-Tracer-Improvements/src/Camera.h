#ifndef CAMERA_H
#define CAMERA_H

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef DEFAULT_FIELD_OF_VIEW
#define DEFAULT_FIELD_OF_VIEW M_PI / 2
#endif

class Camera {

public:

	Camera() {
		this->u = NULL;
		this->v = NULL;
		this->w = NULL;
		this->pos = NULL;
		this->FOV = DEFAULT_FIELD_OF_VIEW;
	}

	Camera(Vector3 pos, Vector3 at, Vector3 up, float fieldOfView) {
		this->pos = pos;
		this->w = Vector3(0.0, 0.0, 0.0) - at;
		this->u = up.cross(w);
		this->v = w.cross(u);
		this->FOV = fieldOfView;
	}

	Vector3 getPos() {
		return pos;
	}
	
	Vector3 getU() {
		return u;
	}

	Vector3 getV() {
		return v;
	}

	Vector3 getW() {
		return w;
	}

	float getFOV() {
		return this->FOV;
	}

private:

	Vector3 u;
	Vector3 v;
	Vector3 w;
	Vector3 pos;
	float FOV;

};

#endif