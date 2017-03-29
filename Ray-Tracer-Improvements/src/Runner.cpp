#include "Runner.h"

int main(int argc, char ** argv) {

	checkParams(argc, argv);

	RayTracer rt = RayTracer(argv[1]);

	Buffer<Vector3> buffer = rt.getAllShadeValues();
	Buffer<Color> cbuffer = rt.convertVec3sToRGBColors(buffer);

	simplePNG_write(argv[2], cbuffer.getWidth(), cbuffer.getHeight(), (unsigned char*)&cbuffer.at(0, 0));

	return 0;
}

void checkParams(int argc, char ** argv) {
	if (argc < 3)
	{
		printf("Usage %s input.obj output.png\n", argv[0]);
		exit(0);
	}
}

