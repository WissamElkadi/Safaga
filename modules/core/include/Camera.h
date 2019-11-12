#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// Default camera values
const float YAW_DEFAULT = -90.0f;
const float PITCH_DEFAULT = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float ZOOM_DEFAULT = 45.0f;


namespace Safaga
{
	namespace Core
	{
		class Camera
		{
		public:
			// Constructor with vectors
			Camera(glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f), float _yaw = YAW_DEFAULT, float _pitch = PITCH_DEFAULT);

			// Constructor with scalar values
			Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float mYaw, float mPitch);

			// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
			glm::mat4 getViewMatrix();

			glm::mat4 getProjectionMatrix(int screenWidth, int screeHeight, float near = 0.1f, float far = 100.0f);

			// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
			void ProcessKeyboard(Camera_Movement direction, float deltaTime);

			// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
			void ProcessMouseMovement(float xoffset, float yoffset, bool constrainmPitch = true);

			// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
			void ProcessMouseScroll(float yoffset);

		private:
			// Camera Attributes
			glm::vec3 mPosition;
			glm::vec3 mFront;
			glm::vec3 mUp;
			glm::vec3 mRight;
			glm::vec3 mWorldUp;

			// Euler Angles
			float mYaw;
			float mPitch;

			// Camera options
			float mMovementSpeed;
			float mMouseSensitivity;
			float mZoom;

			// Calculates the front vector from the Camera's (updated) Euler Angles
			void updateCameraVectors();
		};
	}
}

