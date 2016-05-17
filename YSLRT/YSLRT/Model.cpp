#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Model.hpp"
using namespace std;


Model::Model(std::string path)
{
	OBJparse(path);
}

void Model::OBJparse(std::string path) {

	ifstream obj_file(path);
	if (!obj_file) return;

	string line;
	while (getline(obj_file, line, '\n')) {
		std::istringstream ss(line);
		string token;
		ss >> token;

		if (token == "#") {
			continue;
		} else if (token == "v") {
			// Scan vertices
			glm::vec3 vertex;
			ss >> (float)vertex.x >> (float)vertex.y >> (float)vertex.z;
			vertices.push_back(vertex);
		} else if (token == "f") {
			// vertex index/texture coordinate/normal
			// Currently scans only vertex indices
			unsigned int vertexIndex[3];
			ss >> vertexIndex[0] >> vertexIndex[1] >> vertexIndex[2];
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
		}
	}
}