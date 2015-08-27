#include "Camera.h"
#include <glm\gtx\transform.hpp>
const float movement_speed=0.1f;
Camera::Camera(void) : viewDirection(0.0f,0.0f,-1.0f), UP(0.0f,1.0f,0.0f)
{
}
void Camera::moveForward()
{
	position += movement_speed * viewDirection;
}
void Camera::moveBackward()
{
	position += -movement_speed * viewDirection;
}
void Camera::strafeLeft()
{
	glm::vec3 strafeDirection= glm::cross(viewDirection,UP);
	position += -movement_speed * strafeDirection;
}
void Camera::strafeRight()
{
	glm::vec3 strafeDirection= glm::cross(viewDirection,UP);
	position += movement_speed * strafeDirection;
}
void Camera::moveUp()
{
	position += movement_speed * UP;
}
void Camera::moveDown()
{
	position += -movement_speed * UP;
}
void Camera::mouseUpdate(const glm::vec2& newMousePosition)
{
	glm::vec2 mouseDelta= oldMousePosition-newMousePosition;
	if(glm::length(mouseDelta) >50.0f)
	{
		oldMousePosition= newMousePosition;
		return;
	}
    viewDirection = glm::mat3(glm::rotate(mouseDelta.x*0.5f,UP)) * viewDirection;
	glm::vec3 toRotateAround= glm::cross(viewDirection,UP);
	viewDirection=glm::mat3(glm::rotate(mouseDelta.y*0.5f,toRotateAround)) * viewDirection;
	oldMousePosition= newMousePosition;
}
glm::mat4 Camera::getWorldToViewMatrix() const
{
	return glm::lookAt(position,position+viewDirection,UP);
}



