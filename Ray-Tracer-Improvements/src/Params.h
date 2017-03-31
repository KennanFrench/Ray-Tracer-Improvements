#ifndef PARAMS_H
#define PARAMS_H

#include "Resolution.h"

#define _USE_MATH_DEFINES
#include <Math.h>

#define DEFAULT_RESOLUTION Resolution(150, 100)
#define DEFAULT_FIELD_OF_VIEW M_PI / 2.0f

class Params {

public:

	Params() {

	}

	Params(char* inFile, char* outFile, Resolution res, float fieldOfView) {
		if (res.getX() == -1) {
			this->res = DEFAULT_RESOLUTION;
		} else {
			this->res = res;
		}

		if (fieldOfView < 0.0f) {
			this->fieldOfView = DEFAULT_FIELD_OF_VIEW;
		} else {
			this->fieldOfView = fieldOfView;
		}

		this->inFile = inFile;
		this->outFile = outFile;
	}

	int getResX() {
		return this->res.getX();
	}

	int getResY() {
		return this->res.getY();
	}

	float getFieldOfView() {
		return this->fieldOfView;
	}

	char* getInFile() {
		return this->inFile;
	}

	char* getOutFile() {
		return this->outFile;
	}

private:

	Resolution res;
	float fieldOfView;
	char* inFile;
	char* outFile;

};
#endif