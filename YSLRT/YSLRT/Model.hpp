#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <glm\glm.hpp>
#include "Primitives.hpp"

class Model
{
public:
	Model();
	void OBJparse(std::string);
private:
	std::vector<glm::vec3> vertices;
	vector<unsigned int> vertexIndices;
};

#endif
