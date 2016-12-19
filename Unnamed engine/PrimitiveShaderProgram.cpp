#include "PrimitiveShaderProgram.h"


PrimitiveShaderProgram::PrimitiveShaderProgram() : ShaderProgram(vertexfileLocation(), fragmentfileLocation())
{
	bindAttributes();
	getAllUniformLocations();
}

void PrimitiveShaderProgram::getAllUniformLocations() {

	location_transform = getUniformLocation("transform");
	location_view = getUniformLocation("view");
	location_projection = getUniformLocation("projection");
}

void PrimitiveShaderProgram::bindAttributes() {
	bindAttribute(0, "position");
}

std::string PrimitiveShaderProgram::vertexfileLocation() {
	return "./res/primitiveShader.vs";
}

std::string PrimitiveShaderProgram::fragmentfileLocation() {
	return "./res/primitiveShader.fs";
}

void PrimitiveShaderProgram::loadProjection(glm::mat4& projection) {
	loadMatrix(location_projection, projection);
}

void PrimitiveShaderProgram::loadTransform(glm::mat4 &matrix) {
	loadMatrix(location_transform, matrix);
}

void PrimitiveShaderProgram::loadView(Camera &cam) {
	glm::mat4 view = MyMath::createViewMatrix(cam);
	loadMatrix(location_projection, view);
}

void PrimitiveShaderProgram::loadTextures()
{
	loadInt(location_textureSampler, 0);
}

PrimitiveShaderProgram::~PrimitiveShaderProgram()
{
	ShaderProgram::~ShaderProgram();
}
