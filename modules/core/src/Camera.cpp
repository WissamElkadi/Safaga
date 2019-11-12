#include "Camera.h"

namespace Safaga
{
	namespace Core
	{
		// Constructor with vectors
		Camera::Camera(glm::vec3 _position, glm::vec3 _up, float _yaw, float _pitch) :
			mFront(glm::vec3(0.0f, 0.0f, -1.0f)), mMovementSpeed(SPEED), mMouseSensitivity(SENSITIVITY), mZoom(ZOOM_DEFAULT)
		{
			mPosition = _position;
			mWorldUp = _up;
			mYaw = _yaw;
			mPitch = _pitch;
			updateCameraVectors();
		}

		// Constructor with scalar values
		Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float mYaw, float mPitch) : mFront(glm::vec3(0.0f, 0.0f, -1.0f)), mMovementSpeed(SPEED), mMouseSensitivity(SENSITIVITY), mZoom(mZoom)
		{
			mPosition = glm::vec3(posX, posY, posZ);
			mWorldUp = glm::vec3(upX, upY, upZ);
			mYaw = mYaw;
			mPitch = mPitch;
			updateCameraVectors();
		}

		// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
		glm::mat4 Camera::getViewMatrix()
		{
			return glm::lookAt(mPosition, mPosition + mFront, mUp);
		}

		glm::mat4 Camera::getProjectionMatrix(int screenWidth, int screeHeight, float near, float far)
		{
			return glm::perspective(glm::radians(mZoom), (float)screenWidth / (float)screeHeight, near, far);
		}

		// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
		void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
		{
			float velocity = mMovementSpeed * deltaTime;
			if (direction == FORWARD)
				mPosition += mFront * velocity;
			if (direction == BACKWARD)
				mPosition -= mFront * velocity;
			if (direction == LEFT)
				mPosition -= mRight * velocity;
			if (direction == RIGHT)
				mPosition += mRight * velocity;
		}

		// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
		void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainmPitch)
		{
			xoffset *= mMouseSensitivity;
			yoffset *= mMouseSensitivity;

			mYaw += xoffset;
			mPitch += yoffset;

			// Make sure that when mPitch is out of bounds, screen doesn't get flipped
			if (constrainmPitch)
			{
				if (mPitch > 89.0f)
					mPitch = 89.0f;
				if (mPitch < -89.0f)
					mPitch = -89.0f;
			}

			// Update mFront, mRight and mUp Vectors using the updated Euler angles
			updateCameraVectors();
		}

		// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
		void Camera::ProcessMouseScroll(float yoffset)
		{
			if (mZoom >= 1.0f && mZoom <= 45.0f)
				mZoom -= yoffset;
			if (mZoom <= 1.0f)
				mZoom = 1.0f;
			if (mZoom >= 45.0f)
				mZoom = 45.0f;
		}


		// Calculates the front vector from the Camera's (updated) Euler Angles
		void Camera::updateCameraVectors()
		{
			// Calculate the new mFront vector
			glm::vec3 front;
			front.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
			front.y = sin(glm::radians(mPitch));
			front.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPitch));
			mFront = glm::normalize(front);
			// Also re-calculate the mRight and mUp vector
			mRight = glm::normalize(glm::cross(mFront, mWorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
			mUp = glm::normalize(glm::cross(mRight, mFront));
		}
	}
}
