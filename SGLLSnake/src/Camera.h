#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
	Camera(const glm::vec3& position, float fov = 45.0f);

	
	void update();

	inline const glm::vec3& getPosition() const
	{
		return mPosition;
	}

	inline const glm::vec3& getFront() const
	{
		return mCameraFront;
	}

	inline const glm::vec3& getCameraUp() const
	{
		return mCameraUp;
	}

	inline const glm::vec3& getWorldUp() const
	{
		return mWorldUp;
	}

	inline const glm::vec3& getCameraRight() const
	{
		return mCameraRight;
	}

	glm::mat4 getViewMatrix() const;


	float Sensitivity = 0.1f;
private:
	void updateInput();
	void updateDirection();


	void updateCameraVectors();

	glm::vec3 mPosition;
	glm::vec3 mCameraFront;
	glm::vec3 mCameraRight;
	glm::vec3 mCameraUp;
	glm::vec3 mWorldUp;

	float mFov = 45.0f;

	float mSpeed = 5.0f;

	float mYaw, mPitch;

};
