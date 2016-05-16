#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <glm\glm.hpp>
#include "Primitives.hpp"

class Model
{
public:
	Model(std::string path);
	const std::vector<Triangle*> &getTriangles(void) const;
private:
	void OBJparse(std::string path);
	std::vector<glm::vec3> vertices;
	std::vector<unsigned int> vertexIndices;
};

#endif
