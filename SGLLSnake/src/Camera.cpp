#include "Camera.h"

#include <SGLL/DeltaTime.h>
#include <SGLL/Input/Input.h>

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(const glm::vec3& position, float fov)
	: mPosition(position), mWorldUp(0.0f, 1.0f, 0.0f), mYaw(-90.0f), mPitch(0.0f),
		mFov(fov), mCameraFront(glm::vec3(0.0f, 0.0f, -1.0f))
{
	updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const
{
	return glm::lookAt(mPosition, mPosition + mCameraFront, mCameraUp);
}

void Camera::updateInput()
{

	float speed = mSpeed * SGLL::DeltaTime::get();

	if (SGLL::Keyboard::isKeyDown(SGLL::Key::W))
		mPosition += mCameraFront * speed;

	if (SGLL::Keyboard::isKeyDown(SGLL::Key::S))
		mPosition -= mCameraFront * speed;

	if (SGLL::Keyboard::isKeyDown(SGLL::Key::D))
		mPosition += mCameraRight * speed;

	if (SGLL::Keyboard::isKeyDown(SGLL::Key::A))
		mPosition -= mCameraRight * speed;


	if (SGLL::Keyboard::isKeyDown(SGLL::Key::Space))
		mPosition += mCameraUp * speed;

	if (SGLL::Keyboard::isKeyDown(SGLL::Key::LeftShift))
		mPosition -= mCameraUp * speed;

	updateCameraVectors();
}

void Camera::updateDirection()
{
	mYaw += SGLL::Mouse::getXDeltaPos() * Sensitivity;
	mPitch -= SGLL::Mouse::getYDeltaPos() * Sensitivity;

	if (mPitch > 89.0f)
	{
		mPitch = 89.0f;
	} 
	else if (mPitch < -89.0f)
	{
		mPitch = -89.0f;
	}

	updateCameraVectors();
}

void Camera::updateCameraVectors()
{
	glm::vec3 dir;
	dir.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
	dir.y = sin(glm::radians(mPitch));
	dir.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPitch));
	mCameraFront = glm::normalize(dir);

	mCameraRight = glm::normalize(glm::cross(mCameraFront, mWorldUp));
	mCameraUp = glm::normalize(glm::cross(mCameraRight, mCameraFront));
}

void Camera::update()
{
	updateInput();
	updateDirection();
}
