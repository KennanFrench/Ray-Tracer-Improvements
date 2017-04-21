#ifndef MATERIAL_H
#define MATERIAL_H

#include "GenVector.h"

class Material {

public:

	Material() {

	}

	Material(Vector3 diffuseFactor, Vector3 ambientFactor, Vector3 specularFactor, float shininess, float reflectionFactor) {
		this->diffuseFactor = diffuseFactor;
		this->ambientFactor = ambientFactor;
		this->specularFactor = specularFactor;
		this->shininess = shininess;
		this->reflectionFactor = reflectionFactor;
	}

	Vector3 getDiffuseFactor() {
		return this->diffuseFactor;
	}

	Vector3 getAmbientFactor() {
		return this->ambientFactor;
	}

	Vector3 getSpecularFactor() {
		return this->specularFactor;
	}

	float getShininess() {
		return this->shininess;
	}

	float getReflectionFactor() {
		return this->reflectionFactor;
	}

private:

	Vector3 diffuseFactor;
	Vector3 ambientFactor;
	Vector3 specularFactor;
	float shininess;
	float reflectionFactor;
};

#endif