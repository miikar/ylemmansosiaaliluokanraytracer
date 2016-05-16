#include "Model.hpp"
using namespace std;


Model::Model(std::string path)
{
	OBJparse(path);
}

void Model::OBJparse(string path) {
	FILE *obj_file;
	char *token;
	char *line;
	errno_t erno;

	erno = fopen_s(&obj_file, path.c_str(), "r");
	if (erno != 0)
		fprintf(stderr, "erno %d apuva!\n", erno);

	while (1) {
		int ret = fscanf_s(obj_file, "%s", token);
		if (ret == EOF)
			break;

		if ( strcmp(token, "v") == 0) {
			glm::vec3 vertex;
			fscanf_s(obj_file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			vertices.push_back(vertex);
		} else if ( strcmp(token, "f") == 0) {
			// vertex index/texture coordinate/normal
			// Currently scans only indexes
			unsigned int vertexIndex[3];
			fscanf_s(obj_file, "%d %d %d", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]);
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
		}
	}

	fclose(obj_file);
}