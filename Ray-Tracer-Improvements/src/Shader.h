#ifndef SHADER_H
#define SHADER_H

#include "Scene.h"

class Shader {

public:

	Shader() {

	}

	Shader(Scene s) {
		this->s = s;
	}

	Vector3 shade(Ray r, Hitpoint hp, float energy) {
		if (hp.getT() < 0 || hp.getObj() < 0) {
			return Vector3(0, 0, 0);
		}

		Vector3 amb = Vector3(0, 0, 0);
		Vector3 diff = Vector3(0, 0, 0);
		Vector3 spec = Vector3(0, 0, 0);

		for (int i = 0; i < s.getLights().size(); i++) {

			// Ambient light
			amb += (s.getPrimatives()[hp.getObj()]->getMat().getAmbientFactor() * s.getLights()[i]->getAmbInt());

			Vector3 LightToObjVec = (r.getPointAtTime(hp.getT()) - s.getLights()[i]->getPos());
			Vector3 sVec = -LightToObjVec;
			float LightToObjDist = LightToObjVec.length();
			Ray LightToObj = Ray(s.getLights()[i]->getPos(), LightToObjVec.normalize());
			Hitpoint lightHP = s.intersectWithScene(LightToObj);
			if (LightToObjDist - lightHP.getT() < rTEpsilon) { // if there's an unobstructed path from the light to the object				
				
				Vector3 uS = (-LightToObjVec).normalize();
				Vector3 uN = lightHP.getNorm().normalize();
				Vector3 uV = -(r.getDirection()).normalize();
				Vector3 uR = (-sVec + 2 * (sVec.dot(uN)) * uN).normalize();

				diff += calculateDiffuse(s.getPrimatives()[hp.getObj()]->getMat(), *s.getLights()[i], LightToObjVec, lightHP, uS, uN);
				spec += calculateSpecular(s.getPrimatives()[hp.getObj()]->getMat(), *s.getLights()[i], uV, uR);

			}

		}

		Vector3 surfaceComp = amb + diff + spec;
		if (energy < rTEpsilon) { // No more reflections
			return surfaceComp;
		}

		float refl = s.getPrimatives()[hp.getObj()]->getMat().getReflectionFactor();
		Vector3 newVec = r.getDirection() - 2 * (r.getDirection().dot(hp.getNorm().normalize())) * hp.getNorm().normalize();
		Ray newRay = Ray(r.getPointAtTime(hp.getT()) + newVec/newVec.length() * rTEpsilon, newVec.normalize());
		Hitpoint newHP = s.intersectWithScene(newRay);
		Vector3 refComp = this->shade(newRay, newHP, energy * refl);

		return (1 - refl) * surfaceComp + refl * refComp;

	}

	Vector3 calculateSpecular(Material mat, Light light, Vector3 uV, Vector3 uR) {
		float ns = mat.getShininess();
		Vector3 rs = mat.getSpecularFactor();
		Vector3 is = light.getSpecInt();

		return (rs * is * pow(__max(uR.dot(uV), 0.0), ns));
	}

	Vector3 calculateDiffuse(Material mat, Light light, Vector3 LightToObjVec, Hitpoint lightHP, Vector3 uS, Vector3 uN) {
		Vector3 rd = mat.getDiffuseFactor();
		Vector3 id = light.getDifInt();
		return (rd * id * __max(uS.dot(uN), 0.0));
	}

private:

	Scene s;
	double rTEpsilon = 0.001;

};
#endif