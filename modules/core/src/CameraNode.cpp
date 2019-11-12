#include "CameraNode.h"

namespace Safaga
{
	namespace Core
	{
		CameraNode::CameraNode(MathUtils::vec3 _position, MathUtils::vec3 _up, float _yaw, float _pitch) :
			mPosition(_position), mWorldUp(_up), mYaw(_yaw), mPitch(_pitch)
		{
			updateCameraVectors();
		}

		CameraNode::CameraNode(float posX, float posY, float posZ, float upX, float upY, float upZ, float mYaw, float mPitch) :
			mPosition(MathUtils::vec3(posX, posY, posZ)), mWorldUp(MathUtils::vec3(upX, upY, upZ)), mYaw(mYaw), mPitch(mPitch)
		{
			updateCameraVectors();
		}

		MathUtils::mat4 CameraNode::getViewMatrix()
		{
			return MathUtils::mat4(1.0f); //MathUtils::lookAt(mPosition, mPosition + mFront, mUp);
		}

		MathUtils::mat4 CameraNode::getProjectionMatrix(int screenWidth, int screeHeight, float near, float far)
		{
			return MathUtils::mat4(1.0f); //MathUtils::perspective(MathUtils::radians(mZoom), (float)screenWidth / (float)screeHeight, near, far);
		}

		void CameraNode::accept(INodeVisitor& _nodeVisitor)
		{
			_nodeVisitor.visit(*this);
		}

		void CameraNode::updateCameraVectors()
		{
			//// Calculate the new mFront vector
			//MathUtils::vec3 front;
			//front.x = cos(MathUtils::radians(mYaw)) * cos(MathUtils::radians(mPitch));
			//front.y = sin(MathUtils::radians(mPitch));
			//front.z = sin(MathUtils::radians(mYaw)) * cos(MathUtils::radians(mPitch));
			//mFront = MathUtils::normalize(front);
			//// Also re-calculate the mRight and mUp vector
			//mRight = MathUtils::normalize(MathUtils::cross(mFront, mWorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
			//mUp = MathUtils::normalize(MathUtils::cross(mRight, mFront));
		}
	}
}
