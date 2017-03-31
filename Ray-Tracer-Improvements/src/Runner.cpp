#include "Runner.h"
#include <string>

int main(int argc, char ** argv) {

	Params params = loadFromParams(argc, argv);

	RayTracer rt = RayTracer(params.getInFile(), params.getResX(), params.getResY(), params.getFieldOfView());

	Buffer<Vector3> buffer = rt.getAllShadeValues();
	Buffer<Color> cbuffer = rt.convertVec3sToRGBColors(buffer);

	simplePNG_write(params.getOutFile(), cbuffer.getWidth(), cbuffer.getHeight(), (unsigned char*)&cbuffer.at(0, 0));

	return 0;
}

Params loadFromParams(int argc, char ** argv) {

	if (argc == 3) {
		return Params(argv[1], argv[2], Resolution(), -1);
	}

	if (argc == 4) {
		return Params(argv[1], argv[2], Resolution(), stof(argv[3]));
	}

	if (argc == 5) {
		return Params(argv[1], argv[2], Resolution(stoi(argv[3]), stoi(argv[4])), -1);
	}

	else {
		printf("Usage %s input.obj output.png [resx resy] [fov]\n", argv[0]);
		exit(1);
	}

}

