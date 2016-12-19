#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "Camera.h"
#include "Settings.h"

class MyMath
{
public:
	static glm::mat4 createTransformationMatrix(glm::vec2 translation, glm::vec2 scale);
	static glm::mat4 createViewMatrix(Camera &camera);
	static glm::mat4 createTransformationmatrix(glm::vec3 translation, float rx, float ry, float rz, glm::vec3 scale);
	static float barryCentric(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec2 pos);
	static glm::mat4 createProjectionMatrix();
};


glm::mat4 MyMath::createViewMatrix(Camera &camera)
{
	glm::mat4 matrix;
	matrix = glm::rotate(matrix, camera.getPitch(), glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, camera.getYaw(), glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, camera.getRoll(), glm::vec3(0, 0, 1));
	glm::vec3 cameraPos = camera.getPosition();
	glm::vec3 negCameraPos = glm::vec3(-cameraPos.x, -cameraPos.y, -cameraPos.z);
	matrix = glm::translate(matrix, negCameraPos);
	return matrix;
}

glm::mat4 MyMath::createTransformationmatrix(glm::vec3 translation, float rx, float ry, float rz, glm::vec3 scale) {
	glm::mat4 matrix;
	matrix = glm::translate(matrix, translation);
	matrix = glm::rotate(matrix, rx, glm::vec3(1, 0, 0));
	matrix = glm::rotate(matrix, ry, glm::vec3(0, 1, 0));
	matrix = glm::rotate(matrix, rz, glm::vec3(0, 0, 1));
	matrix = glm::scale(matrix, scale);
	return matrix;
}

glm::mat4 MyMath::createTransformationMatrix(glm::vec2 translation, glm::vec2 scale) {
	glm::mat4 matrix;
	matrix = glm::translate(matrix, glm::vec3(translation.x, translation.y, 0.0));
	glm::scale(matrix, glm::vec3(scale.x, scale.y, 0.0f));
	return matrix;
}

float MyMath::barryCentric(glm::vec3 p1, glm::vec3 p2, glm::vec3 p3, glm::vec2 pos) {
	float det = (p2.z - p3.z) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.z - p3.z);
	float l1 = ((p2.z - p3.z) * (pos.x - p3.x) + (p3.x - p2.x) * (pos.y - p3.z)) / det;
	float l2 = ((p3.z - p1.z) * (pos.x - p3.x) + (p1.x - p3.x) * (pos.y - p3.z)) / det;
	float l3 = 1.0f - l1 - l2;
	return l1 * p1.y + l2 * p2.y + l3 * p3.y;
}

glm::mat4 MyMath::createProjectionMatrix()
{

	float aspectRatio = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	float y_scale = (float)((1.0f / tan((FOV / 2.0f) * 3.14159265 / 180.0)) * aspectRatio);
	float x_scale = y_scale / aspectRatio;
	float frustrum_length = FAR_PLANE - NEAR_PLANE;
	return glm::perspective(FOV, aspectRatio, NEAR_PLANE, FAR_PLANE);

}