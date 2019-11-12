#pragma once

#include "Node.h"
#include "MathUtils.h"

namespace Safaga
{
	namespace Core
	{
		// Default camera values
		const float YAW_DEFAULT = -90.0f;
		const float PITCH_DEFAULT = 0.0f;
		const float ZOOM_DEFAULT = 45.0f;

		class CameraNode : public Node
		{
		public:
			CameraNode(MathUtils::vec3 _position = MathUtils::vec3(0.0f, 0.0f, 0.0f), MathUtils::vec3 _up = MathUtils::vec3(0.0f, 1.0f, 0.0f), float _yaw = YAW_DEFAULT, float _pitch = PITCH_DEFAULT);
			CameraNode(float posX, float posY, float posZ, float upX, float upY, float upZ, float mYaw, float mPitch);

			MathUtils::mat4 getViewMatrix();
			MathUtils::mat4 getProjectionMatrix(int screenWidth, int screeHeight, float near = 0.1f, float far = 100.0f);

			void accept(INodeVisitor& _nodeVisitor) override;
			
		private:
			// Camera Attributes
			MathUtils::vec3 mPosition;
			MathUtils::vec3 mFront;
			MathUtils::vec3 mUp;
			MathUtils::vec3 mRight;
			MathUtils::vec3 mWorldUp;

			// Euler Angles
			float mYaw;
			float mPitch;

			float mZoom;

			void updateCameraVectors();
		};
	}
}
