#pragma once
#include "ShaderProgram.h"
#include "Math.cpp"
#include "Camera.h"

class PrimitiveShaderProgram : public ShaderProgram
{
public:
	PrimitiveShaderProgram();
	~PrimitiveShaderProgram();
	void loadTransform(glm::mat4&);
	void loadTextures();
	void loadView(Camera &cam);
	void loadProjection(glm::mat4& projection);
private:
	void getAllUniformLocations() override;
	void bindAttributes() override;
	std::string vertexfileLocation();
	std::string fragmentfileLocation();
	int location_transform;
	int location_projection;
	int location_view;
	int location_textureSampler;

};
